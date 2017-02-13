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
#include<signal.h>
extern int shmid;
extern int sem_id;

void semaphore_lock();
void semaphore_unlock();
void del_semvalue();

void child_4(struct Resource *s_ptr)
{
	int diff,max = 0;
	struct sembuf p;

	s_ptr = shmat(shmid,(void *)0,0);
	if(s_ptr == (void *)-1){
		fprintf(stderr, "shmget failed\n");
		exit(EXIT_FAILURE);
	}


	semaphore_lock();

	printf("\nacquired lock4\n"); 


	//	s_ptr->a = 10;
	//	s_ptr->b = 30;


	//	printf("\nmsg in child 3  %s\n",s_ptr->buf);
	long j;
	for(j=100000000;j>0;j--);	
	printf("\nchild 4 completed loop\n");
	printf("\n");

	semaphore_unlock();
	semctl(sem_id, 0, IPC_RMID, 1);
	printf("relesed lock4\n"); 

int pid;
pid=getppid();
	if(shmdt(s_ptr) < 0)
		perror("shmdt\n");

if(kill(pid,9)!=-1)
	printf("\nAll process completed its terminating\n");

}




