#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void * print_msg(void * arg){
	int i, n = *(int*) arg;
	for(i = 0; i < n; i ++){
		printf("Print_msg Tread. Iteration: %d\n", i);
		}
		pthread_exit(NULL);
		}

void * any_func(void * arg){
	int i, x, n = *(int*) arg;
	for(i = 0; i < n; i++) { 
		x = rand()%(n+1);
		printf("Any_func Thread. Random: %d\n", x);	
		if(x == n) {
			printf("Any_func Thread. x=n!\n");
			pthread_exit(NULL);
		}
	}
	return NULL;
}

int main(int argc, char *argv[]){
	if(argc < 2){
		fprintf(stderr, "Too few arguments\n");
		return 1;
	}
	int n = atoi(argv[1]);
	pthread_t thread1, thread2;
	
	if(pthread_create(&thread1, NULL, &print_msg, &n) != 0){
		fprintf(stderr, "Error (thread1)\n");
		return 1;
	}
	if(pthread_create(&thread2, NULL, &any_func, &n) != 0){
		fprintf(stderr, "Error (thread2)\n");
		return 1;
	}
	
	if(pthread_join(thread1, NULL) != 0){
		fprintf(stderr, "Join error\n");
		return 1;
	}
	if(pthread_join(thread2, NULL) != 0){
		fprintf(stderr, "Join error\n");
		return 1;
	}
	fprintf(stderr, "The End!\n");
	return 0;
}
