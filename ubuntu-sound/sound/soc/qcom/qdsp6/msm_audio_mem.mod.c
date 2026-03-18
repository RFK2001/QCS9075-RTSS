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

KSYMTAB_FUNC(msm_audio_get_phy_addr, "_gpl", "");
KSYMTAB_FUNC(msm_audio_mem_crash_handler, "_gpl", "");

SYMBOL_CRC(msm_audio_get_phy_addr, 0x13b963ad, "_gpl");
SYMBOL_CRC(msm_audio_mem_crash_handler, 0x8f80a4f6, "_gpl");

static const char ____versions[]
__used __section("__versions") =
	"\x14\x00\x00\x00\x4b\x8d\xfa\x4d"
	"mutex_lock\0\0"
	"\x18\x00\x00\x00\x38\xf0\x13\x32"
	"mutex_unlock\0\0\0\0"
	"\x1c\x00\x00\x00\x65\x62\xf5\x2c"
	"__dynamic_pr_debug\0\0"
	"\x10\x00\x00\x00\x7e\x3a\x2c\x12"
	"_printk\0"
	"\x24\x00\x00\x00\x56\xcf\x7a\xdc"
	"__platform_driver_register\0\0"
	"\x14\x00\x00\x00\x56\x25\x6e\xc6"
	"put_device\0\0"
	"\x14\x00\x00\x00\xee\xa9\xa4\x6e"
	"get_device\0\0"
	"\x24\x00\x00\x00\xd4\xe2\xaf\xf1"
	"platform_driver_unregister\0\0"
	"\x10\x00\x00\x00\xad\x64\xb7\xdc"
	"memset\0\0"
	"\x18\x00\x00\x00\x5b\x8d\xae\x87"
	"devm_kmalloc\0\0\0\0"
	"\x1c\x00\x00\x00\x6e\x5a\xc4\xcb"
	"of_find_property\0\0\0\0"
	"\x2c\x00\x00\x00\xa9\x9c\xd0\x16"
	"of_reserved_mem_device_init_by_idx\0\0"
	"\x18\x00\x00\x00\x00\xfe\x80\xeb"
	"cma_heap_add\0\0\0\0"
	"\x18\x00\x00\x00\x9f\x0c\xfb\xce"
	"__mutex_init\0\0\0\0"
	"\x1c\x00\x00\x00\x2b\x2f\xec\xe3"
	"alloc_chrdev_region\0"
	"\x18\x00\x00\x00\x0f\x96\x21\xcb"
	"class_create\0\0\0\0"
	"\x18\x00\x00\x00\x11\xb4\x28\xaf"
	"device_create\0\0\0"
	"\x14\x00\x00\x00\x84\x83\x65\x87"
	"cdev_init\0\0\0"
	"\x14\x00\x00\x00\x60\xa9\x5b\x29"
	"cdev_add\0\0\0\0"
	"\x1c\x00\x00\x00\xf6\x4d\x96\x6d"
	"__dynamic_dev_dbg\0\0\0"
	"\x20\x00\x00\x00\x16\xfa\x7c\x89"
	"of_property_read_u64\0\0\0\0"
	"\x28\x00\x00\x00\x16\xfd\x76\x4d"
	"__of_parse_phandle_with_args\0\0\0\0"
	"\x14\x00\x00\x00\xbb\xbb\x63\x0b"
	"_dev_err\0\0\0\0"
	"\x18\x00\x00\x00\x1f\x1f\xaa\x8f"
	"device_destroy\0\0"
	"\x18\x00\x00\x00\x18\x96\xb0\x1d"
	"class_destroy\0\0\0"
	"\x24\x00\x00\x00\x33\xb3\x91\x60"
	"unregister_chrdev_region\0\0\0\0"
	"\x1c\x00\x00\x00\xcb\xf6\xfd\xf0"
	"__stack_chk_fail\0\0\0\0"
	"\x2c\x00\x00\x00\xc6\xfa\xb1\x54"
	"__ubsan_handle_load_invalid_value\0\0\0"
	"\x14\x00\x00\x00\x70\x78\x0c\x92"
	"cdev_del\0\0\0\0"
	"\x24\x00\x00\x00\x4c\x23\xb6\x7b"
	"dma_buf_unmap_attachment\0\0\0\0"
	"\x18\x00\x00\x00\x4c\x9b\x7c\x8d"
	"dma_buf_detach\0\0"
	"\x14\x00\x00\x00\x39\xc0\xbb\x02"
	"dma_buf_put\0"
	"\x10\x00\x00\x00\xba\x0c\x7a\x03"
	"kfree\0\0\0"
	"\x18\x00\x00\x00\xad\x5f\x06\xf0"
	"dma_buf_vunmap\0\0"
	"\x20\x00\x00\x00\x65\x16\x6c\x40"
	"dma_buf_end_cpu_access\0\0"
	"\x1c\x00\x00\x00\x8a\xed\xac\xcd"
	"qcom_scm_assign_mem\0"
	"\x1c\x00\x00\x00\x63\xa5\x03\x4c"
	"random_kmalloc_seed\0"
	"\x18\x00\x00\x00\xfb\x61\xdf\xb7"
	"kmalloc_caches\0\0"
	"\x18\x00\x00\x00\xb1\x80\xbd\xfe"
	"kmalloc_trace\0\0\0"
	"\x18\x00\x00\x00\x97\xa6\x3d\xd2"
	"dma_buf_attach\0\0"
	"\x20\x00\x00\x00\xb2\xcb\xd5\x8c"
	"dma_buf_map_attachment\0\0"
	"\x18\x00\x00\x00\x81\xc8\x24\x1d"
	"___ratelimit\0\0\0\0"
	"\x14\x00\x00\x00\xbf\x83\x3d\x01"
	"dma_buf_get\0"
	"\x24\x00\x00\x00\xcf\x85\x98\xb4"
	"dma_buf_begin_cpu_access\0\0\0\0"
	"\x18\x00\x00\x00\x92\x71\x82\xdd"
	"dma_buf_vmap\0\0\0\0"
	"\x18\x00\x00\x00\xc1\x58\x39\x19"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cqcom,msm-audio-mem");
MODULE_ALIAS("of:N*T*Cqcom,msm-audio-memC*");

MODULE_INFO(srcversion, "E46C8E05255FB10407297DD");
