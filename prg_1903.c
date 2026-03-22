#include<stdio.h>
#include<math.h>

/*==============================================================================*/

void arithmetic (int a, int b, char o)
{
	float ans = 0;
	if (o == '+')
	{
		ans = a + b;
		printf("%.2f %c %.2f = %.2f\n",a,b,o,ans);
	}
	else if (o == '-')
	{
		ans = a - b;
		printf("%.2f %c %.2f = %.2f\n",a,b,o,ans);
	}
	else if (o == '*')
	{
		ans = a * b;
		printf("%.2f %c %.2f = %.2f\n",a,b,o,ans);
	}
	else if (o == '/')
	{
		if (b!=0)
		{
			ans = a / b;
			printf("%.2f %c %.2f = %.2f\n",a,b,o,ans);
		}
		else 
		{
			printf("Division by zero not possible!\n");			
		}
	}
}

/*==============================================================================*/

void analysis (int a, int p)
{
	switch (p){
	case 1: if (a % 2 == 0)
		{
			printf("%d is an even number\n", a);
		}
		else
		{
			printf("%d is an odd number\n", a);
		}
		break;
	
	case 2: for (int i = 1; i <= sqrt(a); i++)
		{
			if (a % i == 0)
			{
				printf("%d is NOT a prime number\n", a);
				break;
			}
			else
			{
				printf("%d is a prime number\n");
			}
		}
		break;

	default: printf("Invalid Input\n");
		 break;
	}
}

/*==============================================================================*/

void quadratic (float a, float b, float c)
{

float x = 0, y = 0;
	if ( pow(b, 2) - (4*a*c) > 0)
	{
		x = (-b + sqrt(pow(b, 2) - (4*a*c)))/ 2 * a;
		y = (-b - sqrt(pow(b, 2) - (4*a*c)))/ 2 * a;
		printf("The roots of the quadratic equation (%.2f) x^2 + (%.2f) x + (%.2f) = 0 are %.2f and %.2f\n", a, b, c, x, y);
	}
	else if ( pow(b, 2) - (4*a*c) == 0)
	{
		x = -b / (2 * a);
		y = x;
		printf("The roots of the quadratic equation (%.2f) x^2 + (%.2f) x + (%.2f) = 0 are %.2f and %.2f\n", a, b, c, x, y);
	}
	else if ( pow(b, 2) - (4*a*c) < 0)
	{
		x = (-b / 2 * a);
		y = ( sqrt(-(pow(b, 2) - (4*a*c))) )/ 2 * a;
		printf("The roots of the quadratic equation (%.2f) x^2 + (%.2f) x + (%.2f) = 0 are %.2f + i(%.2f) and %.2f - i(%.2f)\n", a, b, c, x, y, x, y);
	}
}

/*==============================================================================*/

int main(){
int t = 1, p = 0, k;
int choice = 0;
float a,b,c;
char o;


while (t)
{

printf("Enter your choice:\n1. Arithmetic Operations\n2. Number Analysis (Even/Odd and Prime)\n3. Quadratic Equation Solver\n4. Exit\n\n");
scanf("%1d",&choice);

switch (choice){

	case 1: printf("===== Arithmetic Operations =====\n");
		printf("Enter any two numbers: (separated by space)\n");
		scanf("%f %f",&a,&b);
		while(getchar()!='\n');
		printf("Enter the operater: (+ , -, *, /)\n");
		scanf("%c",&o);
		while(getchar()!='\n');

		arithmetic(a,b,o);
		printf("Arithmetic Operation Completed\n");
		break;

	case 2: printf("===== Number Analysis =====\n");
		printf("Enter any number:\n");
		scanf("%d",&k);
		while(getchar()!='\n');
		
		printf("Enter your choice:\n1. Even or Odd Check\n2. Prime Number Analysis\n");
		scanf("%1d",&p);

		analysis(k, p);
		break;

	case 3: printf("===== Roots of Quadratic Equation =====\n");
		printf("Enter the values of a, b, and c (space seperated)\nFormat: ax^2 + bx + c = 0\n");
		scanf("%f %f %f", &a, &b, &c);
		while(getchar() != '\n');

		quadratic(a, b, c);
		break;

	case 4: printf("Exiting\n");
		t = 0;
		break;

	default: printf("Invalid Input!\n");	
	}
}
	printf("Exited\n");
return 0;
}