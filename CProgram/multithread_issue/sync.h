#ifndef _SYNC_H_
#define _SYNC_H_

#define numThreads		3
#define numListElm		10
#define print_error(str) 	printf("%s :Error "str"\n", __func__)

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
	if (!listPtr) {
		listPtr = block;
		*listHead = listPtr;
		return;
	}

	while (listPtr->next != NULL)
		listPtr = listPtr->next;

	listPtr->next = block;

	return;
}

node_t *listUnLink(node_t **listHead)
{
	node_t *tmp;

	tmp = *listHead;
	*listHead = (*listHead)->next;

	return tmp;
}

int traverseList(node_t *listPtr)
{
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
		member->val = idx;
		member->next = NULL;
		listLink(member, listHead);
	}

	traverseList(*listHead);

	return 0;
}

#endif
