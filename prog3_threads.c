#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

int i;
void * print(void *i){
int *j =(int *)i;
printf("HI I am thread %d \n",*j);
}

int main(){
pthread_t tid[3];
for (i=0;i<3;i++){
pthread_create(&tid[i],NULL,print,(void *)&i);sleep(1);
}

for (i=0;i<3;i++){
pthread_join(tid[i],NULL);
}
}
