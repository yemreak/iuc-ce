#include <linux/module.h> /* Specifically, a module */
#include <linux/kernel.h> /* We're doing kernel work */
#include <linux/proc_fs.h> /* Necessary because we use the proc fs */
#define procfs_name "procworld"
struct proc_dir_entry *Our_Proc_File;
int procfile_read(char *buffer,char **buffer_location,off_t offset, int buffer_length, int *eof, void *data)
{
	int ret;
	printk(KERN_INFO "procfile_read (/proc/%s) called\n", procfs_name);
	if (offset > 0) {
	/* we have finished to read, return 0 */
	ret = 0;
	} else {
	/* fill the buffer, return the buffer size */
	ret = sprintf(buffer, "Proc HelloWorld!\n");
	}
	return ret;
}
int init_module()
{
	Our_Proc_File = create_proc_entry(procfs_name, 0644, NULL);
	if (Our_Proc_File == NULL) {
	remove_proc_entry(procfs_name, &proc_root);
	printk(KERN_ALERT "Error: Could not initialize /proc/%s\n",
	procfs_name);
	return −ENOMEM;
	}
	Our_Proc_File−>read_proc = procfile_read;
	Our_Proc_File−>owner = THIS_MODULE;
	Our_Proc_File−>mode = S_IFREG | S_IRUGO;
	Our_Proc_File−>uid = 0;
	Our_Proc_File−>gid = 0;
	Our_Proc_File−>size = 37;
	printk(KERN_INFO "/proc/%s created\n", procfs_name);
	return 0; /* everything is ok */
}
void exit_module()
{
	remove_proc_entry(procfs_name, &proc_root);
	printk(KERN_INFO "/proc/%s removed\n", procfs_name);
}

