#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/stat.h>
#include <sys/signal.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/time.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/un.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <semaphore.h>

#define SYS_init 451
#define SYS_writer 449


int main(){

    // int v = syscall(SYS_init);
    // printf("%d\n",v);

    int fd = open("/dev/urandom", O_RDONLY);
    if(fd<0){ exit(1) ; }

    int ver , bytes ; 

    for(int i=0;i<1;i++){

        long num ;
        bytes = read( fd , &num , sizeof(num));
        printf("%ld %d\n",num,bytes);

        int ver = syscall(SYS_writer, num);

        if(ver == -1){
            printf("Enqueue failed !\n") ;
        }

        else{
            printf("Enqueue Successful !\n");
        }
    }
}