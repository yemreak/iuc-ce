#define __KERNEL__
#define MODULE
/*include the head file involved in the project*/
#if defined(MODVERSIONS)
#include <linux/modversions.h>
#endif
#include <asm/types.h>
#include <asm/atomic.h>
#include <asm/uaccess.h>
#include <asm/signal.h>
#include <asm/unistd.h>
#include <asm/semaphore.h>

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/skbuff.h> 
#include <linux/init.h>
#include <linux/timer.h>
#include <linux/list.h>
#include <linux/types.h>
#include <linux/netdevice.h>
#include <linux/config.h>
#include <linux/random.h>
#include <linux/spinlock.h>
#include <linux/ip.h>
#include <linux/tcp.h>
#include <linux/inet.h>
#include <linux/udp.h>
#include <linux/netfilter_ipv4.h>
#include <linux/utsname.h>
#include <linux/in.h>
#include <linux/if.h>
#include <linux/netdevice.h>
#include <linux/if_arp.h>
#include <linux/fs.h>
#include <linux/string.h>
#include <linux/errno.h>
#include <linux/sched.h>
#include <linux/smp_lock.h>
#include <linux/vmalloc.h>
#include <linux/un.h>
#include <linux/unistd.h>
#include <linux/wrapper.h>
#include <linux/wait.h>
#include <linux/ctype.h>
#include <linux/igmp.h> 
#define TDD_WRITE 0
#define TDD_READ 1
#define FALSE 0
#define TRUE 1
#define MAX_BUF 120
#define TDD_TRON (('M'<<0)|0x01)
#define TDD_TROFF (('M'<<0)|0x02)
struct tdd_buf{
 int buf_size;
 char buffer[MAX_BUF];
 struct tdd_buf * link;
};
#define MAJORDEVICE 30
static int tdd_trace;
static int write_busy;
static int read_busy;
static struct tdd_buf *qhead;
static struct tdd_buf *qtail;
static size_t tdd_read(struct file *, char *, size_t, loff_t * );
static size_t tdd_write(struct file *, const char *, size_t, loff_t * );
static int tdd_ioctl(struct inode *, struct file *, unsigned int, unsigned long );
static int tdd_open(struct inode *, struct file * );
static int tdd_release( struct inode *, struct file * );
struct file_operations tdd_fops={ 
 read: tdd_read,
 write: tdd_write,
 ioctl: tdd_ioctl,
 open: tdd_open,
 release: tdd_release,
};
void tdd_init( void )
{
 if ( register_chrdev( MAJORDEVICE, "tdd", &tdd_fops) )
 printk( "Can not register tdd driver as Major Device 30\n" );
 else
 printk( "Tiny device dirver registered successfully.\n" );
 qhead = NULL;
 write_busy = FALSE;
 read_busy = FALSE;
 return;
}
void tdd_uninstall(void)
{
 unregister_chrdev( MAJORDEVICE, "tdd" );
 qhead = NULL;
 write_busy = FALSE;
 read_busy = FALSE;
 return;
}
int init_module( void ) 
{
 printk( "initializing...." );
 tdd_init();
 return 0;
}
void cleanup_module( void )
{
 tdd_uninstall();
 printk( "Bye bye...\n\n\n" );
}
static int tdd_open(struct inode * inode, struct file * file)
{
 printk( "tdd_open" );
 switch( MINOR( inode-> i_rdev ) ){
 case TDD_WRITE:
 if( write_busy )
 return -EBUSY;
 else
 write_busy = TRUE;
 return 0;
 case TDD_READ:
 if( read_busy )
 return -EBUSY;
 else
 read_busy = FALSE;
 return 0;
 default: 
 return -ENXIO;
 }
}
static int tdd_release( struct inode * inode, struct file * file)
{
 printk( "tdd_release\n" );
 switch( MINOR(inode->i_rdev) ){
 case TDD_WRITE:
 write_busy = FALSE;
 return 0;
 case TDD_READ:
 read_busy = FALSE;
 return 0;
 }
 return 0;
}
static size_t tdd_write(struct file * file, const char *buffer, size_t count, loff_t
*offset)
{
 int len;
 struct tdd_buf *ptr;
 printk( "tdd_write\n" );
 if ( (ptr=kmalloc( sizeof(struct tdd_buf), GFP_KERNEL) ) == NULL )
 return -ENOMEM; 
 len = count<MAX_BUF?count:MAX_BUF;
 if ( copy_from_user( (void*)(ptr->buffer), (void*)buffer, len ) != 0 ){
 printk( "Copy from user Error!\n" );
 return -ENOMEM;
 }
 printk( "W" );
 ptr->link = NULL;
 if( qhead == NULL )
 qhead = ptr;
 else
 qtail -> link = ptr;
 qtail = ptr;
 printk( "\n" );
 ptr->buf_size = len;
 return len;
}
static size_t tdd_read(struct file * file, char * buffer, size_t count, loff_t * offset)
{
 int len;
 struct tdd_buf *ptr;
 char buffer[100];
 printk( "tdd_read\n" ); 
 if (qhead == NULL)
 return -ENODATA;
 ptr = qhead;
 qhead = qhead->link;

 len = count<ptr->buf_size?count:ptr->buf_size;
 if ( copy_to_user( (void*)buffer, (void*)(ptr->buffer), len ) != 0 ){
 printk( "Copy to User Error!\n" );
 return -1;
 }
 kfree( ptr );
 return len;
}
static int tdd_ioctl(struct inode * inode, struct file * file, unsigned int cmd,
unsigned long arg)
{
 printk( "tdd_ioctl\n" );
 switch( cmd ){
 case TDD_TRON:
 tdd_trace = TRUE;
 return 0;
 case TDD_TROFF:
 tdd_trace = FALSE; 
 return 0;
 default:
 return -EINVAL;
 }
}