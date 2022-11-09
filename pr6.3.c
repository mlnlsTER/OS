#include <unistd.h>
#include <sys/types.h>
#include <cstdio>
#include <stdlib.h>

pid_t getpid(void);
pid_t getppid(void);
pid_t getpgrp(void);
uid_t getuid(void);
uid_t geteuid(void);
gid_t getgid(void);
gid_t getegid(void);

pid_t fork(void);

int atoi(const char *string);

int main(int argc, char *argv[]){
        int n = atoi(argv[1]);
        int i;
	pid_t pid;
	printf("Вызов функции fork...\n");
	int c = 0;
	for(i = 0; i < n; i++){
		pid = fork();
		if (pid == 0){
			printf("Процесс - потомок. PID: %d\n", getpid());
			//exit(getpid());
		} else if (pid > 0) {
			printf("Родительский процесс, pid потомка %d\n", pid);
			pid = getpid();
			//exit(getpid());
		} else {
		printf("Ошибка вызова fork, потомок не создан\n");
		}
		printf("-----------\n");
	}
	system("ps -la");
	printf("!-----------!\n");
	exit(getpid());
	
	//return 0;
}
