#include<stdio.h>

int main()
{
    float min = -100;
    float max = 100;
    float value;
    printf("The allowed motor range is from %.2f to %.2f\n",min,max);
    printf("Enter motor command value: \n");
    scanf("%f",&value);
    if(value > max || value < min)
    {
        printf("The value is out of range.\n");
        if (value > max)
        {
            value = max;
        }
        if (value < min)
        {
            value = min;
        }
        printf("The input value is changed to %.2f\n",value);
    }
    else 
    {
        printf("The value is in the range.\n");
    }
    printf("Success");
    return 0;
}