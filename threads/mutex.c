#include <stdio.h>
#include <pthread.h>


#define print(fmt, ...) printf("semaphore: %s: "fmt "\n", __func__, ##__VA_ARGS__)

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int count = 0;

void *thread1(void *data)
{
	while (count <= 10000) {
		pthread_mutex_lock(&lock);
		if (count % 2 == 0)				//even
			printf("count = %d\n", count++);
		pthread_mutex_unlock(&lock);
	}
}

void *thread2(void *data)
{
	while (count < 10000) {
		pthread_mutex_lock(&lock);
		if (count % 2 != 0)				//odd
			printf("count = %d\n", count++);
		pthread_mutex_unlock(&lock);
	}
}

int main(int argc, char *argv[])
{
	pthread_t t1, t2;
	int err;

	print("START");
	
	err = pthread_create(&t1, NULL, thread1, NULL);
	if (err != 0)
		goto err;

	err = pthread_create(&t2, NULL, thread2, NULL);
	if (err != 0)
		goto err;

	print("END");
	pthread_exit(0);

err:
	print("unable to create thread");
	return -1;
}
 
