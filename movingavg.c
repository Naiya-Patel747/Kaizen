#include<stdio.h>
int add(int *p, int n);

int main()
{
    int a[100]={};
    int n;
    int *p = a;  
    float avg;
    int sum = 0;
    printf("Enter window size:");
    scanf("%d",&n);
    int i = 1;
    while (i > 0)
    {
        printf("Enter sensor values:\n");
        scanf("%d",p);
        if (i<n)
            {
                sum += *p;
                avg = (float) sum/i;
                printf("Moving Average: %.2f\n", avg);
                p++;
            }
        else if (i >= n && i < 100)
            {
                avg = (float) add(p, n)/n;
                printf("Moving Average: %.2f\n", avg);
                p++;
            }
        i++;
    }
return 0;
}
int add(int *p, int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            {
                sum += *(p - i);
            }
        return sum;
    }

