/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Dylan Bodoh
 * 
 * Brief summary of modifications: added sigmentation fault handler
 */


#include <stdio.h>
#include <signal.h>

void segv_handler(int sig)
{
    printf("Segmentation fault signal received\n");
}

int main(int argc, char *argv[])
{
    signal(SIGSEGV, segv_handler);

    int *i = NULL;

    printf("The value of i is: %d\n", *i);

    return 0;
}