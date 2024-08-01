#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
int main(int argc,char* argv[]){
int input_fd,output_fd;

//argement check

if(argc!=3){
printf("usage:mv src dest");
return 1;
}

//create input file desciptor
input_fd=link(argv[1],argv[2]);
if(input_fd==-1){
perror("link");
return 2;
}

//create ouput file descriptor
output_fd=unlink(argv[1]);
if(output_fd==-1){
perror("unlink");
return 3;
}

}
