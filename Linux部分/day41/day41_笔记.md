# day41 笔记

Ep01 卖票问题

```c
void *saleWindow1(void *p)
{
    pData_t pData = (pData_t)p;
    while(1)
    {
        pthread_mutex_lock(&pData->mutex);
        //先加锁
        if(pData->tickets > 0)
        {
            printf("here is sale window 1 \n");
            printf("sale tickets %d\n",pData->tickets);
            pData->tickets --;
            if(pData->ticket == 0)
            {
                pthread_cond_singal(pData->cond);
            }
		}
        pthread_mutex_unlock(&pData->mutex);
    }
    pthread_exit(NULL);
}


void *saleWindow2(void *p)
{
    pData_t pData = (pData_t)p;
    while(1)
    {
        pthread_mutex_lock(&pData->mutex);
        //先加锁
        if(pData->tickets > 0)
        {
            printf("here is sale window 1 \n");
            printf("sale tickets %d\n",pData->tickets);
            pData->tickets --;
            if(pData->ticket == 0)
            {
                pthread_cond_singal(pData->cond);
            }
		}
        pthread_mutex_unlock(&pData->mutex);
    }
    pthread_exit(NULL);
}

void *setTicket(void *p)
{
    pData_t pData = (pData_t)p;
    while(1)
    {
        pthread_mutex_lock(pData->mutex);
        if(pData->tickets > 0)
        {
            printf("setTickets thread is waiting\n");
            pthread_cond_wait(&pData->cond,&pData->mutex);
        }
        pData->tickets = 20;
        pthread_mutex_unlock(pData->mutex);
    }
    pthread_exit(NULL);
}
```

