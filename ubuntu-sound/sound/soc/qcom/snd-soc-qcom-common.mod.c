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

KSYMTAB_FUNC(qcom_snd_parse_of, "_gpl", "");
KSYMTAB_FUNC(qcom_snd_parse_of_v2, "_gpl", "");
KSYMTAB_FUNC(qcom_snd_wcd_jack_setup, "_gpl", "");

SYMBOL_CRC(qcom_snd_parse_of, 0x3f990777, "_gpl");
SYMBOL_CRC(qcom_snd_parse_of_v2, 0x38b2e400, "_gpl");
SYMBOL_CRC(qcom_snd_wcd_jack_setup, 0xd0bf1fa7, "_gpl");

static const char ____versions[]
__used __section("__versions") =
	"\x18\x00\x00\x00\x5b\x8d\xae\x87"
	"devm_kmalloc\0\0\0\0"
	"\x2c\x00\x00\x00\x58\x60\x8d\x40"
	"of_property_read_variable_u32_array\0"
	"\x1c\x00\x00\x00\x7c\xea\xfc\xde"
	"snd_soc_of_get_dlc\0\0"
	"\x1c\x00\x00\x00\x17\x5a\xec\x37"
	"snd_soc_dummy_dlc\0\0\0"
	"\x24\x00\x00\x00\x2c\xe8\xed\xf7"
	"simple_util_parse_daifmt\0\0\0\0"
	"\x28\x00\x00\x00\x45\x4b\xf6\x7e"
	"snd_soc_of_parse_audio_routing\0\0"
	"\x24\x00\x00\x00\xb3\x6b\x02\x62"
	"of_get_next_available_child\0"
	"\x24\x00\x00\x00\xd9\xe6\x11\x82"
	"snd_soc_component_set_jack\0\0"
	"\x1c\x00\x00\x00\xcb\xf6\xfd\xf0"
	"__stack_chk_fail\0\0\0\0"
	"\x2c\x00\x00\x00\xeb\xf8\xbd\x92"
	"snd_soc_dai_link_set_capabilities\0\0\0"
	"\x24\x00\x00\x00\x85\xb5\x73\x1a"
	"snd_soc_of_parse_aux_devs\0\0\0"
	"\x20\x00\x00\x00\xe3\x9f\x78\x5b"
	"of_get_child_by_name\0\0\0\0"
	"\x14\x00\x00\x00\xbb\xbb\x63\x0b"
	"_dev_err\0\0\0\0"
	"\x28\x00\x00\x00\x16\xfd\x76\x4d"
	"__of_parse_phandle_with_args\0\0\0\0"
	"\x20\x00\x00\x00\xfa\xf8\x9a\xfe"
	"of_property_read_string\0"
	"\x1c\x00\x00\x00\x6e\x5a\xc4\xcb"
	"of_find_property\0\0\0\0"
	"\x10\x00\x00\x00\xad\x64\xb7\xdc"
	"memset\0\0"
	"\x14\x00\x00\x00\x53\xdf\xeb\xc2"
	"_dev_warn\0\0\0"
	"\x1c\x00\x00\x00\xd6\x38\xb9\x46"
	"snd_jack_set_key\0\0\0\0"
	"\x28\x00\x00\x00\x04\x1f\x39\x60"
	"snd_soc_of_get_dai_link_codecs\0\0"
	"\x24\x00\x00\x00\xf8\x7f\x25\x97"
	"snd_soc_card_jack_new_pins\0\0"
	"\x28\x00\x00\x00\xa9\x50\x33\xf1"
	"snd_soc_of_parse_pin_switches\0\0\0"
	"\x18\x00\x00\x00\xa5\x4f\xa0\x24"
	"dev_err_probe\0\0\0"
	"\x2c\x00\x00\x00\xc6\xfa\xb1\x54"
	"__ubsan_handle_load_invalid_value\0\0\0"
	"\x30\x00\x00\x00\x9a\xb4\x69\x41"
	"snd_soc_of_parse_audio_simple_widgets\0\0\0"
	"\x24\x00\x00\x00\xcd\x55\x93\xe4"
	"snd_soc_of_parse_card_name\0\0"
	"\x18\x00\x00\x00\xc1\x58\x39\x19"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "snd-soc-core,snd-soc-simple-card-utils,snd");


MODULE_INFO(srcversion, "607677E9C21B15AD02D37A9");
