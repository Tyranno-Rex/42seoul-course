#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define THREAD_COUNT 10
#define RESOURCE_COUNT 5
#define MAX_COUNT 10

int shared_resource[RESOURCE_COUNT];
pthread_mutex_t mutex;

void *thread_func(void *arg) {
    int thread_num = *((int*)arg);
    for (int i = 0; i < MAX_COUNT; i++) {
        // 자원 선택
        int resource_num = thread_num % RESOURCE_COUNT;
        pthread_mutex_lock(&mutex);

        // 공유 자원 사용
        printf("Thread %d is accessing resource %d.\n", thread_num, resource_num);
        shared_resource[resource_num]++;
        printf("Thread %d has finished accessing resource %d.\n", thread_num, resource_num);

        pthread_mutex_unlock(&mutex);
        usleep(1000000);
    }
    return NULL;
}

int main() {
    pthread_t threads[THREAD_COUNT];
    int thread_nums[THREAD_COUNT];

    if (pthread_mutex_init(&mutex, NULL) != 0) {
        printf("Mutex initialization failed\n");
        return 1;
    }

    // 쓰레드 생성
    for (int i = 0; i < THREAD_COUNT; i++) {
        thread_nums[i] = i;
        if (pthread_create(&threads[i], NULL, thread_func, &thread_nums[i]) != 0) {
            printf("Thread creation failed\n");
            return 1;
        }
    }

    // 쓰레드 종료 대기
    for (int i = 0; i < THREAD_COUNT; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            printf("Thread join failed\n");
            return 1;
        }
    }

    if (pthread_mutex_destroy(&mutex) != 0) {
        printf("Mutex destruction failed\n");
        return 1;
    }

    return 0;
}