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
void del_semvalue();

void child_3(struct Resource *s_ptr)
{
	int diff,max = 0;
	struct sembuf p;

	s_ptr = shmat(shmid,(void *)0,0);
	if(s_ptr == (void *)-1){
		fprintf(stderr, "shmget failed\n");
		exit(EXIT_FAILURE);
	}


	semaphore_lock();

	printf("\nacquired lock3\n"); 


	//	s_ptr->a = 10;
	//	s_ptr->b = 30;


	//	printf("\nmsg in child 3  %s\n",s_ptr->buf);
	long j;
	for(j=1000000000;j>0;j--);	
	printf("\nchild 3 completed loop\n");
	printf("\n");


	printf("relesed lock3\n"); 
	semctl(sem_id, 0, SETVAL, 0);

	semaphore_unlock();


	if(shmdt(s_ptr) < 0)
		perror("shmdt\n");



}




