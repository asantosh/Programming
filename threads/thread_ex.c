#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <pthread.h>
	

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

static int i = 10;

void *func1(void *arg)
{
	while (i > 0) {
		pthread_mutex_lock(&mutex);
		i--;
		printf("1: %s i = %d\n", __func__, i);
		pthread_mutex_unlock(&mutex);
	}
}

void *func2(void *arg)
{
	while (i > 0) {
		pthread_mutex_lock(&mutex);
		i--;
		printf("2: %s i = %d\n", __func__, i);
		pthread_mutex_unlock(&mutex);
	}
}

int main(int argc, char *argv[])
{
	int rc;
	pthread_t thr[2];

	printf("thread: %s\n", __func__);

	rc = pthread_create(&thr[0], NULL, func1, NULL);
	assert(rc == 0);
	
	rc = pthread_create(&thr[1], NULL, func2, NULL);
	assert(rc == 0);


	pthread_mutex_destroy(&mutex);
	pthread_exit(0);

}

