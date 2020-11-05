#define _REENTRANT
#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <semaphore.h>

sem_t empty;
sem_t full;
sem_t mutex;

typedef struct {
    char buf[15];
    int loc;
} buffer_t;

static buffer_t b;
void *producer(void *args) {
    for (int i = 0; i < 15; i++)
    {
        b.buf[i] = 'a';
    }
}

int main()
{
    b.buf[0] = 'a';
    pthread_t tid1[1];

    pthread_attr_t attr[1];

    fflush(stdout);

    pthread_create(&tid1[0], &attr[0], producer, NULL);
    return 0;
}

