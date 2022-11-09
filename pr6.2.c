#include <unistd.h>
#include <sys/types.h>
#include <cstdio>
#include <time.h>

pid_t getpid(void);
pid_t getppid(void);
pid_t getpgrp(void);
uid_t getuid(void);
uid_t geteuid(void);
gid_t getgid(void);
gid_t getegid(void);

pid_t fork(void);

int main(){
	pid_t pid;
	printf("Пока всего 1 процесс\nВызов функции fork...\n");
	time_t start = time(NULL);
	time_t now = time(NULL);
	int c = 0;
	while(difftime(now, start) < 2){
		now = time(NULL);
		pid = fork();
		if (pid == 0){
			printf("Процесс - потомок\n");
		} else if (pid > 0) {
			printf("Родительский процесс, pid потомка %d\n", pid);
		} else {
		printf("Ошибка вызова fork, потомок не создан\n");
		}
		c++;
		printf("-----------\n");
	}
	printf("Кол-во выполнений тела цикла: %d\n", c);
	return 0;
}
