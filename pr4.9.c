#include <stdlib.h>
#include <cstdio>
#include <unistd.h>
#include <sys/utsname.h>

int gethostname(char *name, size_t namelen);
int uname(struct utsname *name);
long gethostid(void);

int main(void) {
	struct utsname uts;
	char hostname[10];
	int rc = gethostname(hostname, sizeof(hostname));
	if(rc == 0){
  		printf("hostname = %s\n\n", hostname);
	}
	if (uname(&uts) < 0) printf("Error!");
  	else {
  		printf("Sysname:  %s\n", uts.sysname);
		printf("Nodename: %s\n", uts.nodename);
		printf("Release:  %s\n", uts.release);
		printf("Version:  %s\n", uts.version);
		printf("Machine:  %s\n\n", uts.machine);
	}
	printf("hostid = %ld\n", gethostid());
	
}
