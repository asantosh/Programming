#include <stdio.h>
#include <inttypes.h>
#include <pthread.h>
#include <unistd.h>
#include <assert.h>
#include <stdlib.h>
#include "sync.h"

fptr_t fptr[numThreads] = {producerThread, modifierThread, consumerThread};
node_t *gProList, *gModList, *gConList;
pthread_rwlock_t proListLock, modListLock, conListLock;

void *producerThread(void *arg)
{
	while (1) {
		printf("%s\n", __func__);
		sleep (1);
	}

	return 0;
}

void *consumerThread(void *arg)
{
	while (1) {
		printf("%s\n", __func__);
		sleep (1);
	}

	return 0;
}

void *modifierThread(void *arg)
{
	while (1) {
		printf("%s\n", __func__);
		sleep (1);
	}

	return 0;
}

int main (int argc, char *argv[])
{
	uint8_t ret, cnt;
	pthread_t tid[numThreads];

	printf("\t %s: Start\n", __func__);

	createFreeList(numListElm, &gProList);

	pthread_rwlock_init(&proListLock, NULL);
	pthread_rwlock_init(&modListLock, NULL);
	pthread_rwlock_init(&conListLock, NULL);

	for (cnt = 0; cnt < numThreads; cnt++) {
		ret = pthread_create(&tid[cnt], NULL, fptr[cnt], NULL);
		assert(ret == 0);
	}

	printf("\t %s: End\n", __func__);

	for (cnt = 0; cnt < numThreads; cnt++) {
		ret = pthread_join(tid[cnt], NULL);
		assert(ret == 0);
	}

	return 0;
}
