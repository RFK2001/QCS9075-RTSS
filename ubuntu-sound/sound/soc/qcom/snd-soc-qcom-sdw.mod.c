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
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

KSYMTAB_FUNC(qcom_snd_sdw_startup, "_gpl", "");
KSYMTAB_FUNC(qcom_snd_sdw_prepare, "_gpl", "");
KSYMTAB_FUNC(qcom_snd_sdw_hw_params, "_gpl", "");
KSYMTAB_FUNC(qcom_snd_sdw_hw_free, "_gpl", "");

SYMBOL_CRC(qcom_snd_sdw_startup, 0xd085ae09, "_gpl");
SYMBOL_CRC(qcom_snd_sdw_prepare, 0x6ca07196, "_gpl");
SYMBOL_CRC(qcom_snd_sdw_hw_params, 0x11a91d4f, "_gpl");
SYMBOL_CRC(qcom_snd_sdw_hw_free, 0x97eb286c, "_gpl");

static const char ____versions[]
__used __section("__versions") =
	"\x1c\x00\x00\x00\x79\x2d\x12\x9e"
	"sdw_alloc_stream\0\0\0\0"
	"\x1c\x00\x00\x00\xbf\x88\xde\x4c"
	"sdw_disable_stream\0\0"
	"\x14\x00\x00\x00\xbb\xbb\x63\x0b"
	"_dev_err\0\0\0\0"
	"\x20\x00\x00\x00\x59\x1d\x89\x71"
	"sdw_deprepare_stream\0\0\0\0"
	"\x1c\x00\x00\x00\x2e\x2c\xec\xbb"
	"sdw_enable_stream\0\0\0"
	"\x2c\x00\x00\x00\xc6\xfa\xb1\x54"
	"__ubsan_handle_load_invalid_value\0\0\0"
	"\x1c\x00\x00\x00\x09\xce\x5b\xda"
	"sdw_release_stream\0\0"
	"\x1c\x00\x00\x00\x6b\x70\xd1\x16"
	"sdw_prepare_stream\0\0"
	"\x18\x00\x00\x00\xc1\x58\x39\x19"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "soundwire-bus");


MODULE_INFO(srcversion, "97968D3B99F9BF0C0D82F47");
