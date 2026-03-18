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

KSYMTAB_DATA(asoc_qcom_lpass_cpu_dai_ops, "_gpl", "");
KSYMTAB_DATA(asoc_qcom_lpass_cpu_dai_ops2, "_gpl", "");
KSYMTAB_FUNC(asoc_qcom_lpass_cpu_platform_probe, "_gpl", "");
KSYMTAB_FUNC(asoc_qcom_lpass_cpu_platform_remove, "_gpl", "");
KSYMTAB_FUNC(asoc_qcom_lpass_cpu_platform_shutdown, "_gpl", "");

SYMBOL_CRC(asoc_qcom_lpass_cpu_dai_ops, 0x99b577ec, "_gpl");
SYMBOL_CRC(asoc_qcom_lpass_cpu_dai_ops2, 0x38bda4b2, "_gpl");
SYMBOL_CRC(asoc_qcom_lpass_cpu_platform_probe, 0x43d80456, "_gpl");
SYMBOL_CRC(asoc_qcom_lpass_cpu_platform_remove, 0xaecf9450, "_gpl");
SYMBOL_CRC(asoc_qcom_lpass_cpu_platform_shutdown, 0x67e697c0, "_gpl");

static const char ____versions[]
__used __section("__versions") =
	"\x18\x00\x00\x00\x35\x08\x06\xef"
	"regmap_write\0\0\0\0"
	"\x18\x00\x00\x00\x5b\x8d\xae\x87"
	"devm_kmalloc\0\0\0\0"
	"\x2c\x00\x00\x00\x58\x60\x8d\x40"
	"of_property_read_variable_u32_array\0"
	"\x20\x00\x00\x00\x1d\x39\x33\x17"
	"snd_pcm_add_chmap_ctls\0\0"
	"\x28\x00\x00\x00\x46\x28\xfb\x4e"
	"regmap_fields_update_bits_base\0\0"
	"\x28\x00\x00\x00\xa6\xd6\xc8\x31"
	"platform_get_resource_byname\0\0\0\0"
	"\x18\x00\x00\x00\x76\xb8\xd9\x76"
	"clk_set_rate\0\0\0\0"
	"\x18\x00\x00\x00\xe0\x5e\x30\x7b"
	"devm_clk_get\0\0\0\0"
	"\x28\x00\x00\x00\x72\xd0\x64\x0d"
	"devm_snd_soc_register_component\0"
	"\x14\x00\x00\x00\x71\x73\x9a\x7c"
	"clk_prepare\0"
	"\x1c\x00\x00\x00\xb9\xc5\xdf\x97"
	"of_get_next_child\0\0\0"
	"\x1c\x00\x00\x00\xcb\xf6\xfd\xf0"
	"__stack_chk_fail\0\0\0\0"
	"\x28\x00\x00\x00\xb3\x1c\xa2\x87"
	"__ubsan_handle_out_of_bounds\0\0\0\0"
	"\x20\x00\x00\x00\xa5\x46\xc4\x8b"
	"devm_regmap_field_alloc\0"
	"\x14\x00\x00\x00\xbb\xbb\x63\x0b"
	"_dev_err\0\0\0\0"
	"\x28\x00\x00\x00\x16\xfd\x76\x4d"
	"__of_parse_phandle_with_args\0\0\0\0"
	"\x2c\x00\x00\x00\x19\x73\x72\x30"
	"asoc_qcom_lpass_platform_register\0\0\0"
	"\x10\x00\x00\x00\xad\x64\xb7\xdc"
	"memset\0\0"
	"\x14\x00\x00\x00\x53\xdf\xeb\xc2"
	"_dev_warn\0\0\0"
	"\x20\x00\x00\x00\x81\x54\x0d\x9c"
	"device_get_match_data\0\0\0"
	"\x24\x00\x00\x00\x7f\xc7\x48\x95"
	"__devm_regmap_init_mmio_clk\0"
	"\x30\x00\x00\x00\x06\x19\xae\x4b"
	"devm_platform_ioremap_resource_byname\0\0\0"
	"\x20\x00\x00\x00\x50\x15\x3b\x28"
	"devm_clk_get_optional\0\0\0"
	"\x2c\x00\x00\x00\x61\xe5\x48\xa6"
	"__ubsan_handle_shift_out_of_bounds\0\0"
	"\x20\x00\x00\x00\xf1\x1a\x4c\x38"
	"of_device_is_compatible\0"
	"\x28\x00\x00\x00\x0e\x16\xfc\x3c"
	"devm_regmap_field_bulk_alloc\0\0\0\0"
	"\x14\x00\x00\x00\x9d\xd9\xe6\xb6"
	"clk_disable\0"
	"\x2c\x00\x00\x00\xc6\xfa\xb1\x54"
	"__ubsan_handle_load_invalid_value\0\0\0"
	"\x14\x00\x00\x00\xa6\x88\x55\x81"
	"clk_enable\0\0"
	"\x20\x00\x00\x00\x36\x93\x6a\xe5"
	"snd_pcm_format_width\0\0\0\0"
	"\x18\x00\x00\x00\x0a\xe7\x77\xb0"
	"clk_unprepare\0\0\0"
	"\x18\x00\x00\x00\xc1\x58\x39\x19"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "snd-pcm,snd-soc-core,snd-soc-lpass-platform");


MODULE_INFO(srcversion, "E22FAB5B1A45AF84F3BD9D0");
