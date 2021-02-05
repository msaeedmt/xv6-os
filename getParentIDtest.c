#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    int id;

    id = fork();
    if (id > 0)
    {
        /*parent process*/
        wait();
        printf(1, "This is process %d and the parent id is %d\n", getpid(), getParentID());
        id = fork();
        if (id > 0)
        {
            /*parent process*/
            wait();
            printf(1, "This is process %d and the parent id is %d\n", getpid(), getParentID());
        }
        else if (id == 0)
        {
            printf(1, "This is process %d and the parent id is %d\n", getpid(), getParentID());
        }
    }
    else if (id == 0)
    {
        printf(1, "This is process %d and the parent id is %d\n", getpid(), getParentID());
        id = fork();
        if (id > 0)
        {
            /*parent process*/
            wait();
            printf(1, "This is process %d and the parent id is %d\n", getpid(), getParentID());

        }
        else if (id == 0)
        {
            printf(1, "This is process %d and the parent id is %d\n", getpid(), getParentID());

        }
    }
    exit();
}