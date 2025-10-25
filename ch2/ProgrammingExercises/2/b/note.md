# Kernel Data Structures -- Circular Doubly Linked List

The Linux kernel provides several data structures. The circular double linked list is one of them available to kernel developers.
For the simple linked list, the `list_head` structure is used which is available in the `<linux/types.h>` header file. Its
definition if somewhat like follows:

```C
struct list_head {
	struct list_head *next, *prev;
};
```

So, according to the exercise, we are given a structure called `birthday` which is defined as:

```C
struct birthday {
	int day;
	int month;
	int year;
	struct list_head list;
};
```

## Inserting an element into the linked list

We can define a `list_head` object which we can use as a reference to the head of the list. This can be done as follows:

```C
LIST_HEAD(birthday_list);
```

`LIST_HEAD()` is a macro which is defined as follows:

```C
LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)
```

The `LIST_HEAD_INIT()` macro is defined as:

```C
LIST_HEAD_INIT(name) {&(name), &(name)}
```

Both of these macros can be found <a href="https://elixir.bootlin.com/linux/v6.17.5/source/include/linux/list.h#L23">here</a>.
So, if I were to write it in simple plain C code without any macros, then it would look like this:

```C
struct list_head birthday_list = {&birthday_list, &birthday_list};
```

So, essentially this is happening with `birthday_list`:

<img src="https://github.com/chaotic-Coder2002/Learning_OS/blob/OS/ch2/ProgrammingExercises/2/b/images/ListNode.jpg" width="60%" height="60%">

After this, we have the `INIT_LIST_HEAD()` which takes in a pointer to `struct list_head`. Although its proper definition is shown <a href="https://elixir.bootlin.com/linux/v6.17.5/source/include/linux/list.h#L35">here</a>, but this is how I interpreted it (I may be wrong):

```C
static inline void INIT_LIST_HEAD(struct list_head *list) {
	list->prev = list;
	list->next = list;
}
```
This function basically initializes the `list_head` object/variable to point to itself.

The `kmalloc()` is the kernel-level equivalent of the user-level `malloc()` or `calloc()`. However, its job is the same as that of `malloc()`/`calloc()` except that it allocates "kernel memory".
It uses a flag <a href="https://www.emblogic.com/blog/08/gfp_kernel/"><code>GFP_KERNEL</code></a>.

Let's look at a snippet from <a href="https://github.com/chaotic-Coder2002/Learning_OS/blob/OS/ch2/ProgrammingExercises/2/b/simple.c">simple.c</a>:

```C
person = kmalloc(sizeof(struct birthday), GFP_KERNEL);

person->day = 18;
person->month = 11;
person->year = 1969;
INIT_LIST_HEAD(&person->list); // we already know this

list_add_tail(&person->list, &birthday_list);
```

The definition of `list_add_tail()` is shown <a href="https://elixir.bootlin.com/linux/v6.17.5/source/include/linux/list.h#L181">here</a>. It basically calls the inline function `__list_add()` with the following parameters:

```C
__list_add(new, head->prev, head);
```

The definition of `__list_add()` as given <a href="https://elixir.bootlin.com/linux/v6.17.5/source/include/linux/list.h#L146">here</a>, if I remove that `if()` conditional check, is:

```C
static inline void __list_add(struct list_head *new,
				struct list_head *prev,
				struct list_head *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}
```

The images below show the progress of the connection between the two nodes i.e. the head node and the new `list_head` node:

<img src="https://github.com/chaotic-Coder2002/Learning_OS/blob/OS/ch2/ProgrammingExercises/2/b/images/birthday_list.jpg" width="60%" height="60%">

<img src="https://github.com/chaotic-Coder2002/Learning_OS/blob/OS/ch2/ProgrammingExercises/2/b/images/birthday_struct_member_list.jpg" width="60%" height="60%">

<img src="https://github.com/chaotic-Coder2002/Learning_OS/blob/OS/ch2/ProgrammingExercises/2/b/images/connection.jpg" width="60%" height="60%">

So basically any new node is inserted between the head node and the last node.

For example, just to simplify, let's say we have two nodes: `<-Head->` and `<-5->`, the arrows represent `next`(`<-`) and `prev`(`->`) respectively.

