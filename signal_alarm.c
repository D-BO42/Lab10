/**
 * File: signal_alarm.c
 * Modified by: Dylan Bodoh
 * 
 * Brief summary of program: sends alarm signal after 5 seconds and catches it
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void alarm_handler(int sig)
{
    printf("SIGALRM received\n");
    exit(0);
}

int main()
{
    signal(SIGALRM, alarm_handler);

    printf("Sending alarm in 5 seconds...\n");
    alarm(5);

    while(1)
    {
        pause();    // wait for signals
    }

    return 0;
}