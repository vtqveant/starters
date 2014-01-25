#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void *thread_fn(void *arg) {
    int *pth_num = (int *) arg;
    fprintf(stdout, "thread #%d started\n", *pth_num);
    usleep(10000);
    fprintf(stdout, "thread #%d done\n", *pth_num);
    return NULL;
}


int main(int argc, char **argv) {

    /* ten pointers for ten threads */
    pthread_t pths[10];
    int nrs[10];

    int i;
    for (i = 0; i < 10; i++) {
        nrs[i] = i+1;
        pthread_create(&pths[i], NULL, thread_fn, &nrs[i]);
    }

    fprintf(stdout, "main() waiting for thread #6 to terminate\n");
    pthread_join(pths[5], NULL);

    exit(EXIT_SUCCESS);
}
