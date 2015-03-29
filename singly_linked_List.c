#include <stdio.h>
#include <stdlib.h>

#define p_start	printf("%s: start\n", __func__)

#define p_end	printf("%s: end\n", __func__)

typedef struct node {
    int data;
    struct node *next;
}Node;


int is_empty(const Node *head)
{
    return head == NULL ? 1 : 0;
}

void append(Node **head, int num)
{
    Node *pos = *head;
    Node *temp = (Node *) malloc(sizeof(Node));

    if (is_empty(temp))
	return;

    temp->data = num;
    temp->next = NULL;

    if (pos == NULL) {
	pos = temp;
	*head = temp;
    } else {
	while (pos->next != NULL)
	    pos = pos->next;

	pos->next = temp;
    }

}

int delete(Node **head, const int num)
{
    Node *tmp = *head;
    Node *pos = *head;

    if (is_empty(pos))
	return -1;

    while (pos != NULL) {
	if (pos->data == num) {
	    if (pos == *head) {
		*head = pos->next;
		free(pos);
		return 0;
	    }
	    tmp->next = pos->next;
	    free(pos);
	    return 0;
	}
	tmp = pos;
	pos = pos->next;
    }
    return -1;
}

int reverse(Node **head)
{
    Node *prev = NULL;
    Node *nxt = NULL;
    Node *pos = *head;

    if (is_empty(pos))
	return -1;

    while(pos->next != NULL) {
	nxt = pos->next;
	pos->next = prev;
	prev = pos;
	pos = nxt;
    }

    pos->next = prev;
    *head = pos;
    return 0;
}

/*selection sort*/
int sort(Node *head)
{
    int tmp = 0;
    Node *pos = NULL;
    if (is_empty(head))
	return -1;

    for(; head != NULL; head = head->next) {
	for(pos = head; pos != NULL; pos = pos->next) {
	    if (head->data > pos->data) {
		tmp = head->data;
		head->data = pos->data;
		pos->data = tmp;
	    }
	}
    }
    return 0;
}


void print(const Node *head)
{
    if (is_empty(head))
	return;

    while (head != NULL) {
	printf("loc = %p data = %d\n", head, head->data);
	head = head->next;
    }

    printf("\n");
    return;
}

int main(void)
{
    unsigned short i = 0;
    Node *head = NULL;

    p_start;

    for (i = 0; i < 10; i++)
	append(&head, i);

    print(head);

    delete(&head, 0);
    print(head);

    reverse(&head);
    print(head);

    sort(head);
    print(head);

    p_end;
    return 0;
}
