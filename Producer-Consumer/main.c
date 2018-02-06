#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define BUF_SIZE 3

int buffer[BUF_SIZE];
int add = 0;
int rem = 0;
int num = 0;

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t c_cons = PTHREAD_COND_INITIALIZER;
pthread_cond_t c_prod = PTHREAD_COND_INITIALIZER;

void *producer (void *param);
void *consumer (void *param);

int main() {
    pthread_t tid1, tid2;
    int i;

    if(pthread_create(&tid1, NULL, producer, NULL) != 0) {
        fprintf(stderr, "Unable to create producer\n");
        exit(1);
    }

    if(pthread_create(&tid2, NULL, consumer, NULL) != 0) {
        fprintf(stderr, "Unable to create consumer\n");
        exit(1);
    }

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    printf("Parent exit\n");
    return 0;
}

void *producer(void *param) {

    int i;
    for (i = 1; i <= 20; i++) {
        pthread_mutex_lock(&m);
        if (num > BUF_SIZE) {
            exit(1);
        }
        while (num == BUF_SIZE) {
            pthread_cond_wait(&c_prod, &m);
        }
        buffer[add] = i;
        add = (add + 1) % BUF_SIZE;
        num++;
        pthread_mutex_unlock(&m);

        pthread_cond_signal(&c_cons);
        printf("producer: inserted %d\n", i);
        fflush(stdout);
    }

    printf("producer quitting\n");
    fflush(stdout);
    return 0;
}

void *consumer(void *param) {
    int i;
    time_t start, end;
    double elapsed;
    start = time(NULL);
    int terminate = 1;

    while (terminate) {

        pthread_mutex_lock(&m);
        if (num < 0) {
            exit(0);
        }
        while (num == 0) {
            pthread_cond_wait(&c_cons, &m);
        }
        i = buffer[rem];
        rem = (rem + 1) % BUF_SIZE;
        num--;
        pthread_mutex_unlock(&m);

        pthread_cond_signal(&c_prod);
        printf("consumer: consume %d\n", i);
        fflush(stdout);

        end = time(NULL);
        elapsed = difftime(end, start);
        if (elapsed >= 90.0) {
            terminate = 0;
        }
    }

    printf("consumer quitting");
    return 0;
}