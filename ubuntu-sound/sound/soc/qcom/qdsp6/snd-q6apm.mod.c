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

KSYMTAB_FUNC(q6apm_is_adsp_ready, "_gpl", "");
KSYMTAB_FUNC(q6apm_close_all, "_gpl", "");
KSYMTAB_FUNC(q6apm_graph_media_format_shmem, "_gpl", "");
KSYMTAB_FUNC(q6apm_map_memory_regions, "_gpl", "");
KSYMTAB_FUNC(q6apm_unmap_memory_regions, "_gpl", "");
KSYMTAB_FUNC(q6apm_remove_initial_silence, "_gpl", "");
KSYMTAB_FUNC(q6apm_remove_trailing_silence, "_gpl", "");
KSYMTAB_FUNC(q6apm_enable_compress_module, "_gpl", "");
KSYMTAB_FUNC(q6apm_set_real_module_id, "_gpl", "");
KSYMTAB_FUNC(q6apm_graph_media_format_pcm, "_gpl", "");
KSYMTAB_FUNC(q6apm_graph_get_rx_shmem_module_iid, "_gpl", "");
KSYMTAB_FUNC(q6apm_write_async, "_gpl", "");
KSYMTAB_FUNC(q6apm_read, "_gpl", "");
KSYMTAB_FUNC(q6apm_get_hw_pointer, "_gpl", "");
KSYMTAB_FUNC(q6apm_graph_open, "_gpl", "");
KSYMTAB_FUNC(q6apm_graph_close, "_gpl", "");
KSYMTAB_FUNC(q6apm_graph_prepare, "_gpl", "");
KSYMTAB_FUNC(q6apm_graph_start, "_gpl", "");
KSYMTAB_FUNC(q6apm_graph_stop, "_gpl", "");
KSYMTAB_FUNC(q6apm_graph_flush, "_gpl", "");
KSYMTAB_FUNC(audioreach_alloc_pkt, "_gpl", "");
KSYMTAB_FUNC(audioreach_alloc_apm_pkt, "_gpl", "");
KSYMTAB_FUNC(audioreach_alloc_cmd_pkt, "_gpl", "");
KSYMTAB_FUNC(audioreach_alloc_apm_cmd_pkt, "_gpl", "");
KSYMTAB_FUNC(audioreach_alloc_graph_pkt, "_gpl", "");
KSYMTAB_FUNC(audioreach_send_cmd_sync, "_gpl", "");
KSYMTAB_FUNC(audioreach_graph_send_cmd_sync, "_gpl", "");
KSYMTAB_FUNC(audioreach_send_u32_param, "_gpl", "");
KSYMTAB_FUNC(audioreach_compr_set_param, "_gpl", "");
KSYMTAB_FUNC(audioreach_gain_set_vol_ctrl, "_gpl", "");
KSYMTAB_FUNC(audioreach_set_media_format, "_gpl", "");
KSYMTAB_FUNC(audioreach_graph_free_buf, "_gpl", "");
KSYMTAB_FUNC(audioreach_map_memory_regions, "_gpl", "");
KSYMTAB_FUNC(audioreach_shared_memory_send_eos, "_gpl", "");
KSYMTAB_FUNC(audioreach_tplg_init, "_gpl", "");

SYMBOL_CRC(q6apm_is_adsp_ready, 0x2fe33fd3, "_gpl");
SYMBOL_CRC(q6apm_close_all, 0xc38f2e4d, "_gpl");
SYMBOL_CRC(q6apm_graph_media_format_shmem, 0x88bc0847, "_gpl");
SYMBOL_CRC(q6apm_map_memory_regions, 0x9353240d, "_gpl");
SYMBOL_CRC(q6apm_unmap_memory_regions, 0x14584393, "_gpl");
SYMBOL_CRC(q6apm_remove_initial_silence, 0xdff120a4, "_gpl");
SYMBOL_CRC(q6apm_remove_trailing_silence, 0xbcf194ef, "_gpl");
SYMBOL_CRC(q6apm_enable_compress_module, 0xe6469064, "_gpl");
SYMBOL_CRC(q6apm_set_real_module_id, 0xf8236c9a, "_gpl");
SYMBOL_CRC(q6apm_graph_media_format_pcm, 0x10167efb, "_gpl");
SYMBOL_CRC(q6apm_graph_get_rx_shmem_module_iid, 0x60e66843, "_gpl");
SYMBOL_CRC(q6apm_write_async, 0x1cc88285, "_gpl");
SYMBOL_CRC(q6apm_read, 0x915a2e8b, "_gpl");
SYMBOL_CRC(q6apm_get_hw_pointer, 0x1e65552b, "_gpl");
SYMBOL_CRC(q6apm_graph_open, 0x33b63acb, "_gpl");
SYMBOL_CRC(q6apm_graph_close, 0xd12fa933, "_gpl");
SYMBOL_CRC(q6apm_graph_prepare, 0x86f3057a, "_gpl");
SYMBOL_CRC(q6apm_graph_start, 0x60f9490d, "_gpl");
SYMBOL_CRC(q6apm_graph_stop, 0x6afc2e7f, "_gpl");
SYMBOL_CRC(q6apm_graph_flush, 0x029c3b8e, "_gpl");
SYMBOL_CRC(audioreach_alloc_pkt, 0x7f4d39c8, "_gpl");
SYMBOL_CRC(audioreach_alloc_apm_pkt, 0x5543dd66, "_gpl");
SYMBOL_CRC(audioreach_alloc_cmd_pkt, 0x64dc5171, "_gpl");
SYMBOL_CRC(audioreach_alloc_apm_cmd_pkt, 0x145cf8f6, "_gpl");
SYMBOL_CRC(audioreach_alloc_graph_pkt, 0x82d3788c, "_gpl");
SYMBOL_CRC(audioreach_send_cmd_sync, 0x22e159e1, "_gpl");
SYMBOL_CRC(audioreach_graph_send_cmd_sync, 0x7c26e215, "_gpl");
SYMBOL_CRC(audioreach_send_u32_param, 0x898b4351, "_gpl");
SYMBOL_CRC(audioreach_compr_set_param, 0x4bbc3be5, "_gpl");
SYMBOL_CRC(audioreach_gain_set_vol_ctrl, 0x5032fa7c, "_gpl");
SYMBOL_CRC(audioreach_set_media_format, 0x40273ff7, "_gpl");
SYMBOL_CRC(audioreach_graph_free_buf, 0x19780500, "_gpl");
SYMBOL_CRC(audioreach_map_memory_regions, 0xc12d9dc3, "_gpl");
SYMBOL_CRC(audioreach_shared_memory_send_eos, 0x72990424, "_gpl");
SYMBOL_CRC(audioreach_tplg_init, 0x012bb2be, "_gpl");

