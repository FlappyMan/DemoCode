#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(void)
{
    int i;
    pid_t pid;

    //APUE详解

    //为什么父进程返回值大于0而子进程返回0？
    /*  tip1
    **将子进程ID返回给父进程的理由：因为一个进程可以有多个子进程，并且没有一个函数可以获得其所有子进程的进程ID
    **fork使子进程得到返回0的理由是：一个进程只会有一个父进程，所以子进程总是可以
    **调用geppid获得其父进程的ID（进程ID为0总是由内核交换进程使用，所以一个子进程
    **的进程ID不可能为0）
    */

    /*  tip2
    *子进程和父进程继续执行fork调用之后的指令。子进程是父进程的副本。例如，子进程
    **获得了父进程的数据空间，堆和栈的副本。注意，这是子进程所拥有的副本。父进程
    **和子进程并不共享这些存储空间部分。父进程和子进程共享正文段。
    */

    /*  tip3
    *fork后经常跟随exec，所以现在的很多实现并不执行一个父进程的数据段，栈和堆的完全
    **副本。作为替代，使用了写时复制技术。这些区域又父进程和子进程共享，而且内核将他们
    **的权限改变为只读。如果父进程和子进程中的任一个试图修改这些区域，则内核只为修改区域
    **那块内存制作一个副本，通常是虚拟存储系统中的”一页“。

    /*  tip4
    **一般来说，在fork之后是父进程先执行还是子进程先执行是不确定的，这取决于内核
    **所使用的调度算法。如果要求父进程和子进程之间相互同步，则要求某种形式的进程间
    **通信。
    */

    char tmp[] = "hello world";
    
    //for(i = 0;i<2;i++)
    {
        pid = fork();
        if(pid==0)
        {
            printf("son %d\n",getpid());
            tmp[2] = '6';
        }else if(pid>0){
            printf("parent %d %d %d\n",pid,getppid(),getpid());
            tmp[2] = '7';
        }
    }
    printf("tmp %s\n",tmp);

    return 0;
}