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

KSYMTAB_FUNC(q6routing_stream_open, "_gpl", "");
KSYMTAB_FUNC(q6routing_stream_close, "_gpl", "");

SYMBOL_CRC(q6routing_stream_open, 0x5b75f756, "_gpl");
SYMBOL_CRC(q6routing_stream_close, 0xa7a64259, "_gpl");

static const char ____versions[]
__used __section("__versions") =
	"\x28\x00\x00\x00\xb3\x1c\xa2\x87"
	"__ubsan_handle_out_of_bounds\0\0\0\0"
	"\x14\x00\x00\x00\x4b\x8d\xfa\x4d"
	"mutex_lock\0\0"
	"\x18\x00\x00\x00\x38\xf0\x13\x32"
	"mutex_unlock\0\0\0\0"
	"\x24\x00\x00\x00\x56\xcf\x7a\xdc"
	"__platform_driver_register\0\0"
	"\x10\x00\x00\x00\xba\x0c\x7a\x03"
	"kfree\0\0\0"
	"\x24\x00\x00\x00\xba\x13\x6b\x8a"
	"snd_soc_dapm_kcontrol_dapm\0\0"
	"\x28\x00\x00\x00\xa6\x5a\x7e\x28"
	"snd_soc_dapm_mixer_update_power\0"
	"\x18\x00\x00\x00\x20\x2e\xd1\x9e"
	"kmalloc_large\0\0\0"
	"\x18\x00\x00\x00\x9f\x0c\xfb\xce"
	"__mutex_init\0\0\0\0"
	"\x28\x00\x00\x00\x72\xd0\x64\x0d"
	"devm_snd_soc_register_component\0"
	"\x24\x00\x00\x00\xd4\xe2\xaf\xf1"
	"platform_driver_unregister\0\0"
	"\x10\x00\x00\x00\xad\x64\xb7\xdc"
	"memset\0\0"
	"\x14\x00\x00\x00\x0a\x01\x14\x30"
	"q6adm_open\0\0"
	"\x1c\x00\x00\x00\x60\x14\x42\x28"
	"q6adm_get_copp_id\0\0\0"
	"\x1c\x00\x00\x00\xef\x6d\x5c\xa6"
	"alt_cb_patch_nops\0\0\0"
	"\x1c\x00\x00\x00\x84\xc0\x80\x25"
	"q6adm_matrix_map\0\0\0\0"
	"\x14\x00\x00\x00\xbb\xbb\x63\x0b"
	"_dev_err\0\0\0\0"
	"\x10\x00\x00\x00\x7e\x3a\x2c\x12"
	"_printk\0"
	"\x1c\x00\x00\x00\xcb\xf6\xfd\xf0"
	"__stack_chk_fail\0\0\0\0"
	"\x14\x00\x00\x00\xdb\x10\x5f\xb0"
	"q6adm_close\0"
	"\x1c\x00\x00\x00\xfc\xf8\x75\x4e"
	"snd_soc_info_volsw\0\0"
	"\x18\x00\x00\x00\xc1\x58\x39\x19"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "snd-soc-core,q6adm");

MODULE_ALIAS("of:N*T*Cqcom,q6adm-routing");
MODULE_ALIAS("of:N*T*Cqcom,q6adm-routingC*");

MODULE_INFO(srcversion, "980CDDF131B2B9EB94EF20A");
