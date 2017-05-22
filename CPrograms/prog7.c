#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	int i;
	pid_t pid;
	
	for(i=0; i<3; i++){
		
		pid = fork();
		if(pid < 0){
			printf("Error\n");
			exit(-1);
		}
		else if(pid==0){
			printf("Child Process %d: %d\n",i+1,getpid());
		}
		else{
			wait(NULL);
			if(i==2)
				printf("-------------------------\n");
			
			printf("Child process %d finished\n",i+1);
			exit(0);
		}
		printf("Hello\n");
	}
	return 0;
}
