#include<stdio.h>

int main()
{
    int n,num=1;
    printf("Enter number of rows for Floyd's Triangle:\n");
    scanf("%d",&n);
    printf("==== The Floyd's Triangle ====\n");
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=i;j++)
        {
            printf("%d ",num);
            num++; 
        }
        printf("\n");
    }
    for (int i=n;i<=n;i--)
    {
        for (int j=i;j<=i&&j>0;j--)
        {
            printf("%d ",num);
            num++; 
        }
        printf("\n");
    }
return 0;
}