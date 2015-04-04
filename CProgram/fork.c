#include <stdio.h>
#include <unistd.h>

int main(void)
{
    printf("I am the root %d\n", getpid());

    if (fork() == 0)
	printf("I am %d, child of %d\n", getpid(), getppid());

    if (fork() == 0)
	printf("I am %d, child of %d\n", getpid(), getppid());

    if (fork() == 0) {
	printf("I am %d, child of %d\n", getpid(), getppid());

	if(fork() == 0)
	    printf("parent = %d; child = %d\n", getpid(), getppid());

    }
    if (fork() == 0)
	printf("I am %d, child of %d\n", getpid(), getppid());	


    return 0;
}
