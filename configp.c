#include<stdio.h>
#include<math.h>


int main()
{
    char str[100]={};
    int d = 0;
    char para[100];
    float num = 0;
    int t = 0;
    int div = 1;

    printf("Enter a configuration value:\nFormat parameter=value\n");
    scanf("%s",str);
    while(getchar()!='\n');

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != '=' && (str[i]>='a' && str[i]<='z')||(str[i]>='A' && str[i]<='Z'||str[i]== '_'))
        {
            para[d] = str[i];
            d++;
        }
        
        else if (str[i] != '=' && str[i]>='0' && str[i]<='9')
        {  
            if (!t)
            {
                num=(num*10)+(str[i]-'0');          
            }
            else
            {
                div *= 10;
                num = num + (float)(str[i]-'0')/ div;
            }
            
        }
        else if (str[i]=='.')
        {
            if (t)
            {
                break;
            }
            t = 1;
        }
    }
    para[d] = '\0'; //finish storing in the array
    printf("Parameter: %s\n", para);
    printf("Value: %.2f\n", num);

    return 0;
}