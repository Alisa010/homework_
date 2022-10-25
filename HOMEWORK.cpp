#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include<sys/wait.h>
int main(int argc, char** argv){

   for(int i = 1; i < argc; ++i){	
	pid_t pid = fork();
	char* arr[] = {argv[i], nullptr};
	if(pid == -1){ 
		exit(1);
	}
	if(pid == 0){
		execvp(argv[i], arr);
		
	}

	if(pid > 0){
		int wait_status;
		wait(&wait_status);
		if(WIFEXITED(wait_status)){
			if(WEXITSTATUS(wait_status) == 0){
				break;
			}
			else{
				continue;
			}
		}
	}
  }
}
