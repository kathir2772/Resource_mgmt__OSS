#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<time.h>
#include<unistd.h>
#include<sys/types.h>
#include"Resource.h"

/////global variables//////
struct Resource *stuff;
int cnt=0;
int rand_val;
int child_cnt=-1;
///////////////////////


////////function declaration////////
void fork_call(void);
int rand_fun();
void child_1(struct Resource *);
void child_2(struct Resource *);
void child_3(struct Resource *);
void child_4(struct Resource *);
///////////////////////////////////



/////////function pointer//////////

void (*fptr[4])(struct Resource *)={child_1,child_2,child_3,child_4};

////////////////////////////////////







void usr_defned(int sig_num)
{	
	//sleep(2);
	printf("\n>>>>>>>>\n");

	cnt++;

	if(cnt==rand_val)
	{
		cnt = 0;
		sigaction(SIGALRM,0,0);
		shared_mem();
	}

	alarm(1);
}









void fork_call(void)
{
	int i,v;

	if(child_cnt < 4)
	{
		child_cnt += 1;
		printf("\nchild cnt is %d\n",child_cnt+1);
	}

	for(i=0; i<1 && child_cnt < 4; i++)
	{

		if(fork() ==0)
		{
			printf("\nchild process id is %d\n",getpid());

			(*fptr[child_cnt])(stuff);	

			printf("\nchild id %d completed its function\n",getpid());

			exit(0); 
		}
		//		else 
		//			wait(&v);
	}
}











int rand_fun()
{
	int randm=0;

	srand((unsigned)(time(NULL)));

	randm=rand()%5+1;

	printf("\nrandom value is %d\n",randm);

	printf("\n");

	return randm;

}











int main(void)
{
	int v,counter;

	rand_val=5;

	struct sigaction sa;
	//struct sigaction old;

	sa.sa_handler=usr_defned;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags=0;	

	sigaction(SIGALRM,&sa,0);
	alarm(1);
	//sleep(2);
	/*printf("Parent here\n");
	  while(1)
	  {	


	  while(wait(&v)==0)	
	  counter++;
	  if(counter==2)
	  break;
	  }*/	
	while(1)
	{


		if(child_cnt>4)
		{
			//		if(waitpid(-1,&v,0)!=-1){
			printf("\nchild cnt is at max\n");	
			break;
		}		
		}

		waitpid(-1,&v,0);
	}

