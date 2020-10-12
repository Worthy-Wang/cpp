#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <iostream>
using namespace std;

#define THREAD_NUM 2

pthread_spinlock_t spinlock;

void *thread_proc(void *arg)
{
    int *pcount = (int *)arg;

    int i = 0;
    while (i++ < 100000)
    {
        pthread_spin_lock(&spinlock); // 加锁
        cout << pthread_self() << endl;
        cout << (*pcount)++ <<endl;
        pthread_spin_unlock(&spinlock); // 解锁
        usleep(1);
    }
}

int main()
{
    pthread_t thread_id[THREAD_NUM] = {0};

    int count = 0;

    // 初始化自旋锁
    pthread_spin_init(&spinlock, PTHREAD_PROCESS_SHARED);
    int i = 0;
    for (i = 0; i < THREAD_NUM; i++)
    {
        // 创建10个线程，每个线程对count实行自加到10万，count为这10个线程的一个共享资源
        pthread_create(&thread_id[i], NULL, thread_proc, &count);
    }

    // 每隔一秒打印一次count的值
    for (i = 0; i < 100; i++)
    {
        printf("count --> %d\n", count);
        sleep(1);
    }

    return 0;
}