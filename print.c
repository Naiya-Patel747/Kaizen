#include<stdio.h>
#include<string.h>

int add(int *p, int n);

int add(int *p, int n)
{
	int sum = 0;
        for (int i = 0; i < n; i++)
        {
		sum += *(p - i);
        }
        return sum;
}

int main(){

char cmd[100];
int choice = 0;
int True = 1;
float bat = 60;
int dis = 100; // in cm
char linep[6] = {"Center"};
int manual = 1;
int aut = 0;
int em = 0;
int lm = 20;
int rm = 20;
char mode[25] = {};
int a[10];
int max = 100;
int min = -100;

char pos;

int v[20] = {};
int n;
int *p = v;  
float avg; 
int sum = 0;




while (True)

{
  printf("Enter a choice from (1-6):\n1. View Robot State\n2. Update Robot State\n3. Enable Emergency Stop\n4. Manual Mode\n5. Autonomous Mode\n6. Exit\n");
  scanf("%1d", &choice);
  switch (choice){

	case 1: printf("====Current Status====\n");
		printf("Battery level: %.2f\n",bat);
		printf("Obstacle distance: %d\n",dis);
		printf("Line Position: %s\n",linep);
		if (manual == 1)
		{
			printf("Manual Mode\n");
		}
		else if (aut == 1)
		{
			printf("Automatic Mode\n");
		}
		if ( em == 0)
     		{
			printf("Emergency mode OFF\n");
		}
		else if ( em == 1)
     		{
			printf("Emergency mode ON\n");
		}
 		printf("Left Motor: %d\n",lm);
		printf("Right Motor: %d\n\n",rm);
		break;

	case 2: printf("Update value of:\n");
		printf("Battery level(in percentage):\n");
		scanf("%f",&bat);
		printf("Battery Level Updated to %.2f\n",bat);
		printf("Obstacle Distance(in cm):\n");
		scanf("%d",&dis);
		printf("Obstacle Distance Updated to %d\n",dis);
		break;

	case 3: printf("===Emergency Mode Activated===\n");
		em=1;
		int lm=0;
		int rm=0;
		printf("Left Motor: %d\n",lm);
		printf("Right Motor: %d\n\n",rm);
		break;

	case 4: manual = 1;
		aut = 0;
		printf("==== Manual Mode ON ====\n");
		while(manual)
		{
			if (em == 1)
			{ 
				printf("Emergency Mode is ON\n\n"); 
				break;
			}
			if ( dis < 20 && dis > 0)
			{ 
				printf("Obstacle too close!\nAction Required!\n\n");	
				break;
			}
			
			printf("Enter command:\nF - Move Forward\nB - Move Backward\nL - Turn Left\nR - Turn Right\nS - Stop\nThe command should be in the form: direction(space)power\nWhere power should lie between -100 to 100\n\n");
			while(getchar()!='\n');
			fgets(cmd, sizeof(cmd), stdin); 
  			cmd[strcspn(cmd, "\n")] = 0;
			
			//String Parsing

			int num=0;
     			int c=0,d=0;
			int ng = 1; //Negative value multiplier (1: Positive and -1: Negative)
			for (int i=0; cmd[i] != '\0'; i++)
     			{
        			if(cmd[i]==' '||cmd[i]=='\0')
            			{
                			a[c]=num;
                			num=0;
                			c++;
            			}
        			else if(cmd[i]!=' '||cmd[i]!='\0')
            			{  
                			if (cmd[i] == '-')
					{
						ng = -1;
					}
					else if (cmd[i]>='0' && cmd[i]<='9')
                			{   
                    				num=(num*10)+(cmd[i]-'0');
                			}
                			else if ((cmd[i]>='a' && cmd[i]<='z')||(cmd[i]>='A' && cmd[i]<='Z'))
                			{   
                    				mode[d]=(char)cmd[i];
                    				d++;   
                			}
            			}
    			}
    			mode[d]='\0';
    			a[c] = num;
			num=ng*num;
			//printf("%d",num);
			//printf("%s",mode);


			//Range Limiting
			if(num > max || num < min)
    			{
        			printf("The value is out of range.\n");
        			if (num > max)
        			{
            				num = max;
        			}
        			if (num < min)
        			{
            				num = min;
        			}
        			printf("The input value is changed to %d\n",num);
    			}
    			else 
    			{
        			printf("The power value is in the range.\n");
    			}
    			printf("Giving Commands...\n");


			/*for (int i = 0; i < d ;i++)
			{
				printf("%c\n", mode[i]);
				break;
			}*/

			//Commands

			if (mode[0] =='F' || mode[0] =='f')
			{
				printf("Move forward with %d power\n",num);
				break;
			}
			else if (mode[0] =='B' || mode[0] =='b')
			{
				printf("Move backward with %d power\n",num);
				break;
			}
			else if (mode[0] =='L' || mode[0] =='l')
			{
				printf("Turn left with %d power\n",num);
				break;
			}
			else if (mode[0] =='R' || mode[0] =='r')
			{
				printf("Turn right with %d power\n",num);
				break;
			}
			else if (mode[0] =='S' || mode[0] =='s')
			{
				printf("Stop: No power appiled\n");
				break;
			}
			else
			{
				printf("Invalid Input\n");
			}

		}	
	

	case 5: aut = 1;
		manual = 0;
		printf("==== Autonomous Mode ON ====\n");
		while (aut)
		{

		//Moving Average

    		printf("Enter window size:\n");
    		scanf("%d",&n);
		while(getchar()!='\n');

    		int i = 1;
    		while (i > 0 && i < 5)
    		{
        		printf("Enter obstacle sensor value:\n");
        		scanf("%d",p);
			while(getchar()!='\n');
        		if (i<n)
            		{
                		sum += *p;
                		avg = (float) sum/i;
                		printf("Moving Average: %.2f\n", avg);
                		p++;
            		}
        		else if (i >= n && i < 100)
            		{
                		avg = (float) add(p, n)/n;
                		printf("Moving Average: %.2f\n", avg);
                		p++;
            		}
        		i++;
    		}


		
			if (em == 1)
			{ 
				printf("Emergency Mode is ON\nRobot Stopped!\n"); 
				break;
			}
			if (avg < 30 && avg > 0) //using sensor data but in moving average form
			{ 
				printf("Obstacle too close!\nAction Required!\n");
				break;
			}
			if (manual == 1)
			{ 
				printf("Manual Mode is ON\n"); 
				break;
			}
			if (bat < 20 && bat > 0)
			{ 
				printf("Battery low!\nAction Required!");
				break;
			}

			printf("Enter line position of robot:\nC - Center\nL - Left\nR - Right\n"); //This should be input from the sensor but here we are taking user input

			while(getchar()!='\n');
			scanf("%c", &pos);
			while(getchar()!='\n');
			//printf("Input - %c\n",pos);

					
		//Commands

			if (pos == 'C' || pos == 'c')
			{
				printf("Line postion: Centre\n");
				break;
			}
			else if (pos =='L' || pos =='l')
			{
				printf("Line postion: Left\nTurning left to follow the line\n");
				break;
			}
			else if (pos =='R' || pos =='r')
			{
				printf("Line postion: Right\nTurning right to follow the line\n");
				break;
			}
		}

		
	case 6: printf("Exiting\n");
		True=0;
		break;

	default:printf("Invalid input");
		break;
        }
}
printf("Exited the program\n");
return 0;
}