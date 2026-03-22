#include<stdio.h>

int main(){
     char str[120];
     float a[6];
     int num=0;
     char mode[25]={};
     int c=0,range=0,d=0,k=0;
     float sd[4];
     printf("Enter command:\n");
     scanf("%s",str);
     //printf("str = %s\n", str);
     for (int i=0; str[i] != '\0'; i++)
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
                else if ((str[i]>='a' && str[i]<='z')||(str[i]>='A' && str[i]<='Z'))
                {   
                    mode[d]=(char)str[i];
                    d++;   
                }
            }
    }
    mode[d]='\0';
    a[c] = num;
    range = (int)a[1];
    for(int i=2;i<6;i++)
    {
        
        sd[k]=a[i]/10.0;
        k++;
    }
    printf("\nMODE: %s\n",mode);
    printf("RANGE: %d\n",range);
    printf("SPEED: ");
    
    for (int j=0;j<4;j++)
    {
        printf("%.1f ",sd[j]);
    }
return 0;
}