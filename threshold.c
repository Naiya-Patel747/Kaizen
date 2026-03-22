#include<stdio.h>

int main()
{
    int n=0;
    printf("Enter number of sensor values:\n");
    scanf("%d",&n);

    int a[n];
    printf("Enter sensor values:\n");
    
    for (int i = 0 ;i < n; i++)
    {
        scanf("%d",&a[i]);
        if (a[i]<9)
        {
            printf("Alert triggered at: %d\n",a[i]);
        }
    }
    return 0;
}