static const char ____versions[]
__used __section("__versions") =
	"\x1c\x00\x00\x00\xa9\x9a\xd0\xc6"
	"release_firmware\0\0\0\0"
	"\x18\x00\x00\x00\x44\x1f\x2e\x9f"
	"gpr_free_port\0\0\0"
	"\x14\x00\x00\x00\xb9\x8f\x97\x20"
	"idr_find\0\0\0\0"
	"\x18\x00\x00\x00\x5b\x8d\xae\x87"
	"devm_kmalloc\0\0\0\0"
	"\x20\x00\x00\x00\x60\xaa\x10\xb4"
	"of_get_compatible_child\0"
	"\x18\x00\x00\x00\x3a\x6c\x91\xd9"
	"idr_alloc_u32\0\0\0"
	"\x20\x00\x00\x00\x08\x79\x18\xcf"
	"__apr_driver_register\0\0\0"
	"\x14\x00\x00\x00\xbf\x0f\x54\x92"
	"finish_wait\0"
	"\x1c\x00\x00\x00\xfc\x17\xfd\xa6"
	"request_firmware\0\0\0\0"
	"\x10\x00\x00\x00\xba\x0c\x7a\x03"
	"kfree\0\0\0"
	"\x20\x00\x00\x00\x95\xd4\x26\x8c"
	"prepare_to_wait_event\0\0\0"
	"\x14\x00\x00\x00\x44\x43\x96\xe2"
	"__wake_up\0\0\0"
	"\x20\x00\x00\x00\xaa\xc8\xfe\xa3"
	"apr_driver_unregister\0\0\0"
	"\x28\x00\x00\x00\x72\xd0\x64\x0d"
	"devm_snd_soc_register_component\0"
	"\x1c\x00\x00\x00\xad\x8a\xdd\x8d"
	"schedule_timeout\0\0\0\0"
	"\x1c\x00\x00\x00\xcb\xf6\xfd\xf0"
	"__stack_chk_fail\0\0\0\0"
	"\x20\x00\x00\x00\x5f\x69\x96\x02"
	"refcount_warn_saturate\0\0"
	"\x18\x00\x00\x00\xa3\x48\x7c\xc5"
	"idr_get_next\0\0\0\0"
	"\x28\x00\x00\x00\xb3\x1c\xa2\x87"
	"__ubsan_handle_out_of_bounds\0\0\0\0"
	"\x1c\x00\x00\x00\xfc\xf8\x75\x4e"
	"snd_soc_info_volsw\0\0"
	"\x14\x00\x00\x00\x5b\xa9\x65\x76"
	"idr_remove\0\0"
	"\x18\x00\x00\x00\x75\x79\x48\xfe"
	"init_wait_entry\0"
	"\x14\x00\x00\x00\xbb\xbb\x63\x0b"
	"_dev_err\0\0\0\0"
	"\x14\x00\x00\x00\x03\x16\xf1\xb8"
	"idr_alloc\0\0\0"
	"\x18\x00\x00\x00\xca\x1c\xdb\x24"
	"gpr_send_pkt\0\0\0\0"
	"\x1c\x00\x00\x00\xee\xdc\xba\x94"
	"gpr_send_port_pkt\0\0\0"
	"\x1c\x00\x00\x00\x63\xa5\x03\x4c"
	"random_kmalloc_seed\0"
	"\x14\x00\x00\x00\x4b\x8d\xfa\x4d"
	"mutex_lock\0\0"
	"\x24\x00\x00\x00\x51\x03\x88\xde"
	"snd_soc_tplg_component_load\0"
	"\x18\x00\x00\x00\x9f\x0c\xfb\xce"
	"__mutex_init\0\0\0\0"
	"\x1c\x00\x00\x00\x10\x45\xf4\x91"
	"idr_alloc_cyclic\0\0\0\0"
	"\x14\x00\x00\x00\x53\xdf\xeb\xc2"
	"_dev_warn\0\0\0"
	"\x20\x00\x00\x00\x54\xea\xa5\xd9"
	"__init_waitqueue_head\0\0\0"
	"\x24\x00\x00\x00\xba\x13\x6b\x8a"
	"snd_soc_dapm_kcontrol_dapm\0\0"
	"\x28\x00\x00\x00\x0a\x4e\x74\xc8"
	"snd_soc_tplg_component_remove\0\0\0"
	"\x14\x00\x00\x00\x37\x4d\x38\xfb"
	"kasprintf\0\0\0"
	"\x10\x00\x00\x00\x5a\x25\xd5\xe2"
	"strcmp\0\0"
	"\x2c\x00\x00\x00\x61\xe5\x48\xa6"
	"__ubsan_handle_shift_out_of_bounds\0\0"
	"\x18\x00\x00\x00\x38\xf0\x13\x32"
	"mutex_unlock\0\0\0\0"
	"\x18\x00\x00\x00\x60\x75\x61\x0e"
	"gpr_alloc_port\0\0"
	"\x1c\x00\x00\x00\xef\x6d\x5c\xa6"
	"alt_cb_patch_nops\0\0\0"
	"\x18\x00\x00\x00\xb1\x80\xbd\xfe"
	"kmalloc_trace\0\0\0"
	"\x28\x00\x00\x00\x85\x79\xef\x84"
	"snd_soc_tplg_widget_bind_event\0\0"
	"\x28\x00\x00\x00\xa6\x5a\x7e\x28"
	"snd_soc_dapm_mixer_update_power\0"
	"\x20\x00\x00\x00\x85\xa4\xf3\x6f"
	"dynamic_might_resched\0\0\0"
	"\x20\x00\x00\x00\x39\x18\x2a\xa2"
	"of_platform_populate\0\0\0\0"
	"\x14\x00\x00\x00\x45\x3a\x23\xeb"
	"__kmalloc\0\0\0"
	"\x18\x00\x00\x00\xfb\x61\xdf\xb7"
	"kmalloc_caches\0\0"
	"\x28\x00\x00\x00\xb7\xd5\x11\xec"
	"snd_soc_dapm_kcontrol_widget\0\0\0\0"
	"\x18\x00\x00\x00\xc1\x58\x39\x19"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "snd-soc-core");

MODULE_ALIAS("of:N*T*Cqcom,q6apm");
MODULE_ALIAS("of:N*T*Cqcom,q6apmC*");

MODULE_INFO(srcversion, "0223D1B225474624135D0DC");
