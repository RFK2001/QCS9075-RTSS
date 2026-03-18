// SPDX-License-Identifier: GPL-2.0-only
// Copyright (c) 2024-2025 Qualcomm Innovation Center, Inc. All rights reserved.

#include <dt-bindings/sound/qcom,q6afe.h>
#include <linux/input.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/of_device.h>
#include <sound/core.h>
#include <sound/soc.h>
#include <sound/soc-dapm.h>
#include <sound/pcm.h>
#include <linux/soundwire/sdw.h>
#include <sound/jack.h>
#include <sound/pcm_params.h>
#include "lpass.h"
#include "qdsp6/q6afe.h"
#include "qdsp6/q6prm.h"
#include "common.h"
#include "sdw.h"

#define WCN_CDC_SLIM_RX_CH_MAX	2
#define WCN_CDC_SLIM_TX_CH_MAX	2
#define NAME_SIZE	32

extern int es8326_set_jack(struct snd_soc_component *component,struct snd_soc_jack *jack);

#define DRIVER_NAME		"qcs9100"

struct qcs9100_snd_data {
	bool stream_prepared[AFE_PORT_MAX];
	struct snd_soc_card *card;
	struct sdw_stream_runtime *sruntime[AFE_PORT_MAX];
	struct snd_soc_jack jack;
	bool jack_setup;
	struct clk *macro;
	struct clk *dcodec;
        struct clk *mclk;
	struct snd_soc_jack hdmi_jack[8];
        struct snd_soc_jack headset_jack;
};

static int qcs9075_enable_mclk(struct device *dev)
{
    struct clk *mclk;
    int ret;

    mclk = devm_clk_get_optional(dev, "mclk");
    if (IS_ERR(mclk)) {
        ret = PTR_ERR(mclk);
        dev_err(dev, "Failed to get 'mclk' clock: %d\n", ret);
        return ret;
    }

    if (mclk) {
        dev_err(dev, "Enabling mclk (clk=%p)\n", mclk);
        ret = clk_prepare_enable(mclk);
        if (ret) {
            dev_err(dev, "Unable to prepare/enable mclk: %d\n", ret);
            return ret;
        }
    }

    struct qcs9100_snd_data *priv = dev_get_drvdata(dev);
    if (priv)
        priv->mclk = mclk;            /* 让后面的代码能够访问它 */

    dev_err(dev, "MCLK %p successfully prepared and enabled\n", mclk);
    return 0;
}

static int qcm9075_late_probe(struct snd_soc_card *card)
{
    struct qcs9100_snd_data *data = snd_soc_card_get_drvdata(card);
    struct snd_soc_component *component;
    const char *str_cmp = "es8326";
    int ret;

    pr_err("qcom9075 late probe enter\n");
    for_each_card_components(card, component) {
        if (!component->name) {
            dev_err(card->dev, "Component name is NULL\n");
            continue;
        }
        if (strncmp(component->name, str_cmp, strlen(str_cmp)) == 0) {
            ret = snd_soc_card_jack_new(card, "Headset Jack",
                                        SND_JACK_HEADSET | SND_JACK_BTN_0 |
                                        SND_JACK_BTN_1 | SND_JACK_BTN_2,
                                        &data->headset_jack);
            if (ret) {
                dev_err(card->dev, "Failed to create headset jack\n");
                return ret;
            }

            ret = snd_jack_set_key(data->headset_jack.jack, SND_JACK_BTN_0, KEY_PLAYPAUSE);
            if (ret) {
                dev_err(card->dev, "Failed to set BTN_0 key\n");
                return ret;
            }

            ret = snd_jack_set_key(data->headset_jack.jack, SND_JACK_BTN_1, KEY_VOLUMEUP);
            if (ret) {
                dev_err(card->dev, "Failed to set BTN_1 key\n");
                return ret;
            }

            ret = snd_jack_set_key(data->headset_jack.jack, SND_JACK_BTN_2, KEY_VOLUMEDOWN);
            if (ret) {
                dev_err(card->dev, "Failed to set BTN_2 key\n");
                return ret;
            }

            ret = es8326_set_jack(component, &data->headset_jack);
            if (ret) {
                dev_err(component->dev, "Failed to set ES8326 jack\n");
                return ret;
            }

            dev_info(card->dev, "ES8326 headset jack configured\n");
            break;
        }
    }

    return 0;
}

