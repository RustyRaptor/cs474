#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <stdlib.h>

#define SHMKEY ( ( key_t )1497 )

typedef struct {
        int value;
} shared_mem;

static shared_mem *total;

static _Noreturn void process1( ) {
        printf( "this is process1 \n" );

        total->value += 1;

        exit( 0 );
}

static _Noreturn void process2( ) {
        printf( "this is process2 \n" );

        total->value += 1;

        exit( 0 );
}

static _Noreturn void process3( ) {
        printf( "this is process3 \n" );

        total->value += 1;

        exit( 0 );
}

static _Noreturn void process4( ) {
        printf( "this is process4 \n" );

        total->value += 1;

        exit( 0 );
}

int main( ) {
        key_t key = ftok( "./", 1234 );

        if ( key == -1 ) {
                perror( "ftok" );
        }


        int shmid, pid1, pid2, pid3, pid4, ID, status;

        char *shmadd;

        shmadd = ( char * )0;

        if ( ( shmid = shmget( SHMKEY, sizeof( int ), IPC_CREAT | 0666 ) ) <
             0 ) {
                perror( "shmget" );
                exit( 1 );
        }

        if ( ( total = ( shared_mem * )shmat( shmid, shmadd, 0 ) ) ==
             ( shared_mem * )-1 ) {
                perror( "shmat" );
                exit( 0 );
        }

        total->value = 0;

        if ( ( pid1 = fork( ) ) == 0 ) {
                process1( );
        }

        if ( ( pid2 = fork( ) ) == 0 ) {
                process2( );
        }

        if ( ( pid3 = fork( ) ) == 0 ) {
                process3( );
        }

        if ( ( pid4 = fork( ) ) == 0 ) {
                process4( );
        }

        waitpid( pid1, NULL, 0 );
        waitpid( pid2, NULL, 0 );
        waitpid( pid3, NULL, 0 );
        waitpid( pid4, NULL, 0 );
}
