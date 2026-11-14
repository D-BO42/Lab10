/**
 * File: signal_sigaction.c
 * Modified by: Dylan Bodoh
 * 
 * Brief summary of program: reseves signal using sigaction
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void usr1_handler(int sig, siginfo_t *info, void *context)
{
    printf("SIGUSR1 received from PID %d\n", info->si_pid);
}

int main()
{
    struct sigaction sa;

    sa.sa_sigaction = usr1_handler;
    sa.sa_flags = SA_SIGINFO;    // Use siginfo_t
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        perror("sigaction");
        exit(1);
    }

    printf("Process PID: %d\n", getpid());

    while (1)
    {
        pause();    // wait for signals
    }

    return 0;
}
