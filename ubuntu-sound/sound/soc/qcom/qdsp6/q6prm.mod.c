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

KSYMTAB_FUNC(q6prm_vote_lpass_core_hw, "_gpl", "");
KSYMTAB_FUNC(q6prm_unvote_lpass_core_hw, "_gpl", "");
KSYMTAB_FUNC(q6prm_set_lpass_clock, "_gpl", "");

SYMBOL_CRC(q6prm_vote_lpass_core_hw, 0x56dd6aa2, "_gpl");
SYMBOL_CRC(q6prm_unvote_lpass_core_hw, 0xd037d7e3, "_gpl");
SYMBOL_CRC(q6prm_set_lpass_clock, 0xbdeb82e0, "_gpl");

static const char ____versions[]
__used __section("__versions") =
	"\x20\x00\x00\x00\x08\x79\x18\xcf"
	"__apr_driver_register\0\0\0"
	"\x14\x00\x00\x00\x44\x43\x96\xe2"
	"__wake_up\0\0\0"
	"\x18\x00\x00\x00\x5b\x8d\xae\x87"
	"devm_kmalloc\0\0\0\0"
	"\x18\x00\x00\x00\x9f\x0c\xfb\xce"
	"__mutex_init\0\0\0\0"
	"\x20\x00\x00\x00\x54\xea\xa5\xd9"
	"__init_waitqueue_head\0\0\0"
	"\x1c\x00\x00\x00\xd3\x3f\xe3\x2f"
	"q6apm_is_adsp_ready\0"
	"\x24\x00\x00\x00\x6f\xc7\x0a\x74"
	"devm_of_platform_populate\0\0\0"
	"\x20\x00\x00\x00\xaa\xc8\xfe\xa3"
	"apr_driver_unregister\0\0\0"
	"\x24\x00\x00\x00\x71\x51\xdc\x64"
	"audioreach_alloc_cmd_pkt\0\0\0\0"
	"\x24\x00\x00\x00\xe1\x59\xe1\x22"
	"audioreach_send_cmd_sync\0\0\0\0"
	"\x10\x00\x00\x00\xba\x0c\x7a\x03"
	"kfree\0\0\0"
	"\x18\x00\x00\x00\xc1\x58\x39\x19"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "snd-q6apm");

MODULE_ALIAS("of:N*T*Cqcom,q6prm");
MODULE_ALIAS("of:N*T*Cqcom,q6prmC*");

MODULE_INFO(srcversion, "FACFF4E185A8C96366AFDF4");
