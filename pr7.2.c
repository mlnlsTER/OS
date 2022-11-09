#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

struct thread_arg{
	char * name; 
	char * str;
	int num;
};

void * any_func(void * arg){
	int i;
	struct thread_arg * targ = (struct thread_arg*) arg;
	for(i = 0; i < targ->num; i++) printf("%s\t %s\t %d\n", targ->name, targ->str, i+1);	
	return NULL;
}

int main(void){
	int i;
	pthread_t thread1, thread2, thread3, thread4;
	
	struct thread_arg targ1;
	targ1.name = "Thread1";
	targ1.str = "Hello World";
	targ1.num = 1;
	
	struct thread_arg targ2;
	targ2.name = "Thread2";
	targ2.str = "Hello World";
	targ2.num = 2;
	
	struct thread_arg targ3;
	targ3.name = "Thread3";
	targ3.str = "Hello World";
	targ3.num = 3;
	
	struct thread_arg targ4;
	targ4.name = "Thread4";
	targ4.str = "Hello World";
	targ4.num = 4;
	
	if(pthread_create(&thread1, NULL, &any_func, &targ1) != 0){
		fprintf(stderr, "Error (thread1)\n");
		return 1;
	}
	if(pthread_create(&thread2, NULL, &any_func, &targ2) != 0){
		fprintf(stderr, "Error (thread2)\n");
		return 1;
	}
	if(pthread_create(&thread3, NULL, &any_func, &targ3) != 0){
		fprintf(stderr, "Error (thread3)\n");
		return 1;
	}
	if(pthread_create(&thread4, NULL, &any_func, &targ4) != 0){
		fprintf(stderr, "Error (thread4)\n");
		return 1;
	}
	while(1);
	return 0;
}
