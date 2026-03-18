#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

#ifdef CONFIG_UNWINDER_ORC
#include <asm/orc_header.h>
ORC_HEADER;
#endif

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif



static const char ____versions[]
__used __section("__versions") =
	"\x20\x00\x00\x00\x6c\x28\xeb\x97"
	"qcom_snd_sdw_hw_free\0\0\0\0"
	"\x18\x00\x00\x00\x5b\x8d\xae\x87"
	"devm_kmalloc\0\0\0\0"
	"\x24\x00\x00\x00\xd4\xe2\xaf\xf1"
	"platform_driver_unregister\0\0"
	"\x14\x00\x00\x00\x6e\x4a\x6e\x65"
	"snprintf\0\0\0\0"
	"\x20\x00\x00\x00\xa7\x1f\xbf\xd0"
	"qcom_snd_wcd_jack_setup\0"
	"\x1c\x00\x00\x00\x17\x63\x4e\xcc"
	"snd_soc_dai_set_fmt\0"
	"\x20\x00\x00\x00\xe7\x05\x7b\xf5"
	"snd_soc_card_jack_new\0\0\0"
	"\x20\x00\x00\x00\xa4\x68\xf4\x72"
	"snd_soc_dai_set_sysclk\0\0"
	"\x24\x00\x00\x00\xd9\xe6\x11\x82"
	"snd_soc_component_set_jack\0\0"
	"\x1c\x00\x00\x00\xcb\xf6\xfd\xf0"
	"__stack_chk_fail\0\0\0\0"
	"\x28\x00\x00\x00\xb3\x1c\xa2\x87"
	"__ubsan_handle_out_of_bounds\0\0\0\0"
	"\x14\x00\x00\x00\xbb\xbb\x63\x0b"
	"_dev_err\0\0\0\0"
	"\x20\x00\x00\x00\x96\x71\xa0\x6c"
	"qcom_snd_sdw_prepare\0\0\0\0"
	"\x1c\x00\x00\x00\xc3\x43\x48\xd1"
	"dapm_pinctrl_event\0\0"
	"\x14\x00\x00\x00\x53\xdf\xeb\xc2"
	"_dev_warn\0\0\0"
	"\x24\x00\x00\x00\xdf\x71\x3e\x32"
	"snd_soc_dai_set_channel_map\0"
	"\x10\x00\x00\x00\x5a\x25\xd5\xe2"
	"strcmp\0\0"
	"\x24\x00\x00\x00\x56\xcf\x7a\xdc"
	"__platform_driver_register\0\0"
	"\x20\x00\x00\x00\x4f\x1d\xa9\x11"
	"qcom_snd_sdw_hw_params\0\0"
	"\x20\x00\x00\x00\x00\xe4\xb2\x38"
	"qcom_snd_parse_of_v2\0\0\0\0"
	"\x24\x00\x00\x00\x8b\x28\x48\x5a"
	"of_device_get_match_data\0\0\0\0"
	"\x24\x00\x00\x00\x09\x7e\xa8\x39"
	"devm_snd_soc_register_card\0\0"
	"\x18\x00\x00\x00\xc1\x58\x39\x19"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "snd-soc-qcom-sdw,snd-soc-qcom-common,snd-soc-core");

MODULE_ALIAS("of:N*T*Cqcom,qcm6490-sndcard");
MODULE_ALIAS("of:N*T*Cqcom,qcm6490-sndcardC*");
MODULE_ALIAS("of:N*T*Cqcom,qcs6490-rubikpi3-sndcard");
MODULE_ALIAS("of:N*T*Cqcom,qcs6490-rubikpi3-sndcardC*");
MODULE_ALIAS("of:N*T*Cqcom,qcs6490-rb3gen2-sndcard");
MODULE_ALIAS("of:N*T*Cqcom,qcs6490-rb3gen2-sndcardC*");
MODULE_ALIAS("of:N*T*Cqcom,qcs6490-rb3gen2-ia-sndcard");
MODULE_ALIAS("of:N*T*Cqcom,qcs6490-rb3gen2-ia-sndcardC*");
MODULE_ALIAS("of:N*T*Cqcom,qcs6490-rb3gen2-ptz-sndcard");
MODULE_ALIAS("of:N*T*Cqcom,qcs6490-rb3gen2-ptz-sndcardC*");
MODULE_ALIAS("of:N*T*Cqcom,qcs6490-rb3gen2-video-sndcard");
MODULE_ALIAS("of:N*T*Cqcom,qcs6490-rb3gen2-video-sndcardC*");
MODULE_ALIAS("of:N*T*Cqcom,qcs6490-rb3gen2-vision-sndcard");
MODULE_ALIAS("of:N*T*Cqcom,qcs6490-rb3gen2-vision-sndcardC*");

MODULE_INFO(srcversion, "CC8C6481A170D486CB0A3ED");
