#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    if (argc == 1)
        printf(1, "\nSystemcall Number needed !");
    else
    {
        int systemCallNum = atoi(argv[1]);

        int id = fork();
        if (id > 0)
        {
            wait();
            printf(1, "This is process %d and the parent id is %d", getpid(), getParentID());
            printf(1, "  (systemcall %d : %d times)\n", systemCallNum, getSyscallCounter(systemCallNum));

            id = fork();
            if (id > 0)
            {
                wait();
                printf(1, "This is process %d and the parent id is %d", getpid(), getParentID());
                printf(1, "  (systemcall %d : %d times)\n", systemCallNum, getSyscallCounter(systemCallNum));
            }
            else if (id == 0)
            {
                printf(1, "This is process %d and the parent id is %d", getpid(), getParentID());
                printf(1, "  (systemcall %d : %d times)\n", systemCallNum, getSyscallCounter(systemCallNum));
            }
        }
        else if (id == 0)
        {
            printf(1, "This is process %d and the parent id is %d", getpid(), getParentID());
            printf(1, "  (systemcall %d : %d times)\n", systemCallNum, getSyscallCounter(systemCallNum));

            id = fork();
            if (id > 0)
            {
                wait();
                printf(1, "This is process %d and the parent id is %d", getpid(), getParentID());
                printf(1, "  (systemcall %d : %d times)\n", systemCallNum, getSyscallCounter(systemCallNum));
            }
            else if (id == 0)
            {
                printf(1, "This is process %d and the parent id is %d", getpid(), getParentID());
                printf(1, "  (systemcall %d : %d times)\n", systemCallNum, getSyscallCounter(systemCallNum));
            }
        }
    }

    exit();
}