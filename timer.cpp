#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
#include<time.h>

using namespace std;
static int cnt = 0;
pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;
void* resetIncNum(void* args)
{
start:
	time_t start, end;
	start = time(NULL);
	uint64_t totaltime = 0;
	while (1)
	{
		end = time(NULL);
		totaltime = (end - start);
		if (totaltime > 2)
		{
			pthread_mutex_lock(&mutex);
			cnt = 0;
			pthread_mutex_unlock(&mutex);
			goto start;
		}
	}
	return NULL;
}


void *fun2(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);
		++cnt;
		pthread_mutex_unlock(&mutex);
		cout<<"fun2 cnt = "<<cnt<<endl;
		//usleep(10000);
	}
}

int main()
{
	int ret;
	pthread_t tid1,tid2;
	pthread_create(&tid1,NULL,resetIncNum,NULL);
	pthread_create(&tid2,NULL,fun2,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	return 0;
}
