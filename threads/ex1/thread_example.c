#include <stdio.h>
#include "thread.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *msg1(void *arg)
{
    int *count = (int *) arg;
    printf("thread 1\n");
#if 0
    pthread_mutex_lock(&mutex);
    (*count)++;
    pthread_mutex_unlock(&mutex);
#endif
    int i= 100000;
    while(i--)
	printf("%d", i);

}

void *msg2(void *arg)
{
    int *count = (int *) arg;
    printf("thread 2\n");
#if 0
    pthread_mutex_lock(&mutex);
    (*count)--;
    pthread_mutex_unlock(&mutex);
#endif
    int i= 100000;
    while(i--)
	printf("%d", i);

}

int main(void)
{
    int i = 0;
    pthread_t thread[2];

    create_thread(&thread[0], NULL, msg1, &i);
    printf("main1 %d\n",i);

    create_thread(&thread[1], NULL, msg2, &i);
    printf("main2 %d\n",i);

    pthread_mutex_destroy(&mutex);
    return 0;
    //	pthread_exit(0);
}
