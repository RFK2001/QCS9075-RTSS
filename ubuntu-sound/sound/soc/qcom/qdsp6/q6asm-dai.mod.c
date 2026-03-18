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
	"\x1c\x00\x00\x00\x12\xa3\x8a\xd3"
	"q6asm_cmd_nowait\0\0\0\0"
	"\x1c\x00\x00\x00\x0c\x2f\xba\x4f"
	"q6asm_run_nowait\0\0\0\0"
	"\x1c\x00\x00\x00\x76\x7f\x36\xa3"
	"snd_dma_free_pages\0\0"
	"\x24\x00\x00\x00\xe2\x31\xdb\x68"
	"q6asm_unmap_memory_regions\0\0"
	"\x20\x00\x00\x00\xe4\x52\x49\xcc"
	"q6asm_audio_client_free\0"
	"\x20\x00\x00\x00\x59\x42\xa6\xa7"
	"q6routing_stream_close\0\0"
	"\x10\x00\x00\x00\xba\x0c\x7a\x03"
	"kfree\0\0\0"
	"\x14\x00\x00\x00\xd9\xef\xb7\x13"
	"q6asm_cmd\0\0\0"
	"\x24\x00\x00\x00\xdd\xa5\x75\xea"
	"q6asm_map_memory_regions\0\0\0\0"
	"\x20\x00\x00\x00\xa4\x16\xa1\xc5"
	"q6asm_get_session_id\0\0\0\0"
	"\x20\x00\x00\x00\x56\xf7\x75\x5b"
	"q6routing_stream_open\0\0\0"
	"\x1c\x00\x00\x00\x76\xa4\xbf\x25"
	"q6asm_open_write\0\0\0\0"
	"\x14\x00\x00\x00\xbb\xbb\x63\x0b"
	"_dev_err\0\0\0\0"
	"\x30\x00\x00\x00\xa6\xa3\xd3\xa7"
	"q6asm_media_format_block_multi_ch_pcm\0\0\0"
	"\x14\x00\x00\x00\x36\x9d\x13\xc9"
	"_dev_info\0\0\0"
	"\x18\x00\x00\x00\x67\x8d\xdd\xc0"
	"q6asm_open_read\0"
	"\x30\x00\x00\x00\x08\xd1\x7e\xb3"
	"q6asm_enc_cfg_blk_pcm_format_support\0\0\0\0"
	"\x14\x00\x00\x00\x73\x6f\xfe\x4a"
	"q6asm_read\0\0"
	"\x20\x00\x00\x00\x93\xd1\x39\xf0"
	"snd_pcm_period_elapsed\0\0"
	"\x1c\x00\x00\x00\xb0\x7d\x34\xc1"
	"q6asm_write_async\0\0\0"
	"\x28\x00\x00\x00\x84\xff\x9f\x19"
	"snd_pcm_set_managed_buffer_all\0\0"
	"\x1c\x00\x00\x00\xb9\xc5\xdf\x97"
	"of_get_next_child\0\0\0"
	"\x18\x00\x00\x00\x5b\x8d\xae\x87"
	"devm_kmalloc\0\0\0\0"
	"\x2c\x00\x00\x00\x58\x60\x8d\x40"
	"of_property_read_variable_u32_array\0"
	"\x1c\x00\x00\x00\x6e\x5a\xc4\xcb"
	"of_find_property\0\0\0\0"
	"\x28\x00\x00\x00\xb3\x1c\xa2\x87"
	"__ubsan_handle_out_of_bounds\0\0\0\0"
	"\x1c\x00\x00\x00\xcb\xf6\xfd\xf0"
	"__stack_chk_fail\0\0\0\0"
	"\x10\x00\x00\x00\xad\x64\xb7\xdc"
	"memset\0\0"
	"\x28\x00\x00\x00\x16\xfd\x76\x4d"
	"__of_parse_phandle_with_args\0\0\0\0"
	"\x28\x00\x00\x00\x72\xd0\x64\x0d"
	"devm_snd_soc_register_component\0"
	"\x24\x00\x00\x00\xd4\xe2\xaf\xf1"
	"platform_driver_unregister\0\0"
	"\x1c\x00\x00\x00\x63\xa5\x03\x4c"
	"random_kmalloc_seed\0"
	"\x18\x00\x00\x00\xfb\x61\xdf\xb7"
	"kmalloc_caches\0\0"
	"\x18\x00\x00\x00\xb1\x80\xbd\xfe"
	"kmalloc_trace\0\0\0"
	"\x24\x00\x00\x00\x20\xb9\x29\xf6"
	"q6asm_audio_client_alloc\0\0\0\0"
	"\x24\x00\x00\x00\x97\xba\xb7\xb4"
	"snd_pcm_hw_constraint_list\0\0"
	"\x28\x00\x00\x00\x9b\x23\xba\x3f"
	"snd_pcm_hw_constraint_integer\0\0\0"
	"\x24\x00\x00\x00\x55\x6a\x66\x4f"
	"snd_pcm_hw_constraint_step\0\0"
	"\x28\x00\x00\x00\xf0\x66\xb9\xd7"
	"snd_soc_set_runtime_hwparams\0\0\0\0"
	"\x28\x00\x00\x00\xb2\xdb\x41\xaf"
	"snd_pcm_hw_constraint_minmax\0\0\0\0"
	"\x30\x00\x00\x00\x5f\xf8\x0c\x9d"
	"q6asm_stream_media_format_block_flac\0\0\0\0"
	"\x2c\x00\x00\x00\x35\x4b\x7f\xf4"
	"q6asm_stream_media_format_block_ape\0"
	"\x30\x00\x00\x00\xfc\x77\x6c\x1b"
	"q6asm_stream_media_format_block_alac\0\0\0\0"
	"\x30\x00\x00\x00\xdb\x4f\x6b\x85"
	"q6asm_stream_media_format_block_wma_v10\0"
	"\x30\x00\x00\x00\xed\x3e\x69\x2b"
	"q6asm_stream_media_format_block_wma_v9\0\0"
	"\x2c\x00\x00\x00\x42\x5e\xee\xcb"
	"q6asm_stream_remove_initial_silence\0"
	"\x14\x00\x00\x00\x44\x43\x96\xe2"
	"__wake_up\0\0\0"
	"\x30\x00\x00\x00\x17\x4b\xec\x6c"
	"q6asm_stream_remove_trailing_silence\0\0\0\0"
	"\x2c\x00\x00\x00\xc6\xfa\xb1\x54"
	"__ubsan_handle_load_invalid_value\0\0\0"
	"\x20\x00\x00\x00\xe3\x00\x7e\xe8"
	"snd_dma_alloc_dir_pages\0"
	"\x20\x00\x00\x00\x28\xe1\xa4\x12"
	"__arch_copy_from_user\0\0\0"
	"\x1c\x00\x00\x00\xef\x6d\x5c\xa6"
	"alt_cb_patch_nops\0\0\0"
	"\x24\x00\x00\x00\x52\x3f\x0a\x4b"
	"gic_nonsecure_priorities\0\0\0\0"
	"\x1c\x00\x00\x00\x48\x9f\xdb\x88"
	"__check_object_size\0"
	"\x20\x00\x00\x00\x83\x79\x55\x1f"
	"snd_soc_new_compress\0\0\0\0"
	"\x18\x00\x00\x00\xc1\x58\x39\x19"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "q6asm,snd-pcm,q6routing,snd-soc-core");

MODULE_ALIAS("of:N*T*Cqcom,q6asm-dais");
MODULE_ALIAS("of:N*T*Cqcom,q6asm-daisC*");

MODULE_INFO(srcversion, "65DF6D34226CB9510B4B634");
