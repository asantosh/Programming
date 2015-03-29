#include <stdio.h>
#include <pthread.h>

//pthread_mutex_t mutex_lock = PTHREAD_MUTEX_INITIALIZER;
int  flag = 1;

void* hello(void* arg)
{
    int i = 0;
    while(i<5)
    {
	if(flag)
	{
	    //pthread_mutex_lock(&mutex_lock);
	    printf("hello\t");
	    flag = 0;
	    i++;
	    //pthread_mutex_unlock(&mutex_lock);
	}
    }
}

void* world(void* arg)
{
    int i = 0;
    while(i<5)
    {
	if(!flag)
	{
	    //pthread_mutex_lock(&mutex_lock);
	    printf("world\n");
	    flag = 1;
	    i++;
	    //pthread_mutex_unlock(&mutex_lock);
	}
    }
}

int main()
{
    int err ;
    pthread_t tid[2];

    err = pthread_create(&tid[0], NULL, &hello, NULL);	
    if(err != 0)
	return 0;

    err = pthread_create(&tid[1], NULL, &world, NULL);	
    if(err != 0)
	return 0;

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    return 0;
}


