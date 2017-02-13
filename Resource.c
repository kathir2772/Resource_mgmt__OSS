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


int shmid;
void *shared_memory = (void *)0;
int a = 50;
int b = 20;

int sem_id;
struct  Resource *stuff;

void shared_mem(void)
{
	int running = 1;int size,f;
	int i=1;
	pid_t pid_2,pid; 	
	size = sizeof(struct Resource);



	shmid = shmget((key_t)4, size, 0666|IPC_CREAT);
	if(shmid == -1){
		fprintf(stderr, "shmget failed\n");
		exit(EXIT_FAILURE);
	}

	sem_id = semget((key_t)134, 2, 0666 | IPC_CREAT); 	


	stuff = shmat(shmid,(void *)0,0);
	if(stuff == (void *)-1){
		fprintf(stderr, "shmget failed\n");
			exit(EXIT_FAILURE);
	}


	stuff->a = a;
	stuff->b = b;

	fork_call();
}

void semaphore_lock(void)
{
	struct sembuf v;

	v.sem_num = 0;
	v.sem_op = -1;
	v.sem_flg = SEM_UNDO;

	if (semop(sem_id, &v, 1) == -1) {
		perror("Thread1:semop failure Reason:");
		exit(-1);
	}

}

void semaphore_unlock()
{
	struct sembuf v;
	v.sem_num = 0;
	v.sem_op = 1;
	v.sem_flg = SEM_UNDO;

	if (semop(sem_id, &v, 1) == -1) {
		perror("Thread1:semop failure Reason:");
		exit(-1);
	}
}


