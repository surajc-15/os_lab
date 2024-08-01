#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/types.h>
#include<unistd.h>

#define BUF_SIZE 8192
int main(int argc,char * argv[]){
int input_fd,output_fd;   //descriptors
ssize_t ret_in,ret_out;       //no of byte returned by read and write

char buffer[BUF_SIZE];

//check the valid argumetns two  input
if(argc!=3){
printf("usage:cp file1 file2");
return 1;
}

//create input file descriptor
input_fd=open(argv[1],O_RDONLY);
if(input_fd==-1){
perror("open");
return 2;}

//create ouptfile descriptor
output_fd=open(argv[2],O_WRONLY | O_CREAT,0666);
if(output_fd==-1){
perror("open");
return 3;
}

//copy process
while((ret_in=read(input_fd,&buffer,BUF_SIZE)) >0){
ret_out=write(output_fd,&buffer,(ssize_t ) ret_in);
if(ret_out!=ret_in){
perror("write");
return 4;
}

}

close(input_fd);
close(output_fd);
}



