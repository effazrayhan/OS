#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int sum;
void *runner(void *param);

int main(int argc , char *argv[]){
	pthread_t tid1;
	pthread_t tid2;
	pthread_attr_t attr;
	
	pthread_attr_init(&attr);
	if(pthread_create(&tid1,&attr,runner,argv[1]) != 0){
		printf("Failed to create thread!");
	}
	if(pthread_create(&tid2,&attr,runner,argv[2]) != 0){
		printf("Failed to create thread!");
	}
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	
	printf("%d\n",sum);
}
void *runner(void *param){
	int in = atoi(param);
	if(in < 5) in *= 10;
	else in *= 2;
	sum = 0;
	sum += in;
	pthread_exit(0);
}
