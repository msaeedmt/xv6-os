#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    int n1 = fork();
    int n2 = fork();
    int n3 = fork();

    if (n1 > 0 && n2 > 0 && n3 > 0)
    {
        int *childes[63];
        memset(childes, 0, 63);
        int *newChildes = getChildren(*childes);
        int i;
        printf(1,"This is process %d and children are ",getpid());
        for (i = 0; newChildes[i]>0 ; i++)
        {
            printf(1,"%d ", newChildes[i]);
        }
    }

    while(wait() != -1) { }

    sleep(1);

    exit();
}