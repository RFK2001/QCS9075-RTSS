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
	"\x28\x00\x00\x00\xb3\x1c\xa2\x87"
	"__ubsan_handle_out_of_bounds\0\0\0\0"
	"\x24\x00\x00\x00\x56\xcf\x7a\xdc"
	"__platform_driver_register\0\0"
	"\x14\x00\x00\x00\xbb\xbb\x63\x0b"
	"_dev_err\0\0\0\0"
	"\x1c\x00\x00\x00\xcb\x3a\xb6\x33"
	"q6apm_graph_open\0\0\0\0"
	"\x28\x00\x00\x00\xf0\x66\xb9\xd7"
	"snd_soc_set_runtime_hwparams\0\0\0\0"
	"\x20\x00\x00\x00\xe0\x82\xeb\xbd"
	"q6prm_set_lpass_clock\0\0\0"
	"\x24\x00\x00\x00\xd4\xe2\xaf\xf1"
	"platform_driver_unregister\0\0"
	"\x1c\x00\x00\x00\x33\xa9\x2f\xd1"
	"q6apm_graph_close\0\0\0"
	"\x1c\x00\x00\x00\x7f\x2e\xfc\x6a"
	"q6apm_graph_stop\0\0\0\0"
	"\x2c\x00\x00\x00\xc6\xfa\xb1\x54"
	"__ubsan_handle_load_invalid_value\0\0\0"
	"\x28\x00\x00\x00\xfb\x7e\x16\x10"
	"q6apm_graph_media_format_pcm\0\0\0\0"
	"\x1c\x00\x00\x00\x7a\x05\xf3\x86"
	"q6apm_graph_prepare\0"
	"\x1c\x00\x00\x00\x0d\x49\xf9\x60"
	"q6apm_graph_start\0\0\0"
	"\x10\x00\x00\x00\xad\x64\xb7\xdc"
	"memset\0\0"
	"\x28\x00\x00\x00\x16\xfd\x76\x4d"
	"__of_parse_phandle_with_args\0\0\0\0"
	"\x1c\x00\x00\x00\xcb\xf6\xfd\xf0"
	"__stack_chk_fail\0\0\0\0"
	"\x18\x00\x00\x00\x5b\x8d\xae\x87"
	"devm_kmalloc\0\0\0\0"
	"\x20\x00\x00\x00\xf8\x1e\x43\xdb"
	"of_find_device_by_node\0\0"
	"\x1c\x00\x00\x00\x6e\x5a\xc4\xcb"
	"of_find_property\0\0\0\0"
	"\x14\x00\x00\x00\x36\x9d\x13\xc9"
	"_dev_info\0\0\0"
	"\x28\x00\x00\x00\x02\x9c\x33\xe4"
	"q6dsp_audio_ports_set_config\0\0\0\0"
	"\x28\x00\x00\x00\x72\xd0\x64\x0d"
	"devm_snd_soc_register_component\0"
	"\x10\x00\x00\x00\x7e\x3a\x2c\x12"
	"_printk\0"
	"\x20\x00\x00\x00\x36\x93\x6a\xe5"
	"snd_pcm_format_width\0\0\0\0"
	"\x28\x00\x00\x00\xe4\xf8\x01\x95"
	"q6dsp_get_channel_allocation\0\0\0\0"
	"\x2c\x00\x00\x00\x7d\x34\x06\x91"
	"q6dsp_audio_ports_of_xlate_dai_name\0"
	"\x18\x00\x00\x00\xc1\x58\x39\x19"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "snd-q6apm,snd-soc-core,q6prm,snd-q6dsp-common,snd-pcm");

MODULE_ALIAS("of:N*T*Cqcom,q6apm-lpass-dais");
MODULE_ALIAS("of:N*T*Cqcom,q6apm-lpass-daisC*");

MODULE_INFO(srcversion, "9109A85ABDA8CE613BF9E27");