static int qcs9100_snd_init(struct snd_soc_pcm_runtime *rtd)
{
	struct qcs9100_snd_data *data = snd_soc_card_get_drvdata(rtd->card);
	struct snd_soc_dai *cpu_dai = snd_soc_rtd_to_cpu(rtd, 0);
	int ret = 0;
	char jack_name[NAME_SIZE];
	struct snd_soc_jack *hdmi_jack  = NULL;
	int hdmi_pcm_id = 0;
	struct snd_soc_dai *codec_dai;
	int rval, i;

	switch (cpu_dai->id) {
	case PRIMARY_MI2S_RX:
	case PRIMARY_MI2S_TX:
	case PRIMARY_TDM_RX_0:
	case PRIMARY_TDM_TX_0:
		break;
	case DISPLAY_PORT_RX_0:
		hdmi_pcm_id = 0;
		hdmi_jack = &data->hdmi_jack[0];
		break;
	case DISPLAY_PORT_RX_1:
		hdmi_pcm_id = 1;
		hdmi_jack = &data->hdmi_jack[1];
		break;

	default:
		break;
	}
	if (hdmi_jack) {
		snprintf(jack_name, sizeof(jack_name), "HDMI/DP%d Jack", hdmi_pcm_id);
		rval = snd_soc_card_jack_new(rtd->card, jack_name, SND_JACK_AVOUT, hdmi_jack);

		if (rval)
			return rval;

		for_each_rtd_codec_dais(rtd, i, codec_dai) {
			rval = snd_soc_component_set_jack(codec_dai->component, hdmi_jack, NULL);
			if (rval != 0 && rval != -EOPNOTSUPP) {
				dev_warn(rtd->card->dev, "Failed to set HDMI jack: %d\n", rval);
				return rval;
			}
		}
		return qcom_snd_wcd_jack_setup(rtd, &data->jack, &data->jack_setup);
	}

	return ret;
}

static int qcs9100_be_hw_params_fixup(struct snd_soc_pcm_runtime *rtd,
				      struct snd_pcm_hw_params *params)
{
	struct snd_interval *rate = hw_param_interval(params,
					SNDRV_PCM_HW_PARAM_RATE);
	struct snd_interval *channels = hw_param_interval(params,
					SNDRV_PCM_HW_PARAM_CHANNELS);

	rate->min = 48000;
	rate->max = 48000;
	channels->min = 2;
	channels->max = 2;

	return 0;
}

static int qcs9100_snd_hw_params(struct snd_pcm_substream *substream,
				 struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_dai *cpu_dai = snd_soc_rtd_to_cpu(rtd, 0);
	struct qcs9100_snd_data *pdata = snd_soc_card_get_drvdata(rtd->card);
	int ret = 0;
        pr_err("enter into snd_hw_params\n");
	switch (cpu_dai->id) {
	case TERTIARY_MI2S_RX:
	case TERTIARY_MI2S_TX:
	case TERTIARY_TDM_RX_0:
	case TERTIARY_TDM_TX_0:
	case PRIMARY_SDR_MI2S_RX ... QUINARY_SDR_TDM_TX_0:
		/* clock setting is done for qcs9100 target to support high
		 * speed i2s interface
		 */
            dev_err(pdata->card->dev, "fzy case id: %ld\n", cpu_dai->id);
		if (pdata->macro) {
                        dev_err(pdata->card->dev, "fzy clk 1111\n");
			ret = clk_prepare_enable(pdata->macro);
			if (ret) {
				dev_err(pdata->card->dev, "unable to prepare macro\n");
				return ret;
			}
		}
		if (pdata->dcodec) {
                        dev_err(pdata->card->dev, "fzy clk 2222\n");
			ret = clk_prepare_enable(pdata->dcodec);
			if (ret) {
				dev_err(pdata->card->dev, "unable to prepare decode\n");
				return ret;
			}
		}
                if (pdata->mclk) {
                        dev_err(pdata->card->dev, "fzy clk 3333\n");
                        ret = clk_prepare_enable(pdata->mclk);
                        if (ret) {
                                dev_err(pdata->card->dev, "unable to prepare mclk\n");
                                return ret;
                        }
                }
		break;
	default:
		break;
	}

	return qcom_snd_sdw_hw_params(substream, params, &pdata->sruntime[cpu_dai->id]);
}

static int qcs9100_snd_prepare(struct snd_pcm_substream *substream)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_dai *cpu_dai = snd_soc_rtd_to_cpu(rtd, 0);
	struct qcs9100_snd_data *data = snd_soc_card_get_drvdata(rtd->card);
	struct sdw_stream_runtime *sruntime = data->sruntime[cpu_dai->id];

	return qcom_snd_sdw_prepare(substream, sruntime,
				    &data->stream_prepared[cpu_dai->id]);
}

static int qcs9100_snd_hw_free(struct snd_pcm_substream *substream)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct qcs9100_snd_data *data = snd_soc_card_get_drvdata(rtd->card);
	struct snd_soc_dai *cpu_dai = snd_soc_rtd_to_cpu(rtd, 0);
	struct sdw_stream_runtime *sruntime = data->sruntime[cpu_dai->id];

	switch (cpu_dai->id) {
	case TERTIARY_MI2S_RX:
	case TERTIARY_MI2S_TX:
	case TERTIARY_TDM_RX_0:
	case TERTIARY_TDM_TX_0:
	case PRIMARY_SDR_MI2S_RX ... QUINARY_SDR_TDM_TX_0:
		/* clock disable is done for qcs9100 target to support high
		 * speed i2s interface
		 */
		if (data->dcodec)
			clk_disable_unprepare(data->dcodec);

		if (data->macro)
			clk_disable_unprepare(data->macro);

                if (data->mclk)
                        clk_disable_unprepare(data->mclk);

		break;
	default:
		break;
	}

	return qcom_snd_sdw_hw_free(substream, sruntime,
				    &data->stream_prepared[cpu_dai->id]);
}

static int qcs9100_snd_startup(struct snd_pcm_substream *substream)
{
	struct snd_soc_pcm_runtime *rtd = snd_soc_substream_to_rtd(substream);
	struct snd_soc_dai *cpu_dai = snd_soc_rtd_to_cpu(rtd, 0);
	unsigned int fmt = SND_SOC_DAIFMT_BP_FP;

	switch (cpu_dai->id) {
	case PRIMARY_MI2S_RX ... QUATERNARY_MI2S_TX:
	case PRIMARY_SDR_MI2S_RX ... QUINARY_SDR_MI2S_TX:
		snd_soc_dai_set_fmt(cpu_dai, fmt);
		break;
	default:
		break;
	}

	return 0;
}

static const struct snd_soc_dapm_widget iq8_8275_evk_dapm_widgets[] = {
	SND_SOC_DAPM_PINCTRL("MI2S_OUT_PINCTRL", "mi2s_aud_out_active", "mi2s_aud_out_sleep"),
};

static const struct snd_soc_dapm_route iq8_8275_evk_dapm_routes[] = {
	{"Speaker", NULL, "MI2S_OUT_PINCTRL"},
	{"DMic", NULL, "MI2S_OUT_PINCTRL"},
};

static const struct snd_soc_dapm_widget qcs8300_dapm_widgets[] = {
	SND_SOC_DAPM_PINCTRL("STUB_AIF1_PINCTRL", "stub_aif1_active", "stub_aif1_sleep"),
	SND_SOC_DAPM_PINCTRL("STUB_AIF2_PINCTRL", "stub_aif2_active", "stub_aif2_sleep"),
	SND_SOC_DAPM_PINCTRL("STUB_AIF3_PINCTRL", "stub_aif3_active", "stub_aif3_sleep"),
	SND_SOC_DAPM_PINCTRL("STUB_AIF4_PINCTRL", "stub_aif4_active", "stub_aif4_sleep"),
};

static const struct snd_soc_dapm_route qcs8300_dapm_routes[] = {
	{"STUB_AIF0_RX", NULL, "STUB_AIF1_PINCTRL"},
	{"STUB_AIF0_TX", NULL, "STUB_AIF1_PINCTRL"},
	{"STUB_AIF1_RX", NULL, "STUB_AIF2_PINCTRL"},
	{"STUB_AIF1_TX", NULL, "STUB_AIF2_PINCTRL"},
	{"STUB_AIF2_RX", NULL, "STUB_AIF3_PINCTRL"},
	{"STUB_AIF2_TX", NULL, "STUB_AIF3_PINCTRL"},
	{"STUB_AIF3_RX", NULL, "STUB_AIF4_PINCTRL"},
	{"STUB_AIF3_TX", NULL, "STUB_AIF4_PINCTRL"},
};

static const struct snd_soc_dapm_widget qcs9100_dapm_widgets[] = {
	SND_SOC_DAPM_PINCTRL("STUB_AIF0_PINCTRL", "stub_aif0_active", "stub_aif0_sleep"),
	SND_SOC_DAPM_PINCTRL("STUB_AIF1_PINCTRL", "stub_aif1_active", "stub_aif1_sleep"),
	SND_SOC_DAPM_PINCTRL("STUB_AIF2_PINCTRL", "stub_aif2_active", "stub_aif2_sleep"),
	SND_SOC_DAPM_PINCTRL("STUB_AIF3_PINCTRL", "stub_aif3_active", "stub_aif3_sleep"),
};

static const struct snd_soc_dapm_route qcs9100_dapm_routes[] = {
	{"STUB_AIF0_RX", NULL, "STUB_AIF0_PINCTRL"},
	{"STUB_AIF0_TX", NULL, "STUB_AIF0_PINCTRL"},
	{"STUB_AIF1_RX", NULL, "STUB_AIF1_PINCTRL"},
	{"STUB_AIF1_TX", NULL, "STUB_AIF1_PINCTRL"},
	{"STUB_AIF2_RX", NULL, "STUB_AIF2_PINCTRL"},
	{"STUB_AIF2_TX", NULL, "STUB_AIF2_PINCTRL"},
	{"STUB_AIF3_RX", NULL, "STUB_AIF3_PINCTRL"},
	{"STUB_AIF3_TX", NULL, "STUB_AIF3_PINCTRL"},
};

static const struct snd_soc_dapm_widget qcs9075_dapm_widgets[] = {
	SND_SOC_DAPM_PINCTRL("MI2S_OUT_PINCTRL", "mi2s_aud_out_active", "mi2s_aud_out_sleep"),
};

static const struct snd_soc_dapm_route qcs9075_dapm_routes[] = {
	{"Speaker", NULL, "MI2S_OUT_PINCTRL"},
};

static const struct snd_soc_ops qcs9100_be_ops = {
	.startup = qcs9100_snd_startup,
	.hw_params = qcs9100_snd_hw_params,
	.hw_free = qcs9100_snd_hw_free,
	.prepare = qcs9100_snd_prepare,
};

static struct snd_soc_card snd_soc_iq8_8275_evk_data = {
	.name = "iq8-8275-evk",
	.driver_name = "qcs8275",
	.dapm_widgets = iq8_8275_evk_dapm_widgets,
	.num_dapm_widgets = ARRAY_SIZE(iq8_8275_evk_dapm_widgets),
	.dapm_routes = iq8_8275_evk_dapm_routes,
	.num_dapm_routes = ARRAY_SIZE(iq8_8275_evk_dapm_routes),
};

static struct snd_soc_card snd_soc_qcs8300_data = {
	.name = "qcs8300-ride",
	.driver_name = "qcs8300",
	.dapm_widgets = qcs8300_dapm_widgets,
	.num_dapm_widgets = ARRAY_SIZE(qcs8300_dapm_widgets),
	.dapm_routes = qcs8300_dapm_routes,
	.num_dapm_routes = ARRAY_SIZE(qcs8300_dapm_routes),
};

static struct snd_soc_card snd_soc_qcs9100_data = {
	.name = "qcs9100-ride",
	.driver_name = "qcs9100",
	.dapm_widgets = qcs9100_dapm_widgets,
	.num_dapm_widgets = ARRAY_SIZE(qcs9100_dapm_widgets),
	.dapm_routes = qcs9100_dapm_routes,
	.num_dapm_routes = ARRAY_SIZE(qcs9100_dapm_routes),
};

static struct snd_soc_card snd_soc_qcs9075_rb8_data = {
	.name = "qcs9075-rb8",
	.driver_name = "sa8775p",
	.dapm_widgets = qcs9075_dapm_widgets,
	.num_dapm_widgets = ARRAY_SIZE(qcs9075_dapm_widgets),
	.dapm_routes = qcs9075_dapm_routes,
	.num_dapm_routes = ARRAY_SIZE(qcs9075_dapm_routes),
        .late_probe = qcm9075_late_probe,
};

