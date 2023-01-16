
#include <linux/module.h>
#include <linux.kernel.h>
#include <linux/init.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Hitesh");
MODULE_DESCRIPTION("Task struct reading module");
printk(KERN_INFO "Hello this");
printk(KERN_INFO "is our ");
printk(KERN_INFO "program");
 
int device_init(void)
{
    struct task_struct *TASK = current; 
    printk(KERN_INFO "assignment: current process: %s", TASK->comm);
    printk(KERN_INFO " PID: %d", TASK->pid);

    do
    {
        TASK = TASK->parent;
        printk(KERN_INFO "assignment: parent process: %s", TASK->comm);
        printk(KERN_INFO " PID: %d", TASK->pid);

    } while (TASK->pid != 0);
    return 0;
}
module_init(device_init);
 
void device_exit(void) {
    printk(KERN_INFO "Finally our program");
    printk(KERN_INFO "assignment: exiting module");
}

module_exit(device_exit);
