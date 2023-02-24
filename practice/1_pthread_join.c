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

    printf("Main thread is waiting for child thread\n");
    void *retval;
    ret = pthread_join(thread, &retval);
    if (ret != 0) {
        printf("Failed to join thread\n");
        return 1;
    }

    printf("Child thread returned %ld\n", (long)retval);
    printf("Main thread is about to exit\n");
    return 0;
}
