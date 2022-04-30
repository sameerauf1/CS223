#include <stdio.h>
#include <stdbool.h>
// i think i need to create a while loop that will go forever
// the only way to exit the loop should be ctrl-d
int main()
{
auto long max = 0; // used to keep track of max
auto long min = 0; // used to keep track of min
auto long zero = 0;
auto long count; // used to keep track of how many #s user will enter
auto long temp;  // temporary variable to hold value for comparison of max and min
printf("How many numbers would you like to enter?\n");
scanf("%ld", &count);
//printf("%ld",count); //check if count is getting correct data

	while( zero < count && count !=1 && count >0 ) //loop will run as long as the count is not 1 and till the user has entered x numbers
	{
	scanf("%ld", &temp);
	if(temp >= max)
	{
		max = temp;
	}
	if(temp <= min)
	{
		min = temp;
	}
	++zero;
	}
	if(count > 1)
	{
	printf("The max is: %ld \n", max);
	printf("The min is: %ld\n", min);
	}
	else if(count ==1)
	{
		scanf("%ld", &temp);
		printf("You only entered one value: %ld \n",temp);
		max = temp;
		min = temp;
		printf("The max is: %ld \n", max);
		printf("The min is: %ld\n", min);
		
	}
	if(count <=0)
	{
	printf("You have selected to enter  0 or less numbers, there is no min or max\n");
			
	}	

}