static void qcs9100_add_be_ops(struct snd_soc_card *card)
{
	struct snd_soc_dai_link *link;
	int i;

	for_each_card_prelinks(card, i, link) {
		if (link->no_pcm == 1 || link->num_codecs) {
			link->init = qcs9100_snd_init;
			link->be_hw_params_fixup = qcs9100_be_hw_params_fixup;
			link->ops = &qcs9100_be_ops;
		}
	}
}

static int qcs9100_platform_probe(struct platform_device *pdev)
{
	struct snd_soc_card *card;
	struct qcs9100_snd_data *data;
	struct device *dev = &pdev->dev;
	int ret;
        dev_err(dev, "qcs9100_platform_probe: entry\n");
	card = (struct snd_soc_card *)of_device_get_match_data(&pdev->dev);
	if (!card){
                dev_err(dev, "No matching sound card in device tree\n");
		return -EINVAL;
        }
	card->owner = THIS_MODULE;
	/* Allocate the private data */
	data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
	if (!data){
                dev_err(dev, "Failed to allocate private data (qcs9100_snd_data)\n");
		return -ENOMEM;
        }
	card->dev = dev;

	dev_set_drvdata(dev, card);
	snd_soc_card_set_drvdata(card, data);
        dev_err(dev, "qcs9100_platform_probe: parsing devicetree...\n");
	ret = qcom_snd_parse_of(card);
	if (ret){
                dev_err(dev, "qcom_snd_parse_of failed, ret = %d\n", ret);
		return ret;
        }
	card->driver_name = DRIVER_NAME;
	qcs9100_add_be_ops(card);
        dev_err(dev, "qcs9100_platform_probe: getting clocks...\n");
	/* get clock info to set clock for qcs9100 target to support high
	 * speed i2s interface
	 */
	data->macro = devm_clk_get_optional(dev, "macro");
	if (IS_ERR(data->macro)) {
		dev_err(dev, "getting macro clock info FAILED, ret %d\n", PTR_ERR(data->macro));
		return PTR_ERR(data->macro);
	}
	data->dcodec = devm_clk_get_optional(dev, "dcodec");
	if (IS_ERR(data->dcodec)) {
		dev_err(dev, "getting decode clock info FAILED, ret %d\n", PTR_ERR(data->dcodec));
		return PTR_ERR(data->dcodec);
	}
        /*
        data->mclk = devm_clk_get_optional(dev, "mclk");
        if (IS_ERR(data->mclk)) {
                dev_err(dev, "getting mclk clock info FAILED, ret %d\n", PTR_ERR(data->mclk));
                return PTR_ERR(data->mclk);
        }
        */
        dev_err(dev, "qcs9100_platform_probe: registering sound card...\n");
	ret = devm_snd_soc_register_card(dev, card);
	if (ret) {
		dev_err(dev, "devm_snd_soc_register_card failed, ret = %d\n", ret);
		return ret;
	}
        
        ret = qcs9075_enable_mclk(dev);
        if (ret) {
        dev_err(dev, "Failed to enable mclk: %d\n", ret);
        return ret;
    }
	dev_err(dev, "qcs9100_platform_probe: success!\n");
	return 0;
}

static const struct of_device_id snd_qcs9100_dt_match[] = {
	{.compatible = "qcom,iq8-8275-evk-sndcard", .data = &snd_soc_iq8_8275_evk_data},
	{.compatible = "qcom,qcs8300-sndcard", .data = &snd_soc_qcs8300_data},
	{.compatible = "qcom,qcs9100-sndcard", .data = &snd_soc_qcs9100_data},
	{.compatible = "qcom,qcs9075-rb8-sndcard", .data = &snd_soc_qcs9075_rb8_data},
	{}
};

MODULE_DEVICE_TABLE(of, snd_qcs9100_dt_match);

static struct platform_driver snd_qcs9100_driver = {
	.probe  = qcs9100_platform_probe,
	.driver = {
		.name = "snd-qcs9100",
		.of_match_table = snd_qcs9100_dt_match,
	},
};
module_platform_driver(snd_qcs9100_driver);
MODULE_DESCRIPTION("qcs9100 ASoC Machine Driver");
MODULE_LICENSE("GPL");
