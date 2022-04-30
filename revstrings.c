// ============================================================================
// File: dynamic_string.c
// ============================================================================
// This program demonstrates how a single string can be created from the heap.
// The user at the keyboard is prompted to enter a string, which is stored
// temporarily in a local buffer. Then, the appropriate amount of space is
// allocated from the heap to store a copy; after the allocation the local
// buffer is copied to the heap space, so the heap string can be displayed to
// stdout. Finally, the heap string is explicitly released from the heap.
// ============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFLEN 251
// ==== main ==================================================================
//
// ============================================================================
int main(void)
{
	char buf[BUFLEN]; // initialing array of size 250 + 1 to account for null char

	char* result; // creating pointer of type char

	char** ptrToCharPtrs;
	// creating a poitner to a pointer
	ptrToCharPtrs = (char*)malloc(100 * sizeof(char*)); // need to change retrun type to char* pointer
 // store poitner of base adress into ptrToCharPtrs
 // allocate the memeory it would take to store 100 chars, which are each one byte
	printf("Enter up to 100 strings, leave your string empty if you would like to end.  ");

	int counter = 0;
	while (counter < 100 && *result != 10 && (result = fgets(buf, BUFLEN, stdin))) // stop at 100 inputs,
	//keep going as long as there is input, and input is not next line
	{
		// if we failed to get a string, exit the program
		if (NULL == result)
		{
			puts("main: fgets failed to read a string...");
			exit(EXIT_FAILURE);
		}

		// allocate enough space from the heap to store a copy of the string
		// (note that the amount of space allocated allows for the NULL character)
		ptrToCharPtrs[counter] = (char*)malloc(strlen(buf) + 1); // set the element to the pointer

		if (NULL == ptrToCharPtrs[counter])
		{
			puts("main: malloc failed...");
			exit(EXIT_FAILURE);
		}

		//     source,          dest
		strcpy(ptrToCharPtrs[counter], buf); 		// copy the buffer over to the heap 


		counter++;
	}
	
	for (int j = counter - 1; j >= 0; j--) 	// display the heap strings backwards until its empty
	{
		printf("%s", ptrToCharPtrs[j]);

		free(ptrToCharPtrs[j]); 		// release each element as we loop through

	}
	free(ptrToCharPtrs); // release pointer pointing to array

	return 0;
} // end of "main"
