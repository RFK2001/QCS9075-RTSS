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

KSYMTAB_DATA(asoc_qcom_lpass_cdc_dma_dai_ops, "_gpl", "");

SYMBOL_CRC(asoc_qcom_lpass_cdc_dma_dai_ops, 0xf85529a6, "_gpl");

static const char ____versions[]
__used __section("__versions") =
	"\x28\x00\x00\x00\x46\x28\xfb\x4e"
	"regmap_fields_update_bits_base\0\0"
	"\x18\x00\x00\x00\x76\xb8\xd9\x76"
	"clk_set_rate\0\0\0\0"
	"\x14\x00\x00\x00\x71\x73\x9a\x7c"
	"clk_prepare\0"
	"\x1c\x00\x00\x00\xcb\xf6\xfd\xf0"
	"__stack_chk_fail\0\0\0\0"
	"\x14\x00\x00\x00\xbb\xbb\x63\x0b"
	"_dev_err\0\0\0\0"
	"\x14\x00\x00\x00\x9d\xd9\xe6\xb6"
	"clk_disable\0"
	"\x14\x00\x00\x00\xa6\x88\x55\x81"
	"clk_enable\0\0"
	"\x18\x00\x00\x00\x0a\xe7\x77\xb0"
	"clk_unprepare\0\0\0"
	"\x18\x00\x00\x00\xc1\x58\x39\x19"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "2EA1115E265506B47E3C8D0");
