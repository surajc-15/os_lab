#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>

#define buffersize 10
pthread_mutex_t mutex;
pthread_t tidP[20],tidC[20];
sem_t full,empty;
int counter;
int buffer[buffersize];

void initialize()
{
pthread_mutex_init(&mutex,NULL);
sem_init(&full,1,0);
sem_init(&empty,1,buffersize);
counter=0;
}

void write(int item){
buffer[counter++]=item;
}

int read(){
return buffer[--counter];
}

void * producer(void *param)
{
int waittime,item,i;
item=rand()%5;
waittime=rand()%5;
sem_wait(&empty);
pthread_mutex_lock(&mutex);
printf("\n Producer has produced item %d\n",item);
write(item);
pthread_mutex_unlock(&mutex);
sem_post(&full);
}


void * consumer(void *param){
int waittime,item;
waittime=rand()%5;
sem_wait(&full);
pthread_mutex_lock(&mutex);
item=read();
printf("\n consumer has consumer item %d \n",item);
pthread_mutex_unlock(&mutex);
sem_post(&empty);
}

int main(){
int n1,n2,i;
initialize();
printf("enter the no of produce process");
scanf("%d",&n1);
printf("enter the no of consumer processs:");
scanf("%d",&n2);

for(i=0;i<n1;i++){
pthread_create(&tidP[i],NULL,producer,NULL);
pthread_join(tidP[i],NULL);}

for(i=0;i<n2;i++){
pthread_create(&tidC[i],NULL,consumer,NULL);
pthread_join(tidC[i],NULL);}

//for(i=0;i<n1;i++)


//for(i=0;i<n2;i++)



//sleep(5);
exit(0);
}

























