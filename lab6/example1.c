#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void handle_signal(int sig) {
    if (sig == SIGINT){
        printf("Caught SIGINT!\n");
        exit(0);
    } else if (sig == SIGQUIT){
        printf("Caught SIGQUIT!\n");
        abort();
    } else {
        printf("Caught SIGTERM!\n");
        exit(1);
    }
}

int main() {
    signal(SIGINT, handle_signal);
    signal(SIGQUIT, handle_signal);
    signal(SIGTERM, handle_signal);

    while (1) {
        printf("Hello world!\n");
        sleep(1);
    }

    return 0;
}