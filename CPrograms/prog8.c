#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	pid_t pid;
	
	pid = fork();
	if(pid < 0){
		printf("Error\n");
		exit(-1);
	}
	else if(pid == 0){
		printf("Child Process: %d\tParent Process: %d\n",getpid(),getppid());
	}
	else{
		wait(NULL);
		printf("Parent Process: %d\tChild Process: %d\n",getpid(),pid);
		exit(0);
	}
	return 0;
}
	
