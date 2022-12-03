#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>

int n = 100000;
double currentPI = 0;

void * thread_function(void * arg) {
    pthread_setcancelstate(PTHREAD_CANCEL_DEFERRED, NULL); //Делаем поток синхронно-отменяемым

    int i, divider = 1;
    int old_cancel_state;

    for (i = 0; i < n; i++)
    {
        pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &old_cancel_state); //Делаем секцию неотменяемой

        currentPI += pow(-1, i) * (1. / divider); //Считаем ПИ
        divider += 2;

        pthread_setcancelstate(old_cancel_state, NULL); //Возвращаем старый тип отмены

        fprintf(stderr, "%lf\n", currentPI * 4); //Выводим значение
    }

    fprintf(stderr, "%lf -- Calculations completed!\n", currentPI * 4);

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) //Если аргументов в командной строке мало то ошибка
	{
		fprintf(stderr, "Too few arguments\n");
		return 1;
	}
    int n = atoi(argv[1]); //Считываем то что написали в консольке

    void * result;
    pthread_t thread;

    pthread_create(&thread, NULL, &thread_function, NULL); //Создаем отсоединенный поток (не нужно ждать его завершения в мейне)

    sleep(n); //Спим столько секунд сколько написали
    pthread_cancel(thread); //Затем отменяем поток

    if (!pthread_equal(pthread_self(), thread)) //Так надо потому что было в примере (если несколько потоков сделали проверка на именно тот который нужен нам)
    {
        pthread_join(thread, &result) ;
    }

    if (result == PTHREAD_CANCELED) //Если поток был отменен то написать шо отменен, иначе написать результат - условие
    {
        fprintf(stderr, "Canceled!\n");
    }
    else
    {
        fprintf(stderr, "Result of calculations: %lf\n", currentPI * 4);
    }

    return 0;
}
