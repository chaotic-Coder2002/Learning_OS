# Creating a very simple kernel module

To view all the kernel modules that are currently loaded, use the `lsmod` command. This command will list the current kernel modules in three columns: name, size and where the module is being used. I wrote the <a href="https://github.com/chaotic-Coder2002/Learning_OS/blob/OS/ch2/ProgrammingExercises/2/a/simple.c">simple.c</a> from the book and the `Makefile` was copied from <a href="https://github.com/greggagne/osc10e/blob/master/ch2/Makefile">here</a>.

After, that I compiled my program by using the `make` command. Once it was done, I loaded the module using the `insmod` command as follows (as mentioned in the book):

```bash
$ sudo insmod simple.ko
```

Next, to make sure that the module was loaded, I used the following command:

```bash
$ lsmod | grep simple
simple                 12288  0
```

After this, I used the `dmesg` command:

```bash
$ sudo dmesg
[ 2762.421824] Loading Module
```

Next, I removed the module by using the `rmmod` command:

```bash
$ sudo rmmod simple
```

After this I made sure that the module was removed by using the `lsmod` command again:

```bash
$ lsmod | grep simple
```

Once this was done, I used the `dmesg` command to view the output of the unloaded module:

```bash
$ sudo dmesg
[ 2762.421824] Loading Module
[ 2778.476718] Removing Module
```

The `printk()` function is the kernel equivalent of `printf()`, but the only difference is that its output is sent to the kernel log buffer whose contents can be read by the `dmesg` command. Another difference is that `printk()` allows us to specify a priority flag whose values are given in the `<linux/printk.h>` include file. In case of `simple.c`, the priority is `KERN_INFO`, which is defined as an *informational* message.

---
