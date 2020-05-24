#include <stdio.h>
#include <myLibrary.h>
int main()
{
    key_t information = 7777;
    int semArrId = semget(information,7,IPC_CREAT|0600);
    ERROR_CHECK(semArrId,-1,"semget Error,5");
    //IPC_CREAT
    //创建信号量
    struct semid_ds stat;
    memset(&stat,0,sizeof(stat));
    int ret;
    ret = semctl(semArrId,0,IPC_STAT,&stat);
    ERROR_CHECK(ret,-1,"semctl Error,12");
    printf("sem_nsems=%ld,per=%o\n",stat.sem_nsems,stat.sem_perm.mode);
    //IPC_STAT
    //读取一个信号量集的数据结构semid_ds，
    //并将其存储在semun中的buf参数中   
    
    stat.sem_perm.mode = 0666;
    //修改权限666
    ret = semctl(semArrId,0,IPC_SET,&stat);
    ERROR_CHECK(ret,-1,"set Error,21");
    printf("the stat was changed,new stat is:\n");
    printf("sem_nsems=%ld,per=%o\n",stat.sem_nsems,stat.sem_perm.mode);
    //IPC_SET
    //设置信号集中的ipc_prem，取值取自semun中的buf参数中
    
    ret = semctl(semArrId,0,GETVAL);
    ERROR_CHECK(ret,-1,"getval Error,28");
    printf("getval is %d\n",ret);
    //GETVAL
    //返回信号量集中的一个单个的信号量的值
    
    
    int valSet = 777;
    semctl(semArrId,0,SETVAL,valSet);
    ERROR_CHECK(ret,-1,"setval Error,35");
    //SETVAL
    //设置信号量集中的一个单独的信号量的值
    //此处设置信号的值为777
    //下面用getval打印
        
    int valGet;
    valGet = semctl(semArrId,0,GETVAL);
    ERROR_CHECK(valGet,-1,"getval Error,44");
    printf("the valset is %d\n",valGet);
    //GETVAL
    //读取信号集合中一个单独信号的值
    //此处获取的为上面设置的信号3的值777
    
    unsigned short allSet[7] = {1,2,3,4,5,6,7};
    ret = semctl(semArrId,0,SETALL,allSet);
    ERROR_CHECK(ret,-1,"setall Error,52");
    //SETALL
    //设置信号集合中所有信号的值
    
    unsigned short allGet[7];
    ret = semctl(semArrId,0,GETALL,allGet);
    ERROR_CHECK(ret,-1,"getall Error,59");
    //GETALL
    //获取信号中所有信号的值
    for(int i=0;i<7;i++)
    {
        printf("allGet[%d]=%d\n",i,allGet[i]);
    }
    //打印值

    ret = semctl(semArrId,0,IPC_RMID);
    ERROR_CHECK(ret,-1,"rm Error,69");
    printf("rm success\n");
    return 0;
}

