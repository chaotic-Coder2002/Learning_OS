#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>

/* This function is called when the module is loaded */
int simple_init(void) { // this is the module entry point
	printk(KERN_INFO "Loading Module\n");
	return 0;
}

/* This function is called when the module is removed */
void simple_exit(void) { // this is the module exit point
	printk(KERN_INFO "Removing Module\n");
}

module_init(simple_init); // module_init() is the module entry point function
module_exit(simple_exit); // module_exit() is the module exit point function

/* These basicalyy represent details regarding the software license, description of the module and the author. These are not mandatory to include but are
   included because it is standard practice in developing kernel modules. */
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");
