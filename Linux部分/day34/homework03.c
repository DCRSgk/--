#define N 10000000
int main()
{
	int shmid = shmget(1000,1<<20,IPC_CREAT|0600);
	int semArrId = semget(7777,1,IPC_CREAT|0600);
	ERROR_CHECK(semArrId,-1,"smget Error,");
	int ret = semctl(semArrId,0,SETVAL,1);
	struct sembuf sopp,sopv;
    
    sopp.sem_num = 0;
    sopp.sem_op = -1;
    sopp.sem_flg = SEM_UNDO;

    sopv.sem_num = 0;
    sopv.sem_op = 1;
    sopv.sem_flg = SEM_UNDO;
 


	if(fork)
	{
	    while(1)
	    {
	        sleep(1);
	        sopp.sem_num = 0;
	        sopp.sem_op = -1;
	        sopp.sem_flg = SEM_UNDO;
	        sopv.sem_num = 1;
	        sopv.sem_op = 1;
	        sopv.sem_flg = SEM_UNDO;
	        printf("producer repo = %d,product = %d\n",semctl(semArrId,0,GETVAl),semctl(semArrId,1,GETVAl));
	        semop(semArrId,&sopp,1);
	        //ռ����һ���ֿ�
	        printf("producer repo = %d,product = %d\n",semctl(semArrId,0,GETVAl),semctl(semArrId,1,GETVAl));
	        semop(semArrId,&sopv,1);
	        //������һ����Ʒ
	        printf("producer repo = %d,product = %d\n",semctl(semArrId,0,GETVAl),semctl(semArrId,1,GETVAl));
	    }
	}
	else
	{
	    while(1)
	    {
	        
	    
	    	sopp.sem_num = 1;
	        sopp.sem_op = -1;
	        sopp.sem_flg = SEM_UNDO;
	        sopv.sem_num = 0;
	        sopv.sem_op = 1;
	        sopv.sem_flg = SEM_UNDO;
	        printf("comsumer repo = %d,product = %d\n",semctl(semArrId,0,GETVAl),semctl(semArrId,1,GETVAl));
	        semop(semArrId,&sopp,1);
	        //������һ����Ʒ
	        printf("comsumer repo = %d,product = %d\n",semctl(semArrId,0,GETVAl),semctl(semArrId,1,GETVAl));
	        semop(semArrId,&sopv,1);
	        //�ͷ���һ���ֿ�  
	        printf("comsumer repo = %d,product = %d\n",semctl(semArrId,0,GETVAl),semctl(semArrId,1,GETVAl));
	    }
	}
	return 0��
} 
