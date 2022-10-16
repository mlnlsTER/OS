#include <stdlib.h>
#include <cstdio>

char *getenv(const char *name);

int main(int argc, char *argv[]) {
	if(argv[1]) printf("%s\n", getenv(argv[1]));
	else printf("./name.out var\n");
} 
