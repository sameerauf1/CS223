#include <stdio.h>
#include <stdlib.h>
	int pennies = 0;
	int dollars = 0;
	int halfDollars = 0;
	int quarters = 0;
	int dimes = 0;
	int nickels = 0;
void MakeChange( int *dollars, int *halfDollars, int *quarters, int *dimes, int *nickels, int *pennies)
{
	//if(*pennies /100 >= 0)
	//{
		*dollars = *pennies / 100; // 299 /200 = 2
		*pennies = *pennies % 100; // 299/ 100 = 99, this is left over
		
	//	printf("you hae %d dollars", *dollars);	
		
		*halfDollars = *pennies / 50; // 99/50 = 1
		*pennies = *pennies % 50; // 99 % 50 = 49, this is left over
		
		*quarters = *pennies / 25; // 49/25 = 1
		*pennies = *pennies % 25; // 24 % 25 = 24, this is left over 

		*dimes = *pennies / 10; // 24/ 10 = 2
		*pennies = *pennies % 10; // 4 % 10 = 4, tis is left over

		*nickels = *pennies / 5; // 4/5 = 0
		*pennies = *pennies % 5; // 4 %5 = 4, this is left over


		

				
	//}
	
//	*dollars = *pennies / 100;
//	printf("you hae %d dollars", *dollars);	
/*	if(*pennies / 100 >= 0)
	{
	//printf("pennies %d", *pennies);
	int dollarsTemp = 0;
	dollarsTemp = *pennies/ 100;
	dollars = &dollarsTemp;
	int count = 0;
	++count;
//	&dollars = *pennies / 100;

		printf( " you have %d dollars \n", *dollars);
		printf( " you have %d dollars temp \n", dollarsTemp);
		printf( " you have %d dollars count \n", count);
/*	if(*pennies / 50 >= 0)
	{
		int halfDollarsTemp = 0;
		halfDollars = &halfDollarsTemp
		
		printf
		
		
	}
	}*/
	
}

int main()
{


	
	printf("Please enter the total number of pennies: ");
	scanf("%d", &pennies);
//	int *penniesPtr = &pennies;
	//int &penniesPtr = pennies;
//	int *dollarsPtr = &dollars;
//	int *halfDollarsPtr = &halfDollars;
//	int *quartersPtr = &quarters;
//	int *dimesPtr = &dimes;
//	int *nickelsPtr = &nickels;
	
	//printf("pennies varaible: %d\n", pennies);
	//printf("pennies varaible: %d\n", *penniesPtr);
	//MakeChange(dollarsPtr, halfDollarsPtr, quartersPtr, dimesPtr, nickelsPtr, penniesPtr);
	MakeChange(&dollars, &halfDollars, &quarters, &dimes, &nickels, &pennies);
//	printf("you have %d dollarsptr\n", *dollarsPtr);
	printf("Here is the currency equivalent: \n");
	if(dollars >1 || dollars ==0)
	{
	printf("  %d dollars\n", dollars);

	}
	if(dollars ==1)
	{
	printf("  %d dollar\n", dollars);

	}
	
	if(halfDollars > 1 || halfDollars ==0)
	{
		printf("  %d half dollars\n", halfDollars);
	}
	if(halfDollars == 1)
	{
		printf("  %d half dollar\n", halfDollars);
	}
	
	if(quarters > 1 || quarters ==0)
	{
		printf("  %d quarters\n", quarters);
	}
	if(quarters == 1)
	{
		printf("  %d quarter\n", quarters);
	}
	if(dimes > 1 || dimes ==0)
	{
		printf("  %d dimes\n", dimes);
	}
	if(dimes == 1)
	{
		printf("  %d dime\n", dimes);
	}

	if(nickels > 1 || nickels ==0)
	{
		printf("  %d nickels\n", nickels);
	}
	if(nickels == 1)
	{
		printf("  %d nickel\n", nickels);
	}
	if(pennies > 1 || pennies ==0)
	{
		printf("  %d pennies\n", pennies);
	}
	if(pennies == 1)
	{
		printf("  %d penny\n", pennies);
	}
	
	
}

