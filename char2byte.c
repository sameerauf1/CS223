#include <stdio.h> // hi prof should i delete my commented code out, that i used in developement, next time when i turn in my hw?

int main(void) // for this file, i used the file 'zoo.txt' to test out my code
{

/*	auto char inChar;
	auto int  myChar;
	myChar = 'A';
	printf("enter a char: ");
	scanf("%c", &inChar);
	printf("You entered decimal value:  %d \n", inChar);
	printf("You entered hex value: %x \n", inChar);
	printf("you entered char value: %c \n",inChar);
	
	printf("You entered myChar decimal value:  %d \n", myChar);
	printf("You entered myChar hex value: %x \n", myChar);
	printf("you entered myChar char value: %c \n",myChar);
*/

//	auto int myChar;
	auto int myCharall; //initizling int which will be used to store the 'character' casted as an int by get char
//	auto int filecontent = 0;
//	printf("enter a char: ");
	//myChar = getchar();
	auto int counter = 1;
		while(EOF != (myCharall = getchar())) // if EOF is not equal to myCharall, than the while loop will continue reading the entire doc, once it reaches the EOF, the while loop will stop
		{
		/*	if(counter  == 1)
						{
						filecontent = 1;
						}*/

		//	putchar(myCharall);
			printf(" %.2x", myCharall); // print myCharall as a hex with 2 digits
			if(counter % 20 == 0) //jump to next line after every 20 character, so that way we only have 20 characters in each line just in like in hw reqs
			{
			printf("\n"); // print new line
			}
			++counter;
		

		}
	/*	if(filecontent == 0)
				{
				puts("Input files does have any  data... "); 
				
				}*/
	
}
