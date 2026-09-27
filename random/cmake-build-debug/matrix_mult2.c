#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

#define DIM_MATRIX 3

typedef struct {
    int mat1[DIM_MATRIX][DIM_MATRIX];
    int mat2[DIM_MATRIX][DIM_MATRIX];
    int mat3[DIM_MATRIX][DIM_MATRIX];
} Matricies;


int main() {
    Matricies *shared;
    pid_t pid[3];
    int status;
    key_t key = ftok("/tmp", 'a');
    int sharedID = shmget(key, sizeof(Matricies), 0600);
    if (sharedID == -1) {
        perror("memory issuing failure");
    }
    if ((shared = (Matricies *) shmat(sharedID, 0, 1)) < 0) {
        perror("memory attaching failure");
    }
    for (int i = 0; i < DIM_MATRIX; i++) {
        for (int j = 0; j < DIM_MATRIX; j++) {
            for (int k = 0; k < DIM_MATRIX; k++) {
                if ((pid[i] = fork()) == 0) {
                    shared->mat3[i][j] += shared->mat1[i][k] * shared->mat2[k][j];
                    exit(0);
                } else if (pid[i] < 0) {
                    perror("fork failure");
                    exit(1);
                }
            }
        }
    }
    for (int i = 0; i < DIM_MATRIX; i++)
        waitpid(pid[i], &status, 0);
    for (int i = 0; i < DIM_MATRIX; i++) {
        for (int j = 0; j < DIM_MATRIX; j++) {
                printf("%d ", shared->mat3[i][j]);
        }
        printf("\n");
    }
    shmdt(shared);
    shmctl(sharedID, IPC_RMID, 0);
}