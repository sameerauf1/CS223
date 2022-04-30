// ============================================================================
// File: matching_bytes.c (Spring 2022)
// ============================================================================
// This is a small exercise dealing with void pointers. Arrays are allocated
// off the stack so that they contain random values. Then their contents are
// displayed to stdout as individual bytes. The user is then prompted for a 
// target search byte, and the number of matching bytes for an array is 
// displayed.
// ============================================================================

#include    <stdio.h>
#include    <stdint.h>
#include    <stdlib.h>

// defined constants
#define MAX_WIDTH       20
#define NUMELEMS        50

// synonym to simplify byte access -- feel free to use it or not...
typedef unsigned char   Byte;
 

// function prototypes
void DispBytes(void *arrPtr, int memArr);
int CountMatchBytes(void *arrPtr, int numBytes, Byte target);




// ==== main ==================================================================
//
// ============================================================================

int     main(void)
{
    auto    double          myDoubles[NUMELEMS];// array of double type
    auto    int             myInts[NUMELEMS]; // array of int type
    auto    char            myChars[NUMELEMS]; // array of char type
    auto    Byte            target;
    auto    int             numMatches;


//	CountMatchBytes(myChars, sizeof(myChars), target);

    // char array
    puts("Here's the array of chars as bytes: ");
    DispBytes(myChars, sizeof(myChars));
    printf("Enter the target byte as a hex value: ");
    if (1 != scanf("%hhx", &target))
        {
        puts("Error reading hexadecimal value...");
        exit(EXIT_FAILURE);
        }

    numMatches = CountMatchBytes(myChars, sizeof(myChars), target);
    printf("There %s %d matching byte%s.\n\n", (1 == numMatches ? "is" : "are")
                                             , numMatches
                                             , (1 == numMatches ? "" : "s"));
    // int array
    puts("Here's the array of ints as bytes: ");
    DispBytes(myInts, sizeof(myInts));
    printf("Enter the target byte as a hex value: ");
    if (1 != scanf("%hhx", &target))
        {
        puts("Error reading hexadecimal value...");
        exit(EXIT_FAILURE);
        }

    numMatches = CountMatchBytes(myInts, sizeof(myInts), target);
    printf("There %s %d matching byte%s.\n\n", (1 == numMatches ? "is" : "are")
                                             , numMatches
                                             , (1 == numMatches ? "" : "s"));
    // double array
    puts("Here's the array of doubles as bytes: ");
    DispBytes(myDoubles, sizeof(myDoubles));
    printf("Enter the target byte as a hex value: ");
    if (1 != scanf("%hhx", &target))
        {
        puts("Error reading hexadecimal value...");
        exit(EXIT_FAILURE);
        }

    numMatches = CountMatchBytes(myDoubles, sizeof(myDoubles), target);
    printf("There %s %d matching byte%s.\n\n", (1 == numMatches ? "is" : "are")
                                             , numMatches
                                             , (1 == numMatches ? "" : "s"));

    return  0;
    

}  // end of "main"


void DispBytes(void *arrPtr ,int numElem)
        {
        	Byte *pointer;
        	pointer = arrPtr;
        			//	pointer = *(*int)arrPtr;
        	//pointer = *(int*)arrPtr;
        	Byte *endPtr = arrPtr + numElem;
        	int elemCounter = 0;
        	//int numElements = sizeof(memArr)/ sizeof(a[0]);
        	//int *endPtr = a + numElements;
        	for(; pointer < endPtr; ++pointer)
        	{
        		printf("%.2X", *pointer);
        		printf(" ");
        		++elemCounter;
        		if(elemCounter % 20 == 0)
        		{
        			printf("\n");
        		}
        	}
        	printf("\n");
        	
        }
int CountMatchBytes(void *arrPtr, int numBytes, Byte target)

{
			Byte *pointer;
        	pointer = arrPtr;
        			//	pointer = *(*int)arrPtr;
        	//pointer = *(int*)arrPtr;
        	Byte *endPtr = arrPtr + numBytes;
        	int matchedCounter = 0;
        	//int numElements = sizeof(memArr)/ sizeof(a[0]);
        	//int *endPtr = a + numElements;
        	for(; pointer < endPtr; ++pointer)
        	{
        		if(*pointer == target)
        		{
        			++matchedCounter;
        		}
        		
        	}
        	printf("\n");
        	
        	return matchedCounter;

	
}

    
