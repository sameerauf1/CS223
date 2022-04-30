#include <stdio.h> // Hi Prof Edwards, should i delete the code I made in developement next time?

int main(void) // i used the file 'byte2charoutput2.txt' as my input to test my program
{
	
	auto  char ascci;
	auto unsigned char asccicheck;
//	notascci = 0x81;
//	ascci = 0x41;
//	ascci = 0x01;

	char mask = 0x80;
	

 	int nonascicounter = 0;
 	int bytecounter = 0;

   // printf("0. Asci value in hex: %#x char: %c dec: %d\n", ascci, ascci, ascci);
   // ascci &= mask;  
   //  printf("1. Asci value in hex: %#x char: %c dec: %d\n", ascci, ascci, ascci);
 //	asccicheck = mask & ascci;
	
   // printf("2. Assci check, hex: %#x char: %c dec: %d \n", asccicheck , asccicheck, asccicheck);
   // printf("3. The mask, hex: %#x char: %c dec: %d \n",mask , mask, mask );
    while(EOF !=  (ascci = getchar()))
    {
   // ++bytecounter;
   //	printf("Non asci counter: %d\n",nonascicounter);
   //	printf("Byte counter: %d\n",bytecounter);
 
    //	printf("%c\n", ascci);
    	asccicheck = mask & ascci;
    //	printf("2. Assci check, hex: %#x char: %c dec: %d \n", asccicheck , asccicheck, asccicheck);
	   	if(asccicheck  >=  80)
		{ 
		nonascicounter = nonascicounter + 1;
	//	printf("%d",nonascicounter);
		//	printf("4. This is not an  ascii character, hex: %#x char: %c dec: %d \n",ascci, ascci, ascci);
			printf("Non-ascci input: %x detected at %#x\n", ascci, nonascicounter);
		//	printf("A total of %d non-Ascii bytes were encountered.", nonascicounter);
		}
		if(	asccicheck == 0)
		{
			bytecounter = bytecounter + 1;
		//	printf("%d",bytecounter);
		}
	}

	
//	printf("Non asci counter: %d\n",nonascicounter);
   //	printf("Byte counter: %d\n",bytecounter);
	if(nonascicounter > 0)
	{
			printf("A total of %d non-ASCII bytes were encountered", nonascicounter);

	}
	else if( (nonascicounter == 0) && (bytecounter > 0))
	{
		printf("THe input stream was pure ASCII with a total of %d bytes read\n", bytecounter);
	}


/*	 if((mask & ascci) ==  mask)
	{
	    printf("5. This is an  ascii character, hex: %#x char: %c dec: %d \n",ascci, ascci, ascci);
	}*/
     
 		

	//printf("%c", myByte); // doesn't do anything
//	printf("The byte(ascci) being tested is: %x\n", ascci);
//	printf("The bit mask being used is: %x\n", mask);
	//printf("The bit mask being used is: : %x\n", mybyte);

	//match = mask & myByte;

/*
	match = mask & ascci;
	match2 = mask & notascci;

		
	if(match < notascci)
	{
		printf("This is not an  ascii character %x went to %d \n",ascci, match);
	}
	 if(match2 >= ascci)
	{
		printf("This is an ascii character, the input: %x in hexadecimal is %x ", notascci, match2);
	}
*/	
	/*
	printf("And operator on ascii byte and bit mask  %d \n",match);
	printf("And operator on ascii byte and bit mask  %x \n \n", match);


	printf("The byte(not ascci) being tested is: %x\n",notascci);
	printf("The bit mask being used is: %x\n", mask);

	
	printf("And operator on  ascii  byte and bit mask  %d \n", match2);
	printf("And operator on  ascii  byte and bit mask  %x \n", match2);
	*/
//	printf("And operator on byte and bit mask  %c \n", match);
//	printf("And operator on byte and bit mask  %x \n", match);
	/*while(EOF != (scanf("%x", &inChar))) // loop will keep running until EOF is not equal to inchar
	{	
	printf(" %c", inChar); 
	}*/
}
