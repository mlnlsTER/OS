#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

//int pthread_create(pthread_t *Thread_ID, void *ATTR, void *(*THREAD_FUNC)(void*), void *ARG);

void * any_func(void * args){
	int i;
	for(i = 0; i < 10; i ++){
		printf("Child Thread. Iteration: %d\n", i + 1);
		sleep(1);
		}
	return NULL;
}

int main(void){
	int i;
	pthread_t thread;
	int result;
	result = pthread_create(&thread, NULL, &any_func, NULL);
		if(result != 0){
			fprintf(stderr, "Error\n");
			return 1;
		}
	for(i = 0; i < 10; i ++){
		printf("Main Thread. Iteration: %d\n", i + 1);
		sleep(1);
		}
	while(1);
	return 0;
}
