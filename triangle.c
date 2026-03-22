#include<stdio.h>
#include<math.h>
#include <string.h>
int main()
{
    float a,b,c;
    char t[30];
    printf("Enter 3 sides of a triangle:\n");
    scanf("%f %f %f", &a,&b,&c);
    
    if ((a+c)>b && (a+b)>c && (b+c)>a)
    {
        printf("Input is valid.\n");
        if (a == b && b == c)
        {
            strcpy(t, "Equilateral Triangle");
            printf("It is a/an %s",t);
            
        }
        else if (a==b||b==c||a==c)
        {
            if((a == b && (a*a + b*b) == 2*c*c) || (b == c && (c*c + b*b) == 2*a*a) || (a == c && (a*a + c*c) == 2*b*b))
                {
                    strcpy(t, "Right Angled Isoceles Triangle");
                    printf("It is a/an %s",t);
                }
            else
            {
                strcpy(t, "Isoceles Triangle");
                printf("It is a/an %s",t);
            }
        }
        else 
        {
            strcpy(t, "Scalene Triangle");
            printf("It is a/an %s",t);
        }
    }
    else
    {
        printf("Invalid Inputs!\nTriangle is not possible");
    } 
return 0;
}