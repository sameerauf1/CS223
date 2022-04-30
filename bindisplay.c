#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int input;
	int temp_Shift;
	int test = 1;// mask
	int space = 1;
	printf("Enter an integer: \n");
	scanf("%d", &input);
/*	
	temp_Shift = input >> 3;
	if(temp_Shift & 1)
	{
		printf("1");
	}
	else
	{
		printf("0");
	}
	
	//printf("%d shifted right:\n", temp_Shift);
	temp_Shift = input >> 2;
	if(temp_Shift & 1)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	//	printf("%d shifted right:\n", temp_Shift);
		temp_Shift = input >> 1;
		if(temp_Shift & 1)
			{
				printf("1");
			}
			else
			{
				printf("0");
			}
		
		//	printf("%d shifted right:\n", temp_Shift);
	*/
	
	for(int i = 31; i > -1; --i)
	{
	//printf("ehlo");
		temp_Shift = input >>i; 		
		if(temp_Shift & 1)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		if(space % 4 == 0)
		{
			printf(" ");
		}
		++space;
		
		
	}
//	printf("whats up homie");
}
