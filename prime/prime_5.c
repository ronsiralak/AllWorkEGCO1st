#include <pthread.h>
#include <stdio.h>


void compute_prime (void* arg) {

    int candidate = ((int) arg), n = candidate + 100;
    while (1) {
        int factor, is_prime = 1;
        for (factor = 2; factor < candidate; ++factor)
            if (candidate % factor == 0) {
                is_prime = 0;
                break;
            }

        if (is_prime) {
            printf(" %d ",candidate);


        }
        if(candidate == n)
            return (void) candidate;
        ++candidate;
    }
    return NULL;
}
int main () {
    pthread_t thread_1,thread_2,thread_3,thread_4,thread_5;
int which_prime = 5133, prime;

    int thread1_args = 0;

    pthread_create (&thread_1, NULL, &compute_prime, &thread1_args);
    pthread_join (thread_1, NULL);
    printf("The %dth prime number is %d.\n", which_prime, prime);
    return 0;
}
