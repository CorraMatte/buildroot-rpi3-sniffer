#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x453f97d9, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x6bc3fbc0, __VMLINUX_SYMBOL_STR(__unregister_chrdev) },
	{ 0x9416e1d8, __VMLINUX_SYMBOL_STR(__request_region) },
	{ 0xd68acabb, __VMLINUX_SYMBOL_STR(class_remove_file_ns) },
	{ 0x5e1d901d, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x12da5bb2, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0xac905e2d, __VMLINUX_SYMBOL_STR(single_open) },
	{ 0xd5156e3d, __VMLINUX_SYMBOL_STR(usb_init_urb) },
	{ 0xc44935b7, __VMLINUX_SYMBOL_STR(single_release) },
	{ 0x120cc20a, __VMLINUX_SYMBOL_STR(usb_reset_endpoint) },
	{ 0x20000329, __VMLINUX_SYMBOL_STR(simple_strtoul) },
	{ 0x62ebd134, __VMLINUX_SYMBOL_STR(seq_printf) },
	{ 0xc87c1f84, __VMLINUX_SYMBOL_STR(ktime_get) },
	{ 0x651a7c16, __VMLINUX_SYMBOL_STR(usb_kill_urb) },
	{ 0x5fddf6af, __VMLINUX_SYMBOL_STR(remove_proc_entry) },
	{ 0x93eba143, __VMLINUX_SYMBOL_STR(__register_chrdev) },
	{ 0xbbc1fc8f, __VMLINUX_SYMBOL_STR(driver_for_each_device) },
	{ 0xb1ad28e0, __VMLINUX_SYMBOL_STR(__gnu_mcount_nc) },
	{ 0x514cc273, __VMLINUX_SYMBOL_STR(arm_copy_from_user) },
	{ 0x705adb3f, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0xd8f6f063, __VMLINUX_SYMBOL_STR(device_create_with_groups) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0xa6aaff3a, __VMLINUX_SYMBOL_STR(seq_read) },
	{ 0x7d11c268, __VMLINUX_SYMBOL_STR(jiffies) },
	{ 0x189c5980, __VMLINUX_SYMBOL_STR(arm_copy_to_user) },
	{ 0x81da44af, __VMLINUX_SYMBOL_STR(mutex_trylock) },
	{ 0xe2d5255a, __VMLINUX_SYMBOL_STR(strcmp) },
	{ 0x275ef902, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0xe707d823, __VMLINUX_SYMBOL_STR(__aeabi_uidiv) },
	{ 0xfaad8cb7, __VMLINUX_SYMBOL_STR(param_ops_charp) },
	{ 0xfa2a45e, __VMLINUX_SYMBOL_STR(__memzero) },
	{ 0x5f754e5a, __VMLINUX_SYMBOL_STR(memset) },
	{ 0xc02c0b2a, __VMLINUX_SYMBOL_STR(ioport_resource) },
	{ 0xe0a4096f, __VMLINUX_SYMBOL_STR(device_del) },
	{ 0x51d559d1, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irqrestore) },
	{ 0x37befc70, __VMLINUX_SYMBOL_STR(jiffies_to_msecs) },
	{ 0x53b432e, __VMLINUX_SYMBOL_STR(usb_deregister) },
	{ 0x295dc01, __VMLINUX_SYMBOL_STR(__mutex_init) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x2c6609df, __VMLINUX_SYMBOL_STR(sysfs_remove_file_from_group) },
	{ 0xf8ccda, __VMLINUX_SYMBOL_STR(usb_set_interface) },
	{ 0xa1c76e0a, __VMLINUX_SYMBOL_STR(_cond_resched) },
	{ 0x328a05f1, __VMLINUX_SYMBOL_STR(strncpy) },
	{ 0x592f895c, __VMLINUX_SYMBOL_STR(usb_control_msg) },
	{ 0x4004d702, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x8e865d3c, __VMLINUX_SYMBOL_STR(arm_delay_ops) },
	{ 0x622598b1, __VMLINUX_SYMBOL_STR(init_wait_entry) },
	{ 0x2196324, __VMLINUX_SYMBOL_STR(__aeabi_idiv) },
	{ 0x59e5070d, __VMLINUX_SYMBOL_STR(__do_div64) },
	{ 0xa02090f9, __VMLINUX_SYMBOL_STR(usb_submit_urb) },
	{ 0xa051d6dc, __VMLINUX_SYMBOL_STR(usb_reset_device) },
	{ 0xd62c833f, __VMLINUX_SYMBOL_STR(schedule_timeout) },
	{ 0x1000e51, __VMLINUX_SYMBOL_STR(schedule) },
	{ 0xd7b3b161, __VMLINUX_SYMBOL_STR(usb_clear_halt) },
	{ 0xec2188e5, __VMLINUX_SYMBOL_STR(class_create_file_ns) },
	{ 0xfbc6f995, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x598542b2, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irqsave) },
	{ 0xc1b09ab, __VMLINUX_SYMBOL_STR(param_ops_byte) },
	{ 0xd85cd67e, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0xf6ebc03b, __VMLINUX_SYMBOL_STR(net_ratelimit) },
	{ 0x344b7739, __VMLINUX_SYMBOL_STR(prepare_to_wait_event) },
	{ 0x4f68e5c9, __VMLINUX_SYMBOL_STR(do_gettimeofday) },
	{ 0x1b6cfa4d, __VMLINUX_SYMBOL_STR(proc_create_data) },
	{ 0x167c7cdb, __VMLINUX_SYMBOL_STR(seq_lseek) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x9d669763, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x875effe6, __VMLINUX_SYMBOL_STR(param_array_ops) },
	{ 0x1a2c2b03, __VMLINUX_SYMBOL_STR(usb_register_driver) },
	{ 0x9b31d010, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0x1cfb04fa, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0xdf53f73b, __VMLINUX_SYMBOL_STR(sysfs_add_file_to_group) },
	{ 0xb81960ca, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0x99bb8806, __VMLINUX_SYMBOL_STR(memmove) },
	{ 0xa3bcbe47, __VMLINUX_SYMBOL_STR(param_ops_ushort) },
	{ 0xccaa1010, __VMLINUX_SYMBOL_STR(param_ops_uint) },
	{ 0x55982017, __VMLINUX_SYMBOL_STR(__class_create) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("usb:v0C72p000Cd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C72p000Dd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C72p0012d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C72p0011d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C72p0013d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C72p0014d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "6C8192D768DF5A681769259");
