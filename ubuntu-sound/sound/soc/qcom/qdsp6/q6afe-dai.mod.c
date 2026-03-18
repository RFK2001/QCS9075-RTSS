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
	"\x20\x00\x00\x00\x63\x00\xf6\x7d"
	"q6afe_port_set_sysclk\0\0\0"
	"\x18\x00\x00\x00\xeb\x6e\x9b\x36"
	"q6afe_port_put\0\0"
	"\x10\x00\x00\x00\x7e\x3a\x2c\x12"
	"_printk\0"
	"\x10\x00\x00\x00\xad\x64\xb7\xdc"
	"memset\0\0"
	"\x18\x00\x00\x00\x5b\x8d\xae\x87"
	"devm_kmalloc\0\0\0\0"
	"\x1c\x00\x00\x00\xb9\xc5\xdf\x97"
	"of_get_next_child\0\0\0"
	"\x2c\x00\x00\x00\x58\x60\x8d\x40"
	"of_property_read_variable_u32_array\0"
	"\x28\x00\x00\x00\x02\x9c\x33\xe4"
	"q6dsp_audio_ports_set_config\0\0\0\0"
	"\x28\x00\x00\x00\x72\xd0\x64\x0d"
	"devm_snd_soc_register_component\0"
	"\x1c\x00\x00\x00\xcb\xf6\xfd\xf0"
	"__stack_chk_fail\0\0\0\0"
	"\x2c\x00\x00\x00\x61\xe5\x48\xa6"
	"__ubsan_handle_shift_out_of_bounds\0\0"
	"\x24\x00\x00\x00\xd4\xe2\xaf\xf1"
	"platform_driver_unregister\0\0"
	"\x18\x00\x00\x00\xe7\xd6\x16\x3b"
	"q6afe_port_stop\0"
	"\x2c\x00\x00\x00\xc6\xfa\xb1\x54"
	"__ubsan_handle_load_invalid_value\0\0\0"
	"\x20\x00\x00\x00\x4f\x30\x32\x53"
	"q6afe_slim_port_prepare\0"
	"\x24\x00\x00\x00\x80\x47\xa5\x07"
	"q6afe_cdc_dma_port_prepare\0\0"
	"\x1c\x00\x00\x00\xa8\x46\x52\xe4"
	"q6afe_port_start\0\0\0\0"
	"\x20\x00\x00\x00\x70\x23\xf2\xfa"
	"q6afe_tdm_port_prepare\0\0"
	"\x20\x00\x00\x00\x86\x97\x80\xae"
	"q6afe_hdmi_port_prepare\0"
	"\x20\x00\x00\x00\x59\x3c\x52\xd4"
	"q6afe_i2s_port_prepare\0\0"
	"\x20\x00\x00\x00\xc1\x0e\xae\xbc"
	"q6afe_port_get_from_id\0\0"
	"\x20\x00\x00\x00\x36\x93\x6a\xe5"
	"snd_pcm_format_width\0\0\0\0"
	"\x28\x00\x00\x00\xe4\xf8\x01\x95"
	"q6dsp_get_channel_allocation\0\0\0\0"
	"\x2c\x00\x00\x00\x7d\x34\x06\x91"
	"q6dsp_audio_ports_of_xlate_dai_name\0"
	"\x18\x00\x00\x00\xc1\x58\x39\x19"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "q6afe,snd-q6dsp-common,snd-soc-core,snd-pcm");

MODULE_ALIAS("of:N*T*Cqcom,q6afe-dais");
MODULE_ALIAS("of:N*T*Cqcom,q6afe-daisC*");

MODULE_INFO(srcversion, "4847472EC52B8243A33A90F");
