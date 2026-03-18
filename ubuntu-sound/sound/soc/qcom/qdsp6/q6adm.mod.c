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

KSYMTAB_FUNC(q6adm_open, "_gpl", "");
KSYMTAB_FUNC(q6adm_get_copp_id, "_gpl", "");
KSYMTAB_FUNC(q6adm_matrix_map, "_gpl", "");
KSYMTAB_FUNC(q6adm_close, "_gpl", "");

SYMBOL_CRC(q6adm_open, 0x3014010a, "_gpl");
SYMBOL_CRC(q6adm_get_copp_id, 0x28421460, "_gpl");
SYMBOL_CRC(q6adm_matrix_map, 0x2580c084, "_gpl");
SYMBOL_CRC(q6adm_close, 0xb05f10db, "_gpl");

static const char ____versions[]
__used __section("__versions") =
	"\x20\x00\x00\x00\x0b\x05\xdb\x34"
	"_raw_spin_lock_irqsave\0\0"
	"\x1c\x00\x00\x00\xef\x6d\x5c\xa6"
	"alt_cb_patch_nops\0\0\0"
	"\x24\x00\x00\x00\x70\xce\x5c\xd3"
	"_raw_spin_unlock_irqrestore\0"
	"\x10\x00\x00\x00\xba\x0c\x7a\x03"
	"kfree\0\0\0"
	"\x28\x00\x00\x00\xb3\x1c\xa2\x87"
	"__ubsan_handle_out_of_bounds\0\0\0\0"
	"\x14\x00\x00\x00\x4b\x8d\xfa\x4d"
	"mutex_lock\0\0"
	"\x18\x00\x00\x00\x5a\xa4\xa9\xcc"
	"apr_send_pkt\0\0\0\0"
	"\x20\x00\x00\x00\x85\xa4\xf3\x6f"
	"dynamic_might_resched\0\0\0"
	"\x18\x00\x00\x00\x75\x79\x48\xfe"
	"init_wait_entry\0"
	"\x1c\x00\x00\x00\xad\x8a\xdd\x8d"
	"schedule_timeout\0\0\0\0"
	"\x20\x00\x00\x00\x95\xd4\x26\x8c"
	"prepare_to_wait_event\0\0\0"
	"\x14\x00\x00\x00\xbf\x0f\x54\x92"
	"finish_wait\0"
	"\x18\x00\x00\x00\x38\xf0\x13\x32"
	"mutex_unlock\0\0\0\0"
	"\x14\x00\x00\x00\xbb\xbb\x63\x0b"
	"_dev_err\0\0\0\0"
	"\x1c\x00\x00\x00\xcb\xf6\xfd\xf0"
	"__stack_chk_fail\0\0\0\0"
	"\x20\x00\x00\x00\x08\x79\x18\xcf"
	"__apr_driver_register\0\0\0"
	"\x18\x00\x00\x00\x5b\x8d\xae\x87"
	"devm_kmalloc\0\0\0\0"
	"\x20\x00\x00\x00\x0d\xea\x02\x9b"
	"q6core_get_svc_api_info\0"
	"\x18\x00\x00\x00\x9f\x0c\xfb\xce"
	"__mutex_init\0\0\0\0"
	"\x20\x00\x00\x00\x54\xea\xa5\xd9"
	"__init_waitqueue_head\0\0\0"
	"\x24\x00\x00\x00\x6f\xc7\x0a\x74"
	"devm_of_platform_populate\0\0\0"
	"\x20\x00\x00\x00\xaa\xc8\xfe\xa3"
	"apr_driver_unregister\0\0\0"
	"\x20\x00\x00\x00\x5f\x69\x96\x02"
	"refcount_warn_saturate\0\0"
	"\x14\x00\x00\x00\x45\x3a\x23\xeb"
	"__kmalloc\0\0\0"
	"\x14\x00\x00\x00\x44\x43\x96\xe2"
	"__wake_up\0\0\0"
	"\x1c\x00\x00\x00\x63\xa5\x03\x4c"
	"random_kmalloc_seed\0"
	"\x18\x00\x00\x00\xfb\x61\xdf\xb7"
	"kmalloc_caches\0\0"
	"\x18\x00\x00\x00\xb1\x80\xbd\xfe"
	"kmalloc_trace\0\0\0"
	"\x1c\x00\x00\x00\x3b\x99\x8d\x49"
	"q6afe_get_port_id\0\0\0"
	"\x1c\x00\x00\x00\x58\x2e\x14\x17"
	"q6dsp_map_channels\0\0"
	"\x18\x00\x00\x00\xc1\x58\x39\x19"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "q6core,q6afe,snd-q6dsp-common");

MODULE_ALIAS("of:N*T*Cqcom,q6adm");
MODULE_ALIAS("of:N*T*Cqcom,q6admC*");

MODULE_INFO(srcversion, "633908A5C18F81808646EA2");
