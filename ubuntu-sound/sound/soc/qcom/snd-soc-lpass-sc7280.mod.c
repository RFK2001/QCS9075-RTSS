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
	"\x24\x00\x00\x00\xec\x77\xb5\x99"
	"asoc_qcom_lpass_cpu_dai_ops\0"
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
	"\x28\x00\x00\x00\xa6\x29\x55\xf8"
	"asoc_qcom_lpass_cdc_dma_dai_ops\0"
	"\x24\x00\x00\x00\x56\xcf\x7a\xdc"
	"__platform_driver_register\0\0"
	"\x1c\x00\x00\x00\x42\x14\x52\xdf"
	"_find_next_zero_bit\0"
	"\x28\x00\x00\x00\x8d\xdf\x85\xe6"
	"asoc_qcom_lpass_hdmi_dai_ops\0\0\0\0"
	"\x1c\x00\x00\x00\xef\x6d\x5c\xa6"
	"alt_cb_patch_nops\0\0\0"
	"\x30\x00\x00\x00\xc0\x97\xe6\x67"
	"asoc_qcom_lpass_cpu_platform_shutdown\0\0\0"
	"\x1c\x00\x00\x00\xe5\xc8\xd5\xea"
	"clk_bulk_prepare\0\0\0\0"
	"\x18\x00\x00\x00\xc1\x58\x39\x19"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "snd-soc-lpass-cpu,snd-soc-lpass-cdc-dma,snd-soc-lpass-hdmi");

MODULE_ALIAS("of:N*T*Cqcom,sc7280-lpass-cpu");
MODULE_ALIAS("of:N*T*Cqcom,sc7280-lpass-cpuC*");

MODULE_INFO(srcversion, "464E9F8917EB98CA1B5890A");
