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
	//从消息队列中获取消息
	int s=msgrcv(msqid,&mb,256,3,0);
	if(s==-1){
		perror("msgrcv");
		return 3;
	}
	printf("%s",mb.mtext);
	return 0;
}