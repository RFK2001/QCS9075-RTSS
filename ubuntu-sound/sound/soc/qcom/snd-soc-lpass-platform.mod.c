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

KSYMTAB_FUNC(asoc_qcom_lpass_platform_register, "_gpl", "");

SYMBOL_CRC(asoc_qcom_lpass_platform_register, 0x30727319, "_gpl");

static const char ____versions[]
__used __section("__versions") =
	"\x1c\x00\x00\x00\x48\x9f\xdb\x88"
	"__check_object_size\0"
	"\x1c\x00\x00\x00\xc9\x35\xa3\x8b"
	"regcache_cache_only\0"
	"\x18\x00\x00\x00\x26\xfd\x89\xdd"
	"_copy_to_iter\0\0\0"
	"\x18\x00\x00\x00\xe3\x9a\xfb\x7e"
	"regcache_sync\0\0\0"
	"\x18\x00\x00\x00\x35\x08\x06\xef"
	"regmap_write\0\0\0\0"
	"\x24\x00\x00\x00\x6d\xfc\x06\x06"
	"devm_request_threaded_irq\0\0\0"
	"\x18\x00\x00\x00\x5b\x8d\xae\x87"
	"devm_kmalloc\0\0\0\0"
	"\x28\x00\x00\x00\x46\x28\xfb\x4e"
	"regmap_fields_update_bits_base\0\0"
	"\x18\x00\x00\x00\x5c\xec\x12\x0a"
	"snd_pcm_stop\0\0\0\0"
	"\x18\x00\x00\x00\x1c\x87\xcd\x7c"
	"remap_pfn_range\0"
	"\x10\x00\x00\x00\xba\x0c\x7a\x03"
	"kfree\0\0\0"
	"\x1c\x00\x00\x00\x44\x20\xc3\x2e"
	"regcache_mark_dirty\0"
	"\x14\x00\x00\x00\x20\x4f\x92\x4d"
	"memremap\0\0\0\0"
	"\x28\x00\x00\x00\x72\xd0\x64\x0d"
	"devm_snd_soc_register_component\0"
	"\x10\x00\x00\x00\x7e\x3a\x2c\x12"
	"_printk\0"
	"\x18\x00\x00\x00\x81\xc8\x24\x1d"
	"___ratelimit\0\0\0\0"
	"\x20\x00\x00\x00\xdf\xc5\x7d\x5c"
	"platform_get_irq_byname\0"
	"\x1c\x00\x00\x00\xcb\xf6\xfd\xf0"
	"__stack_chk_fail\0\0\0\0"
	"\x28\x00\x00\x00\xb3\x1c\xa2\x87"
	"__ubsan_handle_out_of_bounds\0\0\0\0"
	"\x14\x00\x00\x00\xbb\xbb\x63\x0b"
	"_dev_err\0\0\0\0"
	"\x1c\x00\x00\x00\x63\xa5\x03\x4c"
	"random_kmalloc_seed\0"
	"\x1c\x00\x00\x00\x40\xd4\xa3\xff"
	"copy_to_iter_fromio\0"
	"\x28\x00\x00\x00\x84\xff\x9f\x19"
	"snd_pcm_set_managed_buffer_all\0\0"
	"\x14\x00\x00\x00\x53\xdf\xeb\xc2"
	"_dev_warn\0\0\0"
	"\x28\x00\x00\x00\x9b\x23\xba\x3f"
	"snd_pcm_hw_constraint_integer\0\0\0"
	"\x2c\x00\x00\x00\x61\xe5\x48\xa6"
	"__ubsan_handle_shift_out_of_bounds\0\0"
	"\x14\x00\x00\x00\x37\xd2\x51\xd2"
	"regmap_read\0"
	"\x1c\x00\x00\x00\x72\xa3\x3f\x48"
	"snd_pcm_stop_xrun\0\0\0"
	"\x18\x00\x00\x00\xa4\x05\x6c\x5f"
	"_copy_from_iter\0"
	"\x28\x00\x00\x00\x0e\x16\xfc\x3c"
	"devm_regmap_field_bulk_alloc\0\0\0\0"
	"\x28\x00\x00\x00\xf0\x66\xb9\xd7"
	"snd_soc_set_runtime_hwparams\0\0\0\0"
	"\x20\x00\x00\x00\xaf\xa5\xaf\x1b"
	"regmap_update_bits_base\0"
	"\x1c\x00\x00\x00\x93\x67\x3e\xfc"
	"copy_from_iter_toio\0"
	"\x20\x00\x00\x00\x93\xd1\x39\xf0"
	"snd_pcm_period_elapsed\0\0"
	"\x18\x00\x00\x00\xb1\x80\xbd\xfe"
	"kmalloc_trace\0\0\0"
	"\x24\x00\x00\x00\x3a\x12\x8d\x97"
	"snd_pcm_lib_default_mmap\0\0\0\0"
	"\x18\x00\x00\x00\xfb\x61\xdf\xb7"
	"kmalloc_caches\0\0"
	"\x20\x00\x00\x00\x36\x93\x6a\xe5"
	"snd_pcm_format_width\0\0\0\0"
	"\x18\x00\x00\x00\xc1\x58\x39\x19"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "snd-pcm,snd-soc-core,snd");


MODULE_INFO(srcversion, "046659840E28741166AA167");
