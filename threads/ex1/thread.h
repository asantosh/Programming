#ifndef __THREAD_H
#define __THREAD_H

#include <pthread.h>

typedef void *(*thread_routine) (void *);

int create_thread(pthread_t *thread, const pthread_attr_t *attr,
                  void *(*thread_routine) (void *), void *arg);


#endif
