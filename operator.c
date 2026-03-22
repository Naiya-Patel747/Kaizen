#include <stdio.h>

int main()
{
    float a, b, result;
    char op;

    printf("Enter first number: ");
    scanf("%f", &a);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Enter second number: ");
    scanf("%f", &b);

    if (op == '+')
    {
        result = a + b;
        printf("%.2f + %.2f = %.2f", a, b, result);
    }
    else if (op == '-')
    {
        result = a - b;
        printf("%.2f - %.2f = %.2f", a, b, result);
    }
    else if (op == '*')
    {
        result = a * b;
        printf("%.2f * %.2f = %.2f", a, b, result);
    }
    else if (op == '/')
    {
        if (b == 0)
        {
            printf("Error: Division not allowed!");
        }
        else
        {
            result = a / b;
            printf("%.2f / %.2f = %.2f", a, b, result);
        }
    }
    else
    {
        printf("Error: Invalid operator '%c'!", op);
    }

    return 0;
}