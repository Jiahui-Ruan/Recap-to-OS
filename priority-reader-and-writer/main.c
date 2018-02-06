#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_WRITERS 5
#define NUM_WRITES 10
#define NUM_READERS 5
#define NUM_READS 10

void *readerThread(void *threadParam);
void *writerThread(void *threadParam);

pthread_mutex_t gResourceMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t gReaderCond = PTHREAD_COND_INITIALIZER;
pthread_cond_t gWriterCond = PTHREAD_COND_INITIALIZER;

int gWaitingReaders = 0, gReaders = 0;
unsigned int gSharedValue = 0;

int main() {
    int i;

    int readerNum[NUM_READERS];
    int writerNum[NUM_WRITERS];

    pthread_t readerTIDs[NUM_READERS];
    pthread_t writerTIDs[NUM_WRITERS];

    for (i = 0; i < NUM_READERS; i++) {
        readerNum[i] = i;
        pthread_create(&readerTIDs[i], NULL, readerThread, &readerNum[i]);
    }
    for (i = 0; i < NUM_WRITERS; i++) {
        writerNum[i] = i;
        pthread_create(&writerTIDs[i], NULL, writerThread, &writerNum[i]);
    }

    for (i = 0; i < NUM_READERS; i++) {
        pthread_join(readerTIDs[i], NULL);
    }
    for (i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writerTIDs[i], NULL);
    }

    printf("parent thread quitting\n");
    fflush(stdout);
    return 0;
}

void *readerThread(void *threadParam) {
    int i, numReaders = 0;
    int id = *((int *)threadParam);

    for (i = 0; i < NUM_READS; i++) {
        // Wait Random Time
        usleep(1000 * (random() % NUM_READERS + NUM_WRITERS));

        // Enter Critical Section
        pthread_mutex_lock(&gResourceMutex);
            gWaitingReaders++;
            while (gReaders == -1) {
                pthread_cond_wait(&gReaderCond, &gResourceMutex);
            }
            gWaitingReaders--;
            numReaders = ++gReaders;
        pthread_mutex_unlock(&gResourceMutex);

        // Critical Section
        fprintf(stdout, "[r%d] reading %u [readers: %2d]\n", id, gSharedValue, numReaders);

        // Leave Critical Section
        pthread_mutex_lock(&gResourceMutex);
            gReaders--;
            if (gReaders == 0) {
                pthread_cond_signal(&gWriterCond);
            }
        pthread_mutex_unlock(&gResourceMutex);
    }

    pthread_exit(0);
}

void *writerThread(void *threadParam) {
    int i, numReaders = 0;
    int id = *((int *)threadParam);

    for (i = 0; i < NUM_WRITES; i++) {
        // Wait
        usleep(1000 * (random() % NUM_READERS + NUM_WRITERS));

        // Enter Critical Section
        pthread_mutex_lock(&gResourceMutex);
            while (gReaders != 0) {
                pthread_cond_wait(&gWriterCond, &gResourceMutex);
            }
            gReaders = -1;
            numReaders = gReaders;
        pthread_mutex_unlock(&gResourceMutex);

        // Critical Section
        fprintf(stdout, "[w%d] writing %u [readers: %2d]\n", id, ++gSharedValue, numReaders);

        // Leave Critical Section
        pthread_mutex_lock(&gResourceMutex);
            gReaders = 0;
            if (gWaitingReaders > 0) {
                pthread_cond_broadcast(&gReaderCond);
            }
            else {
                pthread_cond_signal(&gWriterCond);
            }
        pthread_mutex_unlock(&gResourceMutex);
    }
    pthread_exit(0);
}