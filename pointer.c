#include <stdio.h>

int main()
{
    int a[5] = {0, 0, 0, 0, 0};
    int *p = a;  
    int sum = 0;
    printf("Enter 5 integers:\n");
    for (int j = 1; j < 5; j++)
    {
        scanf("%d\n",p);
        p++;
    }
    p = a;
    for (int i = 0; i < 5; i++)
    {
        sum += *p;  
        p++;        
    }

    printf("Sum of all elements: %d\n", sum);

    
    p = a;
    p = p + 2; 

    printf("Middle element: %d\n", *p);

    return 0;
}