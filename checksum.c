#include<stdio.h>

int main(){
     char str[100] ;
     int a[100]={};
     int *p = a;  
     int sum = 0;
     int num=0;
     int c=0;
     printf("Enter packet (comma seprated):\n");
     scanf("%s",str);
     for (int i = 0; str[i] != '\0'; i++)
     {
        if(str[i]==','||str[i]=='\0')
        {
            a[c]=num;
            num=0;
            c++;
        }
        else if(str[i]!=','||str[i]!='\0')
        {  
           if (str[i]>='0' && str[i]<='9')
            {   
                num=(num*10)+(str[i]-'0');
                
            }
        }

     }
    p = a;
    for (int i = 0; i < c-1; i++)
    {
        sum += *p;  
        p++;        
    }
    if (sum == a[c-1])
    {
        
        printf("The packet is valid\nSum(%d) = %d", sum,a[c-1]);
    }
    else 
    {
        printf("The packet is invalid\n");
    }
    
return 0;
}