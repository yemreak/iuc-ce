#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/string.h>
#include <linux/vmalloc.h>
#include <asm/uaccess.h>

#define MAX_LEN       4096
int read_info( char *page, char **start, off_t off,int count, int *eof, void *data );
ssize_t write_info( struct file *filp, const char __user *buff,unsigned long len, void *data );

static struct proc_dir_entry *proc_entry;
static char *info;
static int write_index;
static int read_index;

int init_module( void )
{
    int ret = 0;
    info = (char *)vmalloc( MAX_LEN );
    memset( info, 0, MAX_LEN );
    proc_entry = create_proc_entry( "procEntry123", 0644, NULL );

    if (proc_entry == NULL)
    {
        ret = -1;
        vfree(info);
        printk(KERN_INFO "procEntry123 could not be created\n");
    }
    else
    {
        write_index = 0;
        read_index = 0;
        proc_entry->read_proc = read_info;
        proc_entry->write_proc = write_info;
        printk(KERN_INFO "procEntry123 created.\n");
    }

    return ret;
}

void cleanup_module( void )
{
    remove_proc_entry("procEntry123", proc_entry);
    printk(KERN_INFO "procEntry123 unloaded.\n");
    vfree(info);
}

ssize_t write_info( struct file *filp, const char __user *buff, unsigned long len, void *data )
{
    int capacity = (MAX_LEN-write_index)+1;
    if (len > capacity)
    {
        printk(KERN_INFO "No space to write in procEntry123!\n");
        return -1;
    }
    if (copy_from_user( &info[write_index], buff, len ))
    {
        return -2;
    }

    write_index += len;
    info[write_index-1] = 0;
    return len;
}

int read_info( char *page, char **start, off_t off, int count, int *eof, void *data )
{
    int len;
    if (off > 0)
    {
        *eof = 1;
        return 0;
    }

    if (read_index >= write_index)
    read_index = 0;

    len = sprintf(page, "%s\n", &info[read_index]);
    read_index += len;
    return len;
}

/*
$ cat Makefile
obj-m += proc.o
all:
        sudo make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
        sudo make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
		
$ make
sudo make -C /lib/modules/2.6.32-21-generic/build M=/home/himanshu modules
make: Entering directory `/usr/src/linux-headers-2.6.32-21-generic'
CC [M]  /home/himanshu/proc.o
/home/himanshu/proc.c: In function ‘init_module’:
/home/himanshu/proc.c:33: warning: assignment from incompatible pointer type
Building modules, stage 2.
MODPOST 1 modules
LD [M]  /home/himanshu/proc.ko
make: Leaving directory `/usr/src/linux-headers-2.6.32-21-generic'

$ sudo insmod proc.ko

And after inserting if we see the proc directory, we find an entry ‘procEntry123’

$ ls /proc/procEntry123
/proc/procEntry123
Now, if we try to write and read from it :

$ echo "TGS" > /proc/procEntry123
$ cat /proc/procEntry123
TGS

In the code above :

In the init_module function we used the ‘create_proc_entry’ function to create a proc file named ‘procEntry123’
The file is created with suitable privileges as described by the second argument to the create_proc_entry function.
Two functions read_info and write_info are used when the proc file is read and written.
The address of these two functions is assigned to members of proc_dir_entry structure.
The above step was done in order for the code to know which function to call when the proc file is read and written.
In the write_info function, if there is capacity to write in the buffer, the function copy_from_user is used to copy the string from user space to the kernel module allocated memory buffer.
In the function read_info, the information present in buffer is send back to the user space.
		
		
		
		*/