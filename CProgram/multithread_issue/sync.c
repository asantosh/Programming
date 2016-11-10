#include <stdio.h>
#include <inttypes.h>
#include <pthread.h>
#include <unistd.h>
#include <assert.h>
#include <stdlib.h>
#include "sync.h"

fptr_t fptr[numThreads] = {producerThread, modifierThread, consumerThread};
node_t *gFreeList, *gList_1, *gList_2;
pthread_rwlock_t freeListLock, list1Lock, list2Lock;

void consume_info_in_block(node_t *ptr)
{
	if (!ptr)
		return;

	ptr->val = 0;
	return;
}

void use_block_x_to_pro_y(node_t *x, node_t *y)
{
	if (!x || !y)
		return;

	y->val = x->val;
	x->val = 0;
	return;
}

void produce_info(node_t *ptr)
{
	if (!ptr)
		return;

	ptr->val = 1;
	return;
}

void *producerThread(void *arg)
{
	node_t *n_ptr;

	while (1) {
		printf("%s\n", __func__);

		WRITE_LOCK(freeListLock);
		n_ptr = listUnLink(&gFreeList);
		LEAVE_LOCK(freeListLock);

		produce_info(n_ptr);

		WRITE_LOCK(list1Lock);
		listLink(n_ptr, &gList_1);
		LEAVE_LOCK(list1Lock);
	}

	return 0;
}


void *modifierThread(void *arg)
{
	node_t *x_ptr, *y_ptr;
	while (1) {
		printf("%s\n", __func__);

		WRITE_LOCK(list1Lock);
		x_ptr = listUnLink(&gList_1);
		LEAVE_LOCK(list1Lock);

		WRITE_LOCK(freeListLock);
		y_ptr = listUnLink(&gFreeList);
		LEAVE_LOCK(freeListLock);

		use_block_x_to_pro_y(x_ptr, y_ptr);

		WRITE_LOCK(freeListLock);
		listLink(x_ptr, &gFreeList);
		LEAVE_LOCK(freeListLock);

		WRITE_LOCK(list2Lock);
		listLink(y_ptr, &gList_2);
		LEAVE_LOCK(list2Lock);
	}

	return 0;
}

void *consumerThread(void *arg)
{
	node_t *c_ptr;
	while (1) {
		printf("%s\n", __func__);

		WRITE_LOCK(list2Lock);
		c_ptr = listUnLink(&gList_2);
		LEAVE_LOCK(list2Lock);

		consume_info_in_block(c_ptr);

		WRITE_LOCK(freeListLock);
		listLink(c_ptr, &gFreeList);
		LEAVE_LOCK(freeListLock);
	}

	return 0;
}

int main (int argc, char *argv[])
{
	uint8_t ret, cnt;
	pthread_t tid[numThreads];

	printf("\t %s: Start\n", __func__);

	createFreeList(numListElm, &gFreeList);

	INIT_LOCK(freeListLock);
	INIT_LOCK(list1Lock);
	INIT_LOCK(list2Lock);

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
