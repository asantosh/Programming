#include <stdio.h>
#include <pthread.h>

#define print(fmt, ...) printf("%s: " fmt "\n", __func__, ##__VA_ARGS__)

static int cnt = 0;
static pthread_spinlock_t lock;

void *thread1(void *arg)
{	
	while (cnt <= 10) {
		pthread_spin_lock(&lock);
		if (cnt % 2 == 0)			//even 
			print("cnt = %d", cnt++);
		pthread_spin_unlock(&lock);
	}
	pthread_exit(0);
}
	
void *thread2(void *arg)
{	
	while (cnt < 10) {
		pthread_spin_lock(&lock);
		if (cnt % 2 == 1)				//odd
			print("cnt = %d", cnt++);
		pthread_spin_unlock(&lock);
	}
	pthread_exit(0);
}

int main(int argc, char *argv[])
{
	pthread_t t1, t2;
	int err;

	print("START");

	pthread_spin_init(&lock, PTHREAD_PROCESS_PRIVATE);

	err = pthread_create(&t1, NULL, thread1, NULL);
	if (err)
		goto err;

	err = pthread_create(&t2, NULL, thread2, NULL);
	if (err)
		goto err;

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	print("END");
	
	pthread_spin_destroy(&lock);
	return 0;

err:
	print("unable to create thread");
	return -1;
}
