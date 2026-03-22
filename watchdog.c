#include <stdio.h>


void check(int c, int *a)
{
    if (*a >= 5)
    {
        printf("Cycle %d\nSensor timeout detected! (%d cycles without data)\n",
               c, *a);
    }
}

int main()
{
    int a = 0; //missed cycles counter

    for (int c = 1; c <= 10; c++)
    {
        int d;
        printf("Enter data: (If no data available then enter 0)\n");
        scanf("%d", &d);

        if (d)
        {
            printf("Cycle %d\nData received\n", c);
            a = 0; 
        }
        else
        {
            a++;
            printf("Cycle %d\nNo data recieved (missed: %d)\n", c, a);
        }

        check(c, &a);
    }

    return 0;
}
