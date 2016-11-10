#ifndef _SYNC_H_
#define _SYNC_H_

#define numThreads		3
#define numListElm		1000
#define print_error(str) 	printf("%s :Error "str"\n", __func__)

#ifdef DEBUG
#define dbg_print(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define print_return(str)   \
	do { \
		printf("%s :Error "str"\n", __func__);  \
		return; \
	} while(0)
#else
#define dbg_print(fmt, ...)
#define print_return(str)   \
	do { \
		return; \
	} while(0)
#endif

#define INIT_LOCK(lock)     pthread_rwlock_init(&lock, NULL)
#define WRITE_LOCK(lock)	pthread_rwlock_wrlock(&lock)
#define LEAVE_LOCK(lock)	pthread_rwlock_unlock(&lock)

void *producerThread(void *);
void *consumerThread(void *);
void *modifierThread(void *);

typedef struct __node {
	uint8_t val;
	struct __node *next;
} node_t;
typedef void *(*fptr_t)(void *);

void listLink(node_t *block, node_t **listHead)
{
	node_t *listPtr = *listHead;
	dbg_print("%s\n", __func__);

	if (!block)
		return;

	if (!listPtr) {
		listPtr = block;
		*listHead = listPtr;
		block->next = NULL;
		return;
	}

	while (listPtr->next != NULL)
		listPtr = listPtr->next;

	listPtr->next = block;
	block->next = NULL;

	return;
}

node_t *listUnLink(node_t **listHead)
{
	node_t *tmp;

	dbg_print("%s\n", __func__);

	tmp = *listHead;
	if(!tmp)
		return NULL;

	*listHead = (*listHead)->next;

	return tmp;
}

int traverseList(node_t *listPtr)
{
	dbg_print("%s\n", __func__);
	if (!listPtr) {
		print_error("Empty List");
		return 1;
	}

	while (listPtr->next != NULL) {
		printf(" Ptr:%p val:%d\n", listPtr, listPtr->val);
		listPtr = listPtr->next;
	}
	printf(" Ptr:%p val:%d\n", listPtr, listPtr->val);
	return 0;
}

int createFreeList(int numElem, node_t **listHead)
{
	uint32_t idx;
	node_t *member;

	for(idx = 0; idx < numElem; idx++) {
		member = malloc(sizeof(node_t));
		member->val = 0;
		member->next = NULL;
		listLink(member, listHead);
	}

	traverseList(*listHead);

	return 0;
}

#endif
