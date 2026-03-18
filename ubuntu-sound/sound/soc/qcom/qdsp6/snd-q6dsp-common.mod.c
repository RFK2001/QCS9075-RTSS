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

KSYMTAB_FUNC(q6dsp_map_channels, "_gpl", "");
KSYMTAB_FUNC(q6dsp_get_channel_allocation, "_gpl", "");
KSYMTAB_FUNC(q6dsp_audio_ports_of_xlate_dai_name, "_gpl", "");
KSYMTAB_FUNC(q6dsp_audio_ports_set_config, "_gpl", "");
KSYMTAB_FUNC(q6dsp_clock_dev_probe, "_gpl", "");

SYMBOL_CRC(q6dsp_map_channels, 0x17142e58, "_gpl");
SYMBOL_CRC(q6dsp_get_channel_allocation, 0x9501f8e4, "_gpl");
SYMBOL_CRC(q6dsp_audio_ports_of_xlate_dai_name, 0x9106347d, "_gpl");
SYMBOL_CRC(q6dsp_audio_ports_set_config, 0xe4339c02, "_gpl");
SYMBOL_CRC(q6dsp_clock_dev_probe, 0x1219f2eb, "_gpl");

static const char ____versions[]
__used __section("__versions") =
	"\x18\x00\x00\x00\x5b\x8d\xae\x87"
	"devm_kmalloc\0\0\0\0"
	"\x24\x00\x00\x00\x92\xa9\x68\x0e"
	"devm_of_clk_add_hw_provider\0"
	"\x20\x00\x00\x00\xa8\xc7\x6b\x1c"
	"devm_clk_hw_register\0\0\0\0"
	"\x18\x00\x00\x00\x39\x0c\xb4\x08"
	"clk_hw_get_name\0"
	"\x1c\x00\x00\x00\xcb\xf6\xfd\xf0"
	"__stack_chk_fail\0\0\0\0"
	"\x28\x00\x00\x00\xb3\x1c\xa2\x87"
	"__ubsan_handle_out_of_bounds\0\0\0\0"
	"\x14\x00\x00\x00\xbb\xbb\x63\x0b"
	"_dev_err\0\0\0\0"
	"\x10\x00\x00\x00\xad\x64\xb7\xdc"
	"memset\0\0"
	"\x24\x00\x00\x00\x8b\x28\x48\x5a"
	"of_device_get_match_data\0\0\0\0"
	"\x18\x00\x00\x00\xc1\x58\x39\x19"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "70F583F7C283706E8A33BA1");
