/**
 * File: send_signal.c
 * Modified by: Dylan Bodoh
 * 
 * Brief summary of program: gets a pid argument and then sends a
 * random number to the process using sigqueue
 * program 
 */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2) //check if there is a argument
    {
        printf("no argument");
        return 1;
    }

    pid_t pid = atoi(argv[1]); //pid of receving process

    srand(time(NULL)); //seed random number with time

    int random_num = rand(); //get random number

    printf("Sending value: %d\n", random_num);

    union sigval value;
    value.sival_int = random_num;

    if (sigqueue(pid, SIGUSR1, value) == -1) //check if signal sends
    {
        perror("sigqueue");
        return 1;
    }

    return 0;
}