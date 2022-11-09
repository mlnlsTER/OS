#include <unistd.h>
#include <sys/types.h>
#include <cstdio>

pid_t getpid(void);
pid_t getppid(void);
pid_t getpgrp(void);
uid_t getuid(void);
uid_t geteuid(void);
gid_t getgid(void);
gid_t getegid(void);

int main(){
	printf(" pid: %d\n ppid: %d\n pgrp: %d\n uid: %d\n euid: %d\n gid: %d\n egid: %d\n", getpid(), getppid(), getpgrp(), getuid(), geteuid(), getgid(), getegid());
	return 0;
}
