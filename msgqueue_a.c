#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

typedef struct msgbuf{
	long mtype;
	char mtext[256];
}msgbuf_t;

int main(void){
	key_t key;
	msgbuf_t mb;//消息类型的变量
	//获取key值
	key=ftok("hello",31);
	if(key==-1){
		perror("ftok");
		return 1;
	}
	//获取消息队列的id
	int msqid=msgget(key,IPC_CREAT|0664);
	if(msqid==-1){
		perror("msgget");
		return 2;
	}
	//初始化消息
	mb.mtype=3;/*must be >0*/
	strcpy(mb.mtext,"this is test\n");
	//向消息队列中写入消息
	int s=msgsnd(msqid,&mb,strlen(mb.mtext)+1,0);
	if(s==-1){
		perror("msgsnd");
		return 3;
	}
	return 0;
}