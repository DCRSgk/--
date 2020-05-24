#include<myLibrary.h>
#define N 10000000
int main()
{
	int shmid = shmget(1000,1<<20,IPC_CREAT|0600);
	int semArrId = semget(7777,1,IPC_CREAT|0600);
	ERROR_CHECK(semArrId,-1,"smget Error,");
	int ret = semctl(semArrId,0,SETVAL,1);
	ERROR_CHECK(ret,-1,"semctl Error,8");
    int *p = (int*)shmat(shmid,NULL,0);
	p[0]=0;
	struct sembuf sopp,sopv;
    
    sopp.sem_num = 0;
    sopp.sem_op = -1;
    sopp.sem_flg = SEM_UNDO;

    sopv.sem_num = 0;
    sopv.sem_op = 1;
    sopv.sem_flg = SEM_UNDO;
    
	if(fork())
	{
	    for(int i = 0;i<N;i++)
	    {
        semop(semArrId,&sopp,1);
        //加锁
        p[0] += 1;
        semop(semArrId,&sopv,1);
        //解锁
    }
	    wait(NULL);
	    //等待子进程
	    printf("total = %d\n",p[0]);
	}
	else
	{    
	    for(int i = 0;i<N;i++)
	    {
	        semop(semArrId,&sopp,1);
	        p[0] += 1;
	        semop(semArrId,&sopv,1);
	    }
	}
	return 0;
} 
