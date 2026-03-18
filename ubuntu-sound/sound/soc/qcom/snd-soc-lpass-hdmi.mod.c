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

KSYMTAB_DATA(asoc_qcom_lpass_hdmi_dai_ops, "_gpl", "");

SYMBOL_CRC(asoc_qcom_lpass_hdmi_dai_ops, 0xe685df8d, "_gpl");

static const char ____versions[]
__used __section("__versions") =
	"\x28\x00\x00\x00\x70\xe3\x4b\xd4"
	"regmap_field_update_bits_base\0\0\0"
	"\x14\x00\x00\x00\xbb\xbb\x63\x0b"
	"_dev_err\0\0\0\0"
	"\x20\x00\x00\x00\x36\x93\x6a\xe5"
	"snd_pcm_format_width\0\0\0\0"
	"\x18\x00\x00\x00\xc1\x58\x39\x19"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "snd-pcm");


MODULE_INFO(srcversion, "23E66B659350E244ECFCBE2");
