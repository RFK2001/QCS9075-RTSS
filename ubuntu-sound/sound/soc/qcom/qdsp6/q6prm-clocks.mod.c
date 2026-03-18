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
	"\x24\x00\x00\x00\x56\xcf\x7a\xdc"
	"__platform_driver_register\0\0"
	"\x24\x00\x00\x00\xd4\xe2\xaf\xf1"
	"platform_driver_unregister\0\0"
	"\x20\x00\x00\x00\xe0\x82\xeb\xbd"
	"q6prm_set_lpass_clock\0\0\0"
	"\x24\x00\x00\x00\xa2\x6a\xdd\x56"
	"q6prm_vote_lpass_core_hw\0\0\0\0"
	"\x24\x00\x00\x00\xe3\xd7\x37\xd0"
	"q6prm_unvote_lpass_core_hw\0\0"
	"\x20\x00\x00\x00\xeb\xf2\x19\x12"
	"q6dsp_clock_dev_probe\0\0\0"
	"\x18\x00\x00\x00\xc1\x58\x39\x19"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "q6prm,snd-q6dsp-common");

MODULE_ALIAS("of:N*T*Cqcom,q6prm-lpass-clocks");
MODULE_ALIAS("of:N*T*Cqcom,q6prm-lpass-clocksC*");

MODULE_INFO(srcversion, "46E16A2D6CDF758D8F415D2");
