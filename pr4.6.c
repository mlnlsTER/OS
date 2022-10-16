#include <stdlib.h>
#include <cstdio>
#include <string.h>

extern char **environ;
char *getenv(const char *name);
int setenv(const char *name, const char *value, int overwrite);
char *getenv(const char *name);
int putenv(const char *init_str);
char *strcat(char *destptr, const char *srcptr);
char *strcpy(char *destptr, const char *srcptr);
int atoi(const char *string);

int main(int argc, char *argv[]) {
	if(!argv[1]) {
		printf("./name.out program_version name value overwrite(for version2 set random overwrite)\n");
		return -1;
	}
	if(!argv[2]) {
		printf("./name.out program_version name value overwrite(for version2 set random overwrite)\n");
		return -1;
	}
	if(!argv[3]) {
		printf("./name.out program_version name value overwrite(for version2 set random overwrite)\n");
		return -1;
	}
	printf("Fantastic!\n");
	char *name;
	char equals = '=';
	char *eq = &equals;
	switch(atoi(argv[1])){
		case 1:
			if (setenv(argv[2], argv[3], atoi(argv[4]))==0) printf("v1: %s=%s\n", argv[2], getenv(argv[2]));
			else {
			printf("Not enough space in environment memory!");
			return -1;
			}
			break;
		case 2:
			//strcat(argv[2], 
			//strcat(eq, argv[3]);

			printf("v2: %s\n", strcpy(name, strcat(strcat(argv[2], eq), argv[3])));
			/*else {
			printf("Not enough space in environment memory!");
			return -1;
			}*/
			break;	
		default:
		printf("Error! Invalid program version (only 1 or 2)\n");
		return -1;
	}
	return 0;
} 
