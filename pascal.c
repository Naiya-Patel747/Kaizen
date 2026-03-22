#include<stdio.h>

int main()
{
    int n,num;
    printf("Enter number of rows for Pascal's Triangle:\n");
    scanf("%d",&n);
    printf("==== The Pascal's Triangle ====\n");
    for (int i=0;i<n;i++)
    {
        num=1;

        for (int j=0;j<=i;j++)
        {
            printf("%d ",num);
            num=num*(i-j)/(j+1); 
        }
        printf("\n");
    }
return 0;
}