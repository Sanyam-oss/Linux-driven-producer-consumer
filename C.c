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

#define SYS_reader 450


int main(){

    for(int i=0 ; i<1;i++){

        long num ;

        int ver = syscall(SYS_reader, &num);

        if(ver == -1){
            printf("Deque unsuccessful !\n");
        }

        else{
            printf("%ld Recieved \n",num);
        }
    }
}