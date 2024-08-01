#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 100
#define NUM_THREADS 5

int array[ARRAY_SIZE];
long partialSums[NUM_THREADS] = {0};

// Function that each thread will execute
void *threadFunction(void *threadID) {
    long tid = (long)threadID;
    int start = tid * (ARRAY_SIZE / NUM_THREADS);
    int end = (tid + 1) * (ARRAY_SIZE / NUM_THREADS);

    // Calculate the sum of elements in the assigned section
    for (int i = start; i < end; i++) {
        partialSums[tid] += array[i];
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 10;
    }

    // Create threads
    for (t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, threadFunction, (void *)t);

        if (rc) {
            printf("Error: Return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    // Calculate the total sum from partial sums
    long totalSum = 0;
    for (t = 0; t < NUM_THREADS; t++) {
        totalSum += partialSums[t];
        printf("the sum of %ld row =%ld\n",t+1,partialSums[t]);
    }

    printf("Total sum: %ld\n", totalSum);

    pthread_exit(NULL);
    return 0;
}

