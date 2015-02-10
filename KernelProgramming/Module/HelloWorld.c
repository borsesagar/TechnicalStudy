#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/moduleparam.h>
#include <linux/stat.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("SAGAR BORSE");
MODULE_DESCRIPTION("Its a sample module");



int myEmp = 50886;
module_param(myEmp, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP); //param1- name, param2- type, param3- permission 
MODULE_PARM_DESC(myEmp, "Employee ID");

char *myName = "Sagar";
module_param(myName, charp, 0);
MODULE_PARM_DESC(myName, "First Name");

int myArr[3] = {-1, 0, 1};
int count = 3;
module_param_array(myArr, int, &count, 0); 

static int __init hello_init_module(void)
{
	int i = 0;
	printk(KERN_ALERT "Hello World\n\n\n");
	printk(KERN_INFO "First Name Entered: %s", myName);
	printk(KERN_ALERT "Employee ID : %d\n", myEmp);
	printk(KERN_INFO "Array\n");
	for (i = 0; i <= 2; i++)
	{ 
		printk(KERN_ALERT "Arr[%d]\n", i);
		printk(KERN_INFO "%d\n", myArr[i]);
	}

	return 0;
}

static void __exit hello_exit_module (void)
{
	printk(KERN_ALERT "Good Bye World!!\n");
}


module_init(hello_init_module);
module_exit(hello_exit_module);
