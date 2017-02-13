#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include<sys/shm.h>
#include "Resource.h"

extern int shmid;
extern int sem_id;

void semaphore_lock();
void semaphore_unlock();

void child_2(struct Resource *s_ptr)
{

	int diff,max = 0,i;

	s_ptr = shmat(shmid,(void *)0,0);
	if(s_ptr == (void *)-1){
		fprintf(stderr, "shmget failed\n");
		exit(EXIT_FAILURE);
	}

	semaphore_lock();

	printf("acquired lock2\n"); 


	//	s_ptr->a = 10;
	//	s_ptr->b = 30;

	//		printf("\nmsg in child2 taken from child1  %s",s_ptr->buf);
	//		printf("\nenter msg to modify shared buffer\n");
	//		scanf("%s",s_ptr->buf);

	long j;
	for(j=10000000000;j>0;j--);
	printf("\nchild2 completed loop\n");
	printf("\n");

	semctl(sem_id, 0 , SETVAL ,0); 
	printf("relesed lock2\n"); 


	semaphore_unlock();



	if(shmdt(s_ptr) < 0)
		perror("shmdt\n");



}




