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
	"\x20\x00\x00\x00\x0b\x05\xdb\x34"
	"_raw_spin_lock_irqsave\0\0"
	"\x24\x00\x00\x00\x70\xce\x5c\xd3"
	"_raw_spin_unlock_irqrestore\0"
	"\x24\x00\x00\x00\x56\xcf\x7a\xdc"
	"__platform_driver_register\0\0"
	"\x18\x00\x00\x00\xa9\xcf\x7e\x09"
	"dma_mmap_attrs\0\0"
	"\x1c\x00\x00\x00\x85\x82\xc8\x1c"
	"q6apm_write_async\0\0\0"
	"\x28\x00\x00\x00\xa4\x20\xf1\xdf"
	"q6apm_remove_initial_silence\0\0\0\0"
	"\x28\x00\x00\x00\xef\x94\xf1\xbc"
	"q6apm_remove_trailing_silence\0\0\0"
	"\x1c\x00\x00\x00\x7f\x2e\xfc\x6a"
	"q6apm_graph_stop\0\0\0\0"
	"\x24\x00\x00\x00\x93\x43\x58\x14"
	"q6apm_unmap_memory_regions\0\0"
	"\x1c\x00\x00\x00\x33\xa9\x2f\xd1"
	"q6apm_graph_close\0\0\0"
	"\x1c\x00\x00\x00\x76\x7f\x36\xa3"
	"snd_dma_free_pages\0\0"
	"\x10\x00\x00\x00\xba\x0c\x7a\x03"
	"kfree\0\0\0"
	"\x14\x00\x00\x00\xbb\xbb\x63\x0b"
	"_dev_err\0\0\0\0"
	"\x20\x00\x00\x00\x2b\x55\x65\x1e"
	"q6apm_get_hw_pointer\0\0\0\0"
	"\x10\x00\x00\x00\xad\x64\xb7\xdc"
	"memset\0\0"
	"\x28\x00\x00\x00\x47\x08\xbc\x88"
	"q6apm_graph_media_format_shmem\0\0"
	"\x28\x00\x00\x00\xfb\x7e\x16\x10"
	"q6apm_graph_media_format_pcm\0\0\0\0"
	"\x24\x00\x00\x00\x0d\x24\x53\x93"
	"q6apm_map_memory_regions\0\0\0\0"
	"\x1c\x00\x00\x00\x7a\x05\xf3\x86"
	"q6apm_graph_prepare\0"
	"\x1c\x00\x00\x00\x0d\x49\xf9\x60"
	"q6apm_graph_start\0\0\0"
	"\x14\x00\x00\x00\x8b\x2e\x5a\x91"
	"q6apm_read\0\0"
	"\x1c\x00\x00\x00\xcb\xf6\xfd\xf0"
	"__stack_chk_fail\0\0\0\0"
	"\x28\x00\x00\x00\x84\xff\x9f\x19"
	"snd_pcm_set_managed_buffer_all\0\0"
	"\x18\x00\x00\x00\x5b\x8d\xae\x87"
	"devm_kmalloc\0\0\0\0"
	"\x28\x00\x00\x00\x16\xfd\x76\x4d"
	"__of_parse_phandle_with_args\0\0\0\0"
	"\x28\x00\x00\x00\x72\xd0\x64\x0d"
	"devm_snd_soc_register_component\0"
	"\x24\x00\x00\x00\xd4\xe2\xaf\xf1"
	"platform_driver_unregister\0\0"
	"\x24\x00\x00\x00\xe5\x3b\xbc\x4b"
	"audioreach_compr_set_param\0\0"
	"\x24\x00\x00\x00\x9a\x6c\x23\xf8"
	"q6apm_set_real_module_id\0\0\0\0"
	"\x2c\x00\x00\x00\xc6\xfa\xb1\x54"
	"__ubsan_handle_load_invalid_value\0\0\0"
	"\x20\x00\x00\x00\x93\xd1\x39\xf0"
	"snd_pcm_period_elapsed\0\0"
	"\x1c\x00\x00\x00\x63\xa5\x03\x4c"
	"random_kmalloc_seed\0"
	"\x18\x00\x00\x00\xfb\x61\xdf\xb7"
	"kmalloc_caches\0\0"
	"\x18\x00\x00\x00\xb1\x80\xbd\xfe"
	"kmalloc_trace\0\0\0"
	"\x1c\x00\x00\x00\xcb\x3a\xb6\x33"
	"q6apm_graph_open\0\0\0\0"
	"\x28\x00\x00\x00\x9b\x23\xba\x3f"
	"snd_pcm_hw_constraint_integer\0\0\0"
	"\x28\x00\x00\x00\xb2\xdb\x41\xaf"
	"snd_pcm_hw_constraint_minmax\0\0\0\0"
	"\x24\x00\x00\x00\x55\x6a\x66\x4f"
	"snd_pcm_hw_constraint_step\0\0"
	"\x14\x00\x00\x00\x44\x43\x96\xe2"
	"__wake_up\0\0\0"
	"\x2c\x00\x00\x00\x24\x04\x99\x72"
	"audioreach_shared_memory_send_eos\0\0\0"
	"\x20\x00\x00\x00\xe3\x00\x7e\xe8"
	"snd_dma_alloc_dir_pages\0"
	"\x28\x00\x00\x00\x64\x90\x46\xe6"
	"q6apm_enable_compress_module\0\0\0\0"
	"\x20\x00\x00\x00\x28\xe1\xa4\x12"
	"__arch_copy_from_user\0\0\0"
	"\x1c\x00\x00\x00\xef\x6d\x5c\xa6"
	"alt_cb_patch_nops\0\0\0"
	"\x24\x00\x00\x00\x52\x3f\x0a\x4b"
	"gic_nonsecure_priorities\0\0\0\0"
	"\x1c\x00\x00\x00\x48\x9f\xdb\x88"
	"__check_object_size\0"
	"\x18\x00\x00\x00\xc1\x58\x39\x19"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "snd-q6apm,snd-pcm,snd-soc-core");

MODULE_ALIAS("of:N*T*Cqcom,q6apm-dais");
MODULE_ALIAS("of:N*T*Cqcom,q6apm-daisC*");

MODULE_INFO(srcversion, "AF30D9B1293F25BB957F4C2");
