#include<linux/init.h>
#include<linux/types.h> // for struct list_head
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/list.h> // for the macro LIST_HEAD() and the function INIT_LIST_HEAD() and the list_head functions

/*
   struct list_head {
   	struct list_head *next, *prev;
   };
 */

struct birthday {
	int day;
	int month;
	int year;
	struct list_head list;
};

LIST_HEAD(birthday_list); // birthday_list is now the reference to the head of the list

/* This function is called when the module is loaded */
int simple_init(void) { // this is the module entry point
	printk(KERN_INFO "Loading Module\n");
	//struct list_head birthday_list;

	struct birthday *person;

	person = kmalloc(sizeof(struct birthday), GFP_KERNEL); // kernel equivalent of user-level malloc()/calloc()
	person->day = 19;
	person->month = 2;
	person->year = 2002;
	INIT_LIST_HEAD(&person->list);

	// add the list_head struct member in `person` to the end of the list
	list_add_tail(&person->list, &birthday_list);

	struct birthday *ptr; /* ptr will be used as a loop cursor, that is sort of like an iterator,
				 to iterate through the list */

	person = kmalloc(sizeof(struct birthday), GFP_KERNEL);

	person->day = 21;
	person->month = 11;
	person->year = 2012;
	INIT_LIST_HEAD(&person->list);

	list_add_tail(&person->list, &birthday_list);

	person = kmalloc(sizeof(struct birthday), GFP_KERNEL);

	person->day = 18;
	person->month = 11;
	person->year = 1972;
	INIT_LIST_HEAD(&person->list);

	list_add_tail(&person->list, &birthday_list);

	person = kmalloc(sizeof(struct birthday), GFP_KERNEL);

	person->day = 18;
	person->month = 11;
	person->year = 1969;
	INIT_LIST_HEAD(&person->list);

	list_add_tail(&person->list, &birthday_list);

	list_for_each_entry(ptr, &birthday_list, list)
		printk(KERN_INFO "[%d/%d/%d]", ptr->day, ptr->month, ptr->year);

	return 0;
}

/* This function is called when the module is removed */
void simple_exit(void) { // this is the module exit point
	printk(KERN_INFO "Removing Module\n");
	struct birthday *ptr, *next;
	list_for_each_entry_safe(ptr, next, &birthday_list, list) {
		printk(KERN_INFO "Removing.. %d\n", ptr->year);
		list_del(&ptr->list);
		kfree(ptr); // kernel-equivalent of user-level free()
	}
}

module_init(simple_init); // module_init() is the module entry point function
module_exit(simple_exit); // module_exit() is the module exit point function

/* These basically represent details regarding the software license, description of the module and the author. These are not mandatory to include but are
   included because it is standard practice in developing kernel modules. */
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");
