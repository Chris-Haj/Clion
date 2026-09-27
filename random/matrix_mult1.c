#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define DIM_MATRIX 3

typedef struct {
    int mat1[DIM_MATRIX][DIM_MATRIX];
    int mat2[DIM_MATRIX][DIM_MATRIX];
    int mat3[DIM_MATRIX][DIM_MATRIX];
} Matricies;


int main() {
    Matricies *shared;
    key_t key= ftok("/tmp",'a');
    int sharedID = shmget(key, sizeof(Matricies), IPC_CREAT | 0600);
    if (sharedID == -1) {
        perror("memory issuing failure");
    }
    if ((shared = (Matricies *) shmat(sharedID, 0, 0)) < 0) {
        perror("memory attaching failure");
    }
    printf("Please enter 9 numbers for the first matrix\n");
    for(int i=0;i<DIM_MATRIX;i++)
        for(int j=0;j<DIM_MATRIX;j++)
            scanf("%d",&shared->mat1[i][j]);

    printf("Please enter 9 numbers for the second matrix\n");
    for(int i=0;i<DIM_MATRIX;i++)
        for(int j=0;j<DIM_MATRIX;j++)
            scanf("%d",&shared->mat2[i][j]);

    shmdt(shared);
    system("./second");
}