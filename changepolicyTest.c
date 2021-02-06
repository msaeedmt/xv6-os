#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    if (argc == 1)
        printf(1, "\nNew policy Number needed !");
    else
    {
        int newPolicy = atoi(argv[1]);
        switch (changePolicy(newPolicy))
        {
        case 0:
            printf(1, "Policy changed to Default\n");
            break;
        case 1:
            printf(1, "Policy changed to Roundrobin\n");
            break;
        case 2:
            printf(1, "Policy changed to Priority\n");
            break;
        }
    }

    exit();
}