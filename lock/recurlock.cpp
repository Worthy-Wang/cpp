
#include <stdio.h>
#include <pthread.h>
int count = 0;
pthread_mutex_t mutex;

void *thread_proc(void *)
{
    int i = 0;
    for (i = 0; i < 5000; i++)

    {
        pthread_mutex_lock(&mutex);
        pthread_mutex_lock(&mutex);
        count++;
        printf("count = %d\n", count);
        pthread_mutex_unlock(&mutex);
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{
    pthread_t tid1, tid2;

    // 需要先定义一个pthread_mutexattr_t变量，用于设置锁的属性
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    //设置锁的属性
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&mutex, &attr);
    pthread_create(&tid1, NULL, thread_proc, NULL);
    pthread_create(&tid2, NULL, thread_proc, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    return 0;
}
