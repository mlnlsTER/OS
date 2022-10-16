#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>

int clearenv(void);
extern char **environ;

int main(int argc, char *argv[]){
	if(!argv[1]) {
		printf("./name.out name\n");
		return -1;
	}
	if (argv[1] == NULL) clearenv();
    	else unsetenv(argv[1]);
	return 0;
}
