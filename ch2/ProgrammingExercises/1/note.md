# Using `strace`

After writing and compiling <a href="https://github.com/chaotic-Coder2002/Learning_OS/blob/OS/ch2/ProgrammingExercises/1/copy.c">copy.c</a>, I ran the `strace` command as follows:

```bash
$ gcc -g copy.c -o run
$ strace ./run
```

And the output was a bunch of system calls, as shown below:

```bash
execve("./run", ["./run"], 0x7ffc35da8b50 /* 59 vars */) = 0
brk(NULL)                               = 0x5868daf1f000
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7ae4b622f000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=78295, ...}) = 0
mmap(NULL, 78295, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7ae4b621b000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\220\243\2\0\0\0\0\0"..., 832) = 832
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
fstat(3, {st_mode=S_IFREG|0755, st_size=2125328, ...}) = 0
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
mmap(NULL, 2170256, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7ae4b6000000
mmap(0x7ae4b6028000, 1605632, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x28000) = 0x7ae4b6028000
mmap(0x7ae4b61b0000, 323584, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1b0000) = 0x7ae4b61b0000
mmap(0x7ae4b61ff000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1fe000) = 0x7ae4b61ff000
mmap(0x7ae4b6205000, 52624, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7ae4b6205000
close(3)                                = 0
mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7ae4b6218000
arch_prctl(ARCH_SET_FS, 0x7ae4b6218740) = 0
set_tid_address(0x7ae4b6218a10)         = 5475
set_robust_list(0x7ae4b6218a20, 24)     = 0
rseq(0x7ae4b6219060, 0x20, 0, 0x53053053) = 0
mprotect(0x7ae4b61ff000, 16384, PROT_READ) = 0
mprotect(0x5868d009e000, 4096, PROT_READ) = 0
mprotect(0x7ae4b6267000, 8192, PROT_READ) = 0
prlimit64(0, RLIMIT_STACK, NULL, {rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
munmap(0x7ae4b621b000, 78295)           = 0
fstat(1, {st_mode=S_IFCHR|0620, st_rdev=makedev(0x88, 0x1), ...}) = 0
getrandom("\xfb\x3f\x71\x5f\x6a\xae\xf8\x70", 8, GRND_NONBLOCK) = 8
brk(NULL)                               = 0x5868daf1f000
brk(0x5868daf40000)                     = 0x5868daf40000
fstat(0, {st_mode=S_IFCHR|0620, st_rdev=makedev(0x88, 0x1), ...}) = 0
write(1, "Enter source file: ", 19Enter source file: )     = 19
read(0, a.txt
"a.txt\n", 1024)                = 6
write(1, "Enter destination file: ", 24Enter destination file: ) = 24
read(0, b.txt
"b.txt\n", 1024)                = 6
openat(AT_FDCWD, "a.txt", O_RDONLY)     = 3
openat(AT_FDCWD, "b.txt", O_WRONLY|O_CREAT|O_TRUNC, 0666) = 4
fstat(3, {st_mode=S_IFREG|0664, st_size=63, ...}) = 0
read(3, "Hello world! This is C programmi"..., 4096) = 63
fstat(4, {st_mode=S_IFREG|0664, st_size=0, ...}) = 0
read(3, "", 4096)                       = 0
close(3)                                = 0
write(4, "Hello world! This is C programmi"..., 63) = 63
close(4)                                = 0
lseek(0, -1, SEEK_CUR)                  = -1 ESPIPE (Illegal seek)
exit_group(0)                           = ?
+++ exited with 0 +++
```


---
