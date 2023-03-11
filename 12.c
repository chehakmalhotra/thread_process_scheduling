#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sched.h>




int main(){
    FILE *fp;
    fp=fopen("mata.txt","a");
    struct sched_param par1, par2, par3;
    struct timespec start, stop1, stop2, stop3;
    double accum;
    if( clock_gettime( CLOCK_REALTIME, &start) == -1 ) {
        perror( "clock gettime" );
        return EXIT_FAILURE;
        //return NULL;
    }

    pid_t pid1=fork();
    pid_t pid2=fork();
    pid_t pid3=fork();

    if(pid1==0 && pid2>0 && pid3>0){
        par1.sched_priority=10;
        sched_setscheduler(pid1,SCHED_OTHER,&par1);
        execl("/bin/bash","/bin/bash","bashy1.sh",NULL);
        //sleep(1);
        
    }
    else if(pid2==0 && pid1>0 && pid3>0){
        par2.sched_priority=20;
        sched_setscheduler(pid2,SCHED_RR,&par2);
        execl("/bin/bash","/bin/bash","bashy2.sh",NULL);
        //sleep(1);

        
    }
    else if(pid3==0 && pid1>0 && pid2>0){
        par3.sched_priority=30;
        sched_setscheduler(pid3,SCHED_FIFO,&par3);
        execl("/bin/bash","/bin/bash","bashy3.sh",NULL);
        //sleep(1);

        
    }
    else if (pid1 > 0 && pid2 > 0 && pid3 > 0){
        waitpid(pid1,NULL,0);
    //     if( clock_gettime( CLOCK_REALTIME, &stop1) == -1 ) {
    //     perror( "clock gettime" );
    //     return EXIT_FAILURE;
    //     //return NULL;
    // }
    // accum = ( stop1.tv_sec - start.tv_sec )
    //         + (double)( stop1.tv_nsec - start.tv_nsec )
    //           /(double) 1000000000L;
    //           printf("%ld\n",stop1.tv_nsec - start.tv_nsec);
    //           fprintf(fp,"process1 %lf\n", accum);
        waitpid(pid2,NULL,0);
    //     if( clock_gettime( CLOCK_REALTIME, &stop2) == -1 ) {
    //     perror( "clock gettime" );
    //     return EXIT_FAILURE;
    //     //return NULL;}
    //     }
    
    // accum = ( stop2.tv_sec - start.tv_sec )
    //         + (double)( stop2.tv_nsec - start.tv_nsec )
    //           /(double) 1000000000L;

    //     printf("%ld\n",stop2.tv_nsec - start.tv_nsec);
    //     fprintf(fp,"  process 2 %lf\n", accum);

        waitpid(pid3,NULL,0);
    //     if( clock_gettime( CLOCK_REALTIME, &stop3) == -1 ) {
    //     perror( "clock gettime" );
    //     return EXIT_FAILURE;
    //     //return NULL;
    //     }
    // accum = ( stop3.tv_sec - start.tv_sec )
    //         + (double)( stop3.tv_nsec - start.tv_nsec )
    //           /(double) 1000000000L;

    //           printf("%ld\n",stop3.tv_nsec - start.tv_nsec);
    //           fprintf(fp,"process3 %lf\n", accum);
    }

    fclose(fp);
    
}
