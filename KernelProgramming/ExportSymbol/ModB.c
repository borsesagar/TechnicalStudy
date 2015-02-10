#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
void  ExportFunction(void);

static int modB_init(void)
{
	printk(KERN_INFO "ModB init done\n");
	ExportFunction();
	return 0;
}


static void modB_exit(void)
{
	printk(KERN_INFO "ModB exiting\n");
	
}

module_init(modB_init);
module_exit(modB_exit);

