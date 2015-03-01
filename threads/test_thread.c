#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <sched.h>
#include <unistd.h>

void *thread1(void *arg)
{
	while(1) {
//		sleep(1);
		printf("pid %u cpu %d\n", (unsigned int)pthread_self(), sched_getcpu());
	}
}

void *thread2(void *arg)
{
	while(1) {
//		sleep(1);
		printf("pid %u cpu %d\n", (unsigned int)pthread_self(), sched_getcpu());
	}
}

int main(void)
{
	int rc;
	pthread_t t1, t2;
	cpu_set_t cpuset;
	
	/*create a thread - pthread_create(thread_id, thread_attribute, function, args to function); */
	rc = pthread_create(&t1, NULL, thread1, NULL);
	assert(rc == 0);

	rc = pthread_create(&t2, NULL, thread2, NULL);
	assert(rc == 0);

	/*Over ride scheduler, set t1 to CPU -0 and t2 to CPU -1*/
	pthread_getaffinity_np(t1, sizeof(cpuset), &cpuset);
	CPU_CLR_S(1, sizeof(cpuset), &cpuset);
	CPU_SET_S(0, sizeof(cpuset), &cpuset);
	pthread_setaffinity_np(t1, sizeof(cpuset), &cpuset);

	pthread_getaffinity_np(t2, sizeof(cpuset), &cpuset);
	CPU_CLR_S(0, sizeof(cpuset), &cpuset);
	CPU_SET_S(1, sizeof(cpuset), &cpuset);
	pthread_setaffinity_np(t2, sizeof(cpuset), &cpuset);


	pthread_exit(0);
}
