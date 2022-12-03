#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

/* обработчик для SIGINT */
static void signal_handler(int signo) {
    if (signo == SIGINT)
        printf("Захвачен сигнал SIGINT!\n");
    else if (signo == SIGTERM)
        printf("Захвачен сигнал SIGTERM!\n");
    else {
        /* это никогда не должно случаться */
        fprintf(stderr, "Неожиданный сигнал!\n");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}

int main (void) {

    // Регистрируем signal_handler нак наш обработчик сигнала для SIGINT
    if (signal(SIGINT, signal_handler) == SIG_ERR) {
        fprintf(stderr, "Невозможно обработать SIGINT!\n");
        exit(EXIT_FAILURE);
    }
    // Регистрируем signal_handler как наш обработчик сигнала для SIGTERM
    if (signal(SIGTERM, signal_handler) == SIG_ERR) {
        fprintf(stderr, "Невозможно обработать SIGTERM!\n");
        exit(EXIT_FAILURE);
    }

    // Восстановление поведения по умолчание для сигнала SIGPROF
    if (signal(SIGPROF, SIG_DFL) == SIG_ERR) {
        fprintf(stderr, "Невозможно сбросить SIGPROF!\n");
        exit(EXIT_FAILURE);
    }

    // Игнорировать SIGHUP
    if (signal(SIGHUP, SIG_IGN) == SIG_ERR) {
        fprintf(stderr, "Невозможно игнорировать SlGHUP!\n");
        exit(EXIT_FAILURE);
    }

    while(1)
        pause();
}
