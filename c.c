#include <stdio.h>
#include <unistd.h>

void print_white(int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
        printf("-");
}

int main(void)
{
    int white = 0;
    int tag = 0;
    for (int i = 0; i < 2; i++) {
        printf("%d->", getpid());
        pid_t PID = fork();

        if (PID) {
            tag++;
        }

        /*       if (!PID) {
                    white++;
                }
                printf("%d ", getpid());
                print_white(white);
                printf("%d\n", i);
        */
        // printf("%d\n", i);
        printf("%d->%d-%d ", getpid(), i, tag);
    }
    /*
        if (!white){
            printf("First parent die\n");
        }
    */
    /*    printf("!\n");
        fflush(stdout);
        printf("!\n");*/
    return 0;
}
