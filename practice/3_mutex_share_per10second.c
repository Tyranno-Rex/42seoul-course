#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define COUNT_MAX 10

int shared_resource = 0; // 공유자원
pthread_mutex_t mutex; // 뮤텍스

void *thread_func(void *arg) {
    int thread_num = *((int*)arg); // 스레드 번호

    for (int i = 0; i < COUNT_MAX; i++) { // COUNT_MAX 만큼 반복
        pthread_mutex_lock(&mutex); // 뮤텍스 락 -> 뮤텍스에 접근이 불가능
        if (shared_resource % 2 == thread_num) { // 스레드 번호와 공유자원을 비교하여 각 스레드가 번갈아 가며 사용
            printf("Thread %d: shared_resource = %d\n", thread_num, ++shared_resource);
        }
        usleep(2000000); // 1초 대기
        pthread_mutex_unlock(&mutex); // 뮤텍스 언락
        usleep(2000000); // 1초 대기
    }
    return NULL;
}

int main() {
    pthread_t threads[2]; // 스레드 배열
    int thread_nums[2] = {0, 1}; // 스레드 번호

    // 뮤텍스 초기화
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        printf("Mutex initialization failed\n");
        return 1;
    }
    // 스레드 생성
    for (int i = 0; i < 2; i++) {
        if (pthread_create(&threads[i], NULL, thread_func, &thread_nums[i]) != 0) {
            printf("Thread creation failed\n");
            return 1;
        }
        pthread_detach(threads[i]); // 스레드 분리
    }

    // 뮤텍스 삭제
    if (pthread_mutex_destroy(&mutex) != 0) {
        printf("Mutex destruction failed\n");
        return 1;
    }
    return 0;
}