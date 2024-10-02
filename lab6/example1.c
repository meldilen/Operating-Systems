#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void handle_signal(int sig) {
    printf("Signal: %d\n", sig);
    exit(1);
}

int main() {
    signal(SIGINT, handle_signal);
    signal(SIGQUIT, handle_signal);
    signal(SIGTERM, handle_signal);

    char buffer[1024];

    while (1) {
        printf("Hello world!\n");
        sleep(1);
    }

    return 0;
}