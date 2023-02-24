#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define RESOURCE_COUNT 2
#define THREAD_COUNT 4

pthread_mutex_t mutex; // 뮤텍스
int resources[RESOURCE_COUNT] = {0, 0}; // 자원
int active_threads = THREAD_COUNT; // 활성 쓰레드 수

void *thread_func(void *arg) {
    int thread_num = *((int*)arg); // 쓰레드 번호
    int resource_num = thread_num % RESOURCE_COUNT; // 자원 번호
    int lifespan = 5; // 스레드 수명 초기값

    while (active_threads > 1) { // 마지막 남은 스레드까지 실행
        int res = pthread_mutex_trylock(&mutex); // 뮤텍스 시도

        if (res == 0) { // 뮤텍스 점유 성공
            printf("Thread %d acquired resource %d\n", thread_num, resource_num);
            resources[resource_num] = thread_num; // 자원 점유
            lifespan = 5; // 수명 초기화
            usleep(1000000); // 1초 대기
            resources[resource_num] = 0; // 자원 반납
            pthread_mutex_unlock(&mutex); // 뮤텍스 언락
        }
        else { // 뮤텍스 점유 실패
            printf("Thread %d failed to acquire resource %d and exited\n", thread_num, resource_num);
            active_threads--; // 활성 쓰레드 수 감소
            pthread_exit(NULL); // 쓰레드 종료
        }

        // 수명 감소
        lifespan--;
        if (lifespan == 0) {
            lifespan = 5;
            printf("Thread %d lifespan extended\n", thread_num);
        }

        sleep(1); // 1초 대기
    }

    printf("Thread %d exited\n", thread_num);
    active_threads--; // 활성 쓰레드 수 감소

    if (active_threads == THREAD_COUNT - 1) { // 쓰레드가 1개만 남은 경우
        printf("Thread %d terminated the program\n", thread_num);
        exit(0); // 프로그램 종료
    }

    pthread_exit(NULL);
}


int main() {
    pthread_t threads[THREAD_COUNT]; // 쓰레드 배열
    int thread_nums[THREAD_COUNT] = {0, 1, 2, 3}; // 쓰레드 번호

    // 뮤텍스 초기화
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        printf("Mutex initialization failed\n");
        return 1;
    }

    // 쓰레드 생성
    for (int i = 0; i < THREAD_COUNT; i++) {
        if (pthread_create(&threads[i], NULL, thread_func, &thread_nums[i]) != 0) {
            printf("Thread creation failed\n");
            return 1;
        }
    }

    // 쓰레드 조인
    for (int i = 0; i < THREAD_COUNT; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            printf("Thread join failed\n");
            return 1;
        }
    }

    // 뮤텍스 해제
    pthread_mutex_destroy(&mutex);

    return 0;
}