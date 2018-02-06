#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 4

void *hello (void *arg) {
    printf("Hello Thread.\n");
    return 0;
}

void *threadFunc(void *pArg) {
    int myNum = *((int *)pArg);
    printf("Thread Number %d\n", myNum);
    return 0;
}

int main() {
    int i;
    pthread_t tid[NUM_THREADS];
    int tNum[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        tNum[i] = i;
        pthread_create(&tid[i], NULL, threadFunc, &tNum[i]);
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(&tid[i], NULL);
    }
    return 0;
}