#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

int main(void){
	int status;
	
	if (fork()){
		execlp("ls", "ls", NULL);
		fprintf(stderr, "Exec error\n");
	}
	
	sleep(40);
	system("ps -l");
	wait(&status);
	
	if(WIFEXITED (status)){
		printf("Code=%d\n", WEXITSTATUS(status));
	}
	system("ps -l");
	return 0;
}
	
