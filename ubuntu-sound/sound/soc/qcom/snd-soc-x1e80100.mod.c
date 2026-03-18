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
	"\x20\x00\x00\x00\xa7\x1f\xbf\xd0"
	"qcom_snd_wcd_jack_setup\0"
	"\x1c\x00\x00\x00\x77\x07\x99\x3f"
	"qcom_snd_parse_of\0\0\0"
	"\x28\x00\x00\x00\xb3\x1c\xa2\x87"
	"__ubsan_handle_out_of_bounds\0\0\0\0"
	"\x20\x00\x00\x00\x96\x71\xa0\x6c"
	"qcom_snd_sdw_prepare\0\0\0\0"
	"\x24\x00\x00\x00\x56\xcf\x7a\xdc"
	"__platform_driver_register\0\0"
	"\x20\x00\x00\x00\x4f\x1d\xa9\x11"
	"qcom_snd_sdw_hw_params\0\0"
	"\x1c\x00\x00\x00\x09\xce\x5b\xda"
	"sdw_release_stream\0\0"
	"\x20\x00\x00\x00\x09\xae\x85\xd0"
	"qcom_snd_sdw_startup\0\0\0\0"
	"\x24\x00\x00\x00\x09\x7e\xa8\x39"
	"devm_snd_soc_register_card\0\0"
	"\x18\x00\x00\x00\xc1\x58\x39\x19"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "snd-soc-qcom-sdw,snd-soc-qcom-common,soundwire-bus,snd-soc-core");

MODULE_ALIAS("of:N*T*Cqcom,x1e80100-sndcard");
MODULE_ALIAS("of:N*T*Cqcom,x1e80100-sndcardC*");

MODULE_INFO(srcversion, "D8670E9230A208EE343C82C");
