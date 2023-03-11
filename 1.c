#include <stdio.h>
//#include <math.h>

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h>
#include <sys/resource.h>
#define BILLION 1000000000L;

void *countA(void *fp)
{
    struct timespec start, stop;
    double accum;
    if (clock_gettime(CLOCK_REALTIME, &start) == -1)
    {
        perror("clock gettime");
        // return EXIT_FAILURE;
        return NULL;
    }
    unsigned long int count = 0;
    for (unsigned long int i = 0; i < 4294967295; i++)
    {
        count += 1;
    }
    // printf("A");

    if (clock_gettime(CLOCK_REALTIME, &stop) == -1)
    {
        perror("clock gettime");
        // return EXIT_FAILURE;
        return NULL;
    }
    accum = (stop.tv_sec - start.tv_sec) + (double)(stop.tv_nsec - start.tv_nsec) / (double)BILLION;

    // printf("%ld",stop.tv_nsec - start.tv_nsec);
    printf("Count A: %lf\n", accum);
    fprintf(fp, "A %lf\n", accum);

    return NULL;
}

void *countB(void *fp)
{
    struct timespec start, stop;
    double accum;
    if (clock_gettime(CLOCK_REALTIME, &start) == -1)
    {
        perror("clock gettime");
        // return EXIT_FAILURE;
        return NULL;
    }
    unsigned long int count = 0;
    for (unsigned long int i = 0; i < 4294967295; i++)
    {
        count += 1;
    }
    // printf("A");

    if (clock_gettime(CLOCK_REALTIME, &stop) == -1)
    {
        perror("clock gettime");
        // return EXIT_FAILURE;
        return NULL;
    }
    accum = (stop.tv_sec - start.tv_sec) + (double)(stop.tv_nsec - start.tv_nsec) / (double)BILLION;

    // printf("%ld",stop.tv_nsec - start.tv_nsec);
    printf("Count B: %lf\n", accum);
    fprintf(fp, "B %lf\n", accum);

    return NULL;
}

void *countC(void *fp)
{
    struct timespec start, stop;
    double accum;
    if (clock_gettime(CLOCK_REALTIME, &start) == -1)
    {
        perror("clock gettime");
        // return EXIT_FAILURE;
        return NULL;
    }
    unsigned long int count = 0;
    for (unsigned long int i = 0; i < 4294967295; i++)
    {
        count += 1;
    }
    // printf("A");

    if (clock_gettime(CLOCK_REALTIME, &stop) == -1)
    {
        perror("clock gettime");
        // return EXIT_FAILURE;
        return NULL;
    }
    accum = (stop.tv_sec - start.tv_sec) + (double)(stop.tv_nsec - start.tv_nsec) / (double)BILLION;

    // printf("%ld",stop.tv_nsec - start.tv_nsec);
    printf("Count C: %lf\n", accum);
    fprintf(fp, "C %lf\n", accum);

    return NULL;
}

// implement count vaali cheez, make this function better and make historgram

int main()
{

    FILE *fp;
    fp = fopen("data.txt", "a");

    pthread_t thread_id_oth, thread_id_rr, thread_id_fifo;
    pthread_attr_t attr_rr, attr_oth, attr_fifo;

    struct sched_param schedparam;

    printf("Deafult priority\n");

    schedparam.sched_priority = nice(0);
    int tst;
    pthread_attr_init(&attr_oth);
    pthread_attr_setinheritsched(&attr_oth, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&attr_oth, SCHED_OTHER);
    pthread_attr_setschedparam(&attr_oth, &schedparam);

    schedparam.sched_priority = sched_get_priority_max(SCHED_RR);
    pthread_attr_init(&attr_rr);
    pthread_attr_setinheritsched(&attr_rr, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&attr_rr, SCHED_RR);
    pthread_attr_setschedparam(&attr_rr, &schedparam);

    schedparam.sched_priority = sched_get_priority_max(SCHED_FIFO);
    pthread_attr_init(&attr_fifo);
    pthread_attr_setinheritsched(&attr_fifo, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&attr_fifo, SCHED_FIFO);
    pthread_attr_setschedparam(&attr_fifo, &schedparam);

    pthread_create(&thread_id_rr, &attr_rr, countB, (void *)fp);
    pthread_create(&thread_id_oth, &attr_oth, countA, (void *)fp);
    pthread_create(&thread_id_fifo, &attr_fifo, countC, (void *)fp);
    // pthread_attr_destroy(&attr);

    pthread_join(thread_id_rr, NULL);
    pthread_join(thread_id_oth, NULL);
    pthread_join(thread_id_fifo, NULL);

    for (int i = 0; i < 10; i++)
    {

        int pro = 5 + 3 * i;
        printf("Priority: %d\n", pro);
        schedparam.sched_priority =pro;
        pthread_attr_init(&attr_rr);
        pthread_attr_setinheritsched(&attr_rr, PTHREAD_EXPLICIT_SCHED);
        pthread_attr_setschedpolicy(&attr_rr, SCHED_RR);
        pthread_attr_setschedparam(&attr_rr, &schedparam);

        schedparam.sched_priority = nice(0);
        pthread_attr_init(&attr_oth);
        pthread_attr_setinheritsched(&attr_oth, PTHREAD_EXPLICIT_SCHED);
        pthread_attr_setschedpolicy(&attr_oth, SCHED_OTHER);
        pthread_attr_setschedparam(&attr_oth, &schedparam);

        schedparam.sched_priority = pro;
        printf("%d",schedparam.sched_priority);
        pthread_attr_init(&attr_fifo);
        pthread_attr_setinheritsched(&attr_fifo, PTHREAD_EXPLICIT_SCHED);
        pthread_attr_setschedpolicy(&attr_fifo, SCHED_FIFO);
        pthread_attr_setschedparam(&attr_fifo, &schedparam);
        printf("%d",pthread_attr_setschedparam(&attr_fifo, &schedparam));

        pthread_create(&thread_id_rr, &attr_rr, countB, (void *)fp);
        pthread_create(&thread_id_oth, &attr_oth, countA, (void *)fp);
        pthread_create(&thread_id_fifo, &attr_fifo, countC, (void *)fp);

        pthread_join(thread_id_rr, NULL);
        pthread_join(thread_id_oth, NULL);
        pthread_join(thread_id_fifo, NULL);
    }

    fclose(fp);

    return 0;
}