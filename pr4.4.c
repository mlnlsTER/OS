#include <stdlib.h>
#include <cstdio>

extern char **environ;

int main(void) {
	for (; *environ; environ++) printf("%s\n", *environ);
} 
