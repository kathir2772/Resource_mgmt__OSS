#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#include<sys/shm.h>
#include "Resource.h"


extern int shmid;
extern int sem_id;

void semaphore_lock();
void semaphore_unlock();
void set_semvalue();
void child_1(struct Resource *resource_ptr)
{
	int sum, max = 0;
	char c;


	resource_ptr = shmat(shmid, (void *)0, 0);
	if (resource_ptr == (void *)-1) {
		fprintf(stderr, "shmget failed\n");
		exit(EXIT_FAILURE);
	}

	resource_ptr->a = 10;
	resource_ptr->b = 20;

	semctl(sem_id, 0, SETVAL, 1);
	semaphore_lock();

	printf("acquired lock 1\n");


	//		printf("\nEnter string\n");
	//		scanf("%s",resource_ptr->buf);
	long j;
	for(j=10000000000;j>0;j--);
		printf("\nchild 1 loop completed\n");

	printf("\n");	




	sum = resource_ptr->a + resource_ptr->b;

	printf("sum is = %d\n", sum);

	printf("released lock 1\n");
	semaphore_unlock();





	if (shmdt(resource_ptr) < 0)
		perror("shmdt");

}
