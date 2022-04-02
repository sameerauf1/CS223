#include <ctype.h> // hi prof, im finding that majority of the work is thinking about the problem & coding is rather less..
#include <stdio.h>

int main()
{
	int input;
	int counter = 0;
	int max = 0;
	int line = 1;

	while(EOF!= (input = getchar()))
	{
	
	
	//	printf("%c", input);
		if((input != 0) &&  (input != 10) ) // if reading something and reading anything besides enter line, then increment char counter
 		{
		++counter;
		}
		if ((counter > 80) && ( input == 10)) // if beyond 80 characters on a new line and reading line feed then store char count && print line number with chars
		{
			max = counter;
			printf("line %d has %d characters\n", line, counter);
		}
		if(input == 10) // if line feed, then increment line and reset char counter
		{
			++line;
			counter = 0;
		}
	/*	if(char == 10)
		{
			++line
		}	*/	
	}
	if(max == 0) // if char was never >80, then it will remain 0 and thus print file is valid
	{
		printf("The input file is valid\n");
	}
	
	
}
