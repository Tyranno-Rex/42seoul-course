#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *thread_func(void *arg) {
    printf("Child thread is running\n");
    sleep(3);
    printf("Child thread is about to exit\n");
    return (void *)42;
}

int main() {
    pthread_t thread;
    int ret = pthread_create(&thread, NULL, thread_func, NULL);
    if (ret != 0) {
        printf("Failed to create thread\n");
        return 1;
    }

    ret = pthread_detach(thread);
    if (ret != 0) {
        printf("Failed to detach thread\n");
        return 1;
    }

    printf("Main thread is continuing\n");
    sleep(5);
    printf("Main thread is about to exit\n");
    return 0;
}