/**
 * File: recv_signal.c 
 * Modified by: Dylan Bodoh
 * 
 * Brief summary of program: receves signal with sigqueue
 */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigusr1_handler(int sig, siginfo_t *info, void *context)
{
    (void)sig;
    (void)context;

    printf("Received SIGUSR1 with value: %d\n",
           info->si_value.sival_int);
    fflush(stdout);
}

int main(void)
{
    struct sigaction sa;

    sa.sa_sigaction = sigusr1_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;

    if (sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        perror("sigaction");
        exit(1);
    }

    printf("Receiver PID: %d\n", getpid()); //pid for other program input

    while (1)
    {
        pause();    // Wait for signals
    }

    return 0;
}