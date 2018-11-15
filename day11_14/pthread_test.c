#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

void *thread_start(void *arg)
{
    pthread_t *tid = (pthread_t*)arg;
    while(1)
    {
        printf("i am child ----%p\n",*tid);

        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t tid ;
    int ret = pthread_create(&tid,NULL,thread_start,(void*)&tid);

    if(ret !=0)
    {
        printf("pthread ceate error\n");
        return -1;
    }

    int pid = getpid();
    sleep(3);

    pthread_cancel(tid);
    while(1)
    {
        printf("i am main -------!%d-------%p\n",pid,pthread_self());
        sleep(1);
    }

    return 0;
}
