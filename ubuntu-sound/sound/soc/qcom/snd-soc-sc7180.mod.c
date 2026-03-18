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
	"\x18\x00\x00\x00\x5b\x8d\xae\x87"
	"devm_kmalloc\0\0\0\0"
	"\x18\x00\x00\x00\x71\xc2\xbf\x85"
	"gpiod_set_value\0"
	"\x24\x00\x00\x00\xd4\xe2\xaf\xf1"
	"platform_driver_unregister\0\0"
	"\x1c\x00\x00\x00\x17\x63\x4e\xcc"
	"snd_soc_dai_set_fmt\0"
	"\x20\x00\x00\x00\xe7\x05\x7b\xf5"
	"snd_soc_card_jack_new\0\0\0"
	"\x20\x00\x00\x00\xa4\x68\xf4\x72"
	"snd_soc_dai_set_sysclk\0\0"
	"\x1c\x00\x00\x00\x77\x07\x99\x3f"
	"qcom_snd_parse_of\0\0\0"
	"\x24\x00\x00\x00\xd9\xe6\x11\x82"
	"snd_soc_component_set_jack\0\0"
	"\x24\x00\x00\x00\xfb\x63\x47\xee"
	"snd_soc_dapm_get_pin_switch\0"
	"\x14\x00\x00\x00\xbb\xbb\x63\x0b"
	"_dev_err\0\0\0\0"
	"\x1c\x00\x00\x00\x6e\x5a\xc4\xcb"
	"of_find_property\0\0\0\0"
	"\x24\x00\x00\x00\xba\x13\x6b\x8a"
	"snd_soc_dapm_kcontrol_dapm\0\0"
	"\x24\x00\x00\x00\x5e\x69\x07\x80"
	"snd_soc_info_enum_double\0\0\0\0"
	"\x1c\x00\x00\x00\xd6\x38\xb9\x46"
	"snd_jack_set_key\0\0\0\0"
	"\x10\x00\x00\x00\x5a\x25\xd5\xe2"
	"strcmp\0\0"
	"\x24\x00\x00\x00\x56\xcf\x7a\xdc"
	"__platform_driver_register\0\0"
	"\x24\x00\x00\x00\xf8\x7f\x25\x97"
	"snd_soc_card_jack_new_pins\0\0"
	"\x20\x00\x00\x00\xf1\x1a\x4c\x38"
	"of_device_is_compatible\0"
	"\x1c\x00\x00\x00\xa4\x4b\xf2\xcb"
	"snd_soc_dai_set_pll\0"
	"\x18\x00\x00\x00\x2e\x95\xf2\xe6"
	"devm_gpiod_get\0\0"
	"\x24\x00\x00\x00\x05\x31\x5f\xd9"
	"snd_soc_dapm_put_pin_switch\0"
	"\x28\x00\x00\x00\x84\xed\x71\xa1"
	"snd_soc_dapm_info_pin_switch\0\0\0\0"
	"\x18\x00\x00\x00\xe1\x0b\x1c\x2d"
	"snd_soc_pm_ops\0\0"
	"\x28\x00\x00\x00\x5c\xa8\xfb\x78"
	"snd_pcm_hw_constraint_msbits\0\0\0\0"
	"\x24\x00\x00\x00\x09\x7e\xa8\x39"
	"devm_snd_soc_register_card\0\0"
	"\x18\x00\x00\x00\xc1\x58\x39\x19"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "snd-soc-core,snd-soc-qcom-common,snd,snd-pcm");

MODULE_ALIAS("of:N*T*Cgoogle,sc7180-trogdor");
MODULE_ALIAS("of:N*T*Cgoogle,sc7180-trogdorC*");
MODULE_ALIAS("of:N*T*Cgoogle,sc7180-coachz");
MODULE_ALIAS("of:N*T*Cgoogle,sc7180-coachzC*");
MODULE_ALIAS("of:N*T*Cqcom,sc7180-qdsp6-sndcard");
MODULE_ALIAS("of:N*T*Cqcom,sc7180-qdsp6-sndcardC*");

MODULE_INFO(srcversion, "10F8CBECC1778110ABCCB44");
