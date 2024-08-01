#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
int main(int argc,char * argv[]){
int id,wt;
id=fork();
if(id==0){
printf("HI I am child ,my pid is %d\n",getpid());
printf("child: my parent pid is %d\n",getppid());
execl("./fibinocci","fibinocci",argv[1],NULL);
exit(34);
}

else if(id>0){
wait(&wt);
printf("\nHI I am parent ,my pid is %d \n",getpid());
printf("parent: my parent pid is %d\n",getppid());
if (WIFEXITED(wt)){
printf("the child has terminated normally and exit status is %d\n",WEXITSTATUS(wt));
}
else if(WIFSIGNALED(wt)){
printf("the child has terminated abnormally  and is jkilled by signaled %d\n",WTERMSIG(wt));
}
}
}
