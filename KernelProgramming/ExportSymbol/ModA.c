#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");

static int modA_init(void)
{
	printk(KERN_INFO "ModA init done\n");
	return 0;
}

static void ExportFunction(void)
{
	printk(KERN_INFO "ModA exporting ExportFunction()\n");
}

static void modA_exit(void)
{
	printk(KERN_INFO "ModA Exiting\n");
}

EXPORT_SYMBOL(ExportFunction);
module_init(modA_init);
module_exit(modA_exit);
