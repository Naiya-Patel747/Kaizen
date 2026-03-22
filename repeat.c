#include<stdio.h>
#include<string.h>

char check(char *p, int i)
{
    if (i >= 2 && *p == *(p-1) && *(p-1) == *(p-2))
        return 'N';
    return 'Y';
}

int main()
{

char a[20];
char *p;
p = a;
for (int i = 0; i < 10; i++)
{
    printf("Enter command:\n(L - Left) (R- Right)\n");
    
    scanf("%c",p);
    while(getchar()!='\n');
    if (i >= 2)
    {
        if (check(p, i) == 'N')
        {
            printf("Repeat Command Detected: %c\n",*p);
        }
    }
    p++;
}

    return 0;
}