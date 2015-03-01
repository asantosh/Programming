#include "thread.h"
#include <assert.h>

int create_thread(pthread_t *_thread, const pthread_attr_t *attr,
                          thread_routine routine , void *arg)
{
	int rc;
	pthread_t thread;

	rc = pthread_create(&thread, attr, routine, arg);
	assert(rc == 0);

	pthread_join(thread, NULL);

	if (_thread)
		*_thread = thread;

	return 0;
}
