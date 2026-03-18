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
	"\x24\x00\x00\x00\xd4\xe2\xaf\xf1"
	"platform_driver_unregister\0\0"
	"\x1c\x00\x00\x00\x4b\x7d\x9f\x47"
	"clk_bulk_disable\0\0\0\0"
	"\x20\x00\x00\x00\xa7\xd4\x37\x7b"
	"_find_first_zero_bit\0\0\0\0"
	"\x1c\x00\x00\x00\x29\x80\xc0\x63"
	"clk_bulk_unprepare\0\0"
	"\x18\x00\x00\x00\x76\xb8\xd9\x76"
	"clk_set_rate\0\0\0\0"
	"\x1c\x00\x00\x00\xf6\x4d\x96\x6d"
	"__dynamic_dev_dbg\0\0\0"
	"\x18\x00\x00\x00\xe0\x5e\x30\x7b"
	"devm_clk_get\0\0\0\0"
	"\x24\x00\x00\x00\xec\x77\xb5\x99"
	"asoc_qcom_lpass_cpu_dai_ops\0"
	"\x14\x00\x00\x00\x71\x73\x9a\x7c"
	"clk_prepare\0"
	"\x1c\x00\x00\x00\x9d\xd9\xfd\x00"
	"devm_clk_bulk_get\0\0\0"
	"\x2c\x00\x00\x00\x50\x94\xcf\xae"
	"asoc_qcom_lpass_cpu_platform_remove\0"
	"\x18\x00\x00\x00\x70\xe7\xa7\xc7"
	"clk_bulk_enable\0"
	"\x14\x00\x00\x00\xbb\xbb\x63\x0b"
	"_dev_err\0\0\0\0"
	"\x2c\x00\x00\x00\x56\x04\xd8\x43"
	"asoc_qcom_lpass_cpu_platform_probe\0\0"
	"\x24\x00\x00\x00\x56\xcf\x7a\xdc"
	"__platform_driver_register\0\0"
	"\x18\x00\x00\x00\x90\x43\x6e\x55"
	"clk_get_rate\0\0\0\0"
	"\x1c\x00\x00\x00\x42\x14\x52\xdf"
	"_find_next_zero_bit\0"
	"\x14\x00\x00\x00\x9d\xd9\xe6\xb6"
	"clk_disable\0"
	"\x1c\x00\x00\x00\xef\x6d\x5c\xa6"
	"alt_cb_patch_nops\0\0\0"
	"\x1c\x00\x00\x00\xe5\xc8\xd5\xea"
	"clk_bulk_prepare\0\0\0\0"
	"\x14\x00\x00\x00\xa6\x88\x55\x81"
	"clk_enable\0\0"
	"\x18\x00\x00\x00\x0a\xe7\x77\xb0"
	"clk_unprepare\0\0\0"
	"\x18\x00\x00\x00\xc1\x58\x39\x19"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "snd-soc-lpass-cpu");

MODULE_ALIAS("of:N*T*Cqcom,lpass-cpu-apq8016");
MODULE_ALIAS("of:N*T*Cqcom,lpass-cpu-apq8016C*");
MODULE_ALIAS("of:N*T*Cqcom,apq8016-lpass-cpu");
MODULE_ALIAS("of:N*T*Cqcom,apq8016-lpass-cpuC*");

MODULE_INFO(srcversion, "0A8BC8EFD520195C35DF105");