Right now, `<-Head` is `5` and `5->` is `Head`. Basically the linked list looks like this: `...<-Head-><-5->...` the `...` represent that it's a circular list and `Head` and `5` point to each other

Now, if I want to add a number `4` into this list, then it will inserted as:
```
Head-> = 4
<-4 = Head
4-> = 5 (because 5 is Head->) and
<-5 = 4
```

So our circular linked list is: `...<-Head-><-4-><-5->...`.

Again, let's say I want to add a node `10`, so it will inserted as:

```
Head-> = 10
<-10 = Head
10-> = 4 (which is basically Head->) and
<-4 = 10
```

So our circular linked list is: `...<-Head-><-10-><-4-><-5->...`.

## Traversing the linked list

To traverse the list, the `list_for_each_entry()` macro is used. It contains an `for` loop. It's definition is provided <a href="https://elixir.bootlin.com/linux/v6.17.5/source/include/linux/list.h#L764">here</a>.
In the program it's called as:

```C
struct birthday *ptr;

list_for_each_entry(ptr, &birthday_list, list)
	printk(KERN_INFO "[%d/%d/%d]", ptr->day, ptr->month, ptr->year);
```

The pointer `ptr` is used as an iterator that will be used to iterate through the list.

The `for` loop in `list_for_each_entry()` is like this:

```C
for (pos = list_first_entry(head, typeof(*pos), member);\
	!list_entry_is_head(pos, head, member);		\
	pos = list_next_entry(pos, member))
```

The macro `list_first_entry()` is defined <a href="https://elixir.bootlin.com/linux/v6.17.5/source/include/linux/list.h#L604">here</a>. It's second argument is the <a href="https://www.oracle.com/solaris/technologies/c-type.html"><code>typeof()</code></a> operator. Basically
the type of `*pos` is sent as a second parameter which is `struct birthday`.

Now, the `list_first_entry()` macro calls another macro <a href="https://elixir.bootlin.com/linux/v6.17.5/source/include/linux/list.h#L595"><code>list_entry()</code></a>:

```C
list_entry((ptr)->next, type, member) // ptr is actually the head.
```

This macro uses a macro called `container_of()` to cast a member of a structure out to the containing structure.

In simple terms, consider the previously assumed circular linked list: `...<-Head-><-10-><-4-><-5->...`.

If we are to print it, then it will be printed as follows:

```
5
4
10
```

Because, we do a `<-Head` (move to the node next to `Head` which will take us to the last node i.e. `5`).


# Resources

Resources in order:

<ol>
<li><a href="https://elixir.bootlin.com/linux/v6.17.5/source/include/linux/list.h#L764">https://elixir.bootlin.com/linux/v6.17.5/source/include/linux/list.h#L764</a>.</li>
<li><a href="https://elixir.bootlin.com/linux/v6.17.5/source/include/linux/list.h#L604">https://elixir.bootlin.com/linux/v6.17.5/source/include/linux/list.h#L604</a>.</li>
<li><a href="https://elixir.bootlin.com/linux/v6.17.5/source/include/linux/list.h#L595">https://elixir.bootlin.com/linux/v6.17.5/source/include/linux/list.h#L595</a>.</li>
<li><a href="https://elixir.bootlin.com/linux/v6.17.5/source/tools/include/linux/container_of.h#L7">https://elixir.bootlin.com/linux/v6.17.5/source/tools/include/linux/container_of.h#L7</a>.</li>
<li><a href="https://elixir.bootlin.com/linux/v6.17.5/source/drivers/gpu/drm/radeon/mkregtable.c#L20">https://elixir.bootlin.com/linux/v6.17.5/source/drivers/gpu/drm/radeon/mkregtable.c#L20</a>.</li>
<li><a href="https://elixir.bootlin.com/linux/v6.17.5/source/include/linux/list.h#L639">https://elixir.bootlin.com/linux/v6.17.5/source/include/linux/list.h#L639</a>.</li>
<li><a href="https://stackoverflow.com/a/65236136">https://stackoverflow.com/a/65236136</a>.</li>
</ol>

---
