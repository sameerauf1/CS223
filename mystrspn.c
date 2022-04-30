#include <stdio.h>
#include <string.h>
int mystrspn( const char* str, const char* accept)/// const pointer adresses
{
	
		char* str1 = str;// get adress of first array
		char* str2 = accept; // get adress of second array
	    int countStr1 = 0;
	    int countStr2 = 0;
	
	 
	int count = 0;

// if there is a char in the first loop that is not in teh second loop, then dne
	int flagCharExist = 0; // if char in string 1 exist in char2?
	while(*str1 != '\0')
	{

	//	printf("in the first while loop \n");
		
		while(*str2 != '\0')
		{
		//	printf("JJ*** mystrspn: *str1 = %c\n", *str1);
		//	printf("JJ*** mystrspn: *str2 = %c\n", *str2);
			if(*str2 != *str1)
				{
			//	printf("no match\n");
			
				//	break;
				}
			else if(*str1 == *str2 ||str2 == '\0')
			{
			//		printf("broken\n");
					flagCharExist = 1;
				++count;
				str2 = accept; //resettgint teh pointer...
				break;	
			}
		 ++str2;
		}
		// am i not looking at anull, and does this char exist in teh second loop
		if(*str1 == '\0' || flagCharExist ==0)
		{
			break;
		}
		++str1;
	}		
		

	printf("count %d\n ", count); // shouldn't print it
	return count;
}

int main()
{
//	printf("enter a string");
	char inputFirst[] = "xyz";
	char inputSecond[] = "abcxyz";

	mystrspn("abcxyz", "abc"); 
    mystrspn("abcxyz", "xyz"); 
    mystrspn("abcxyz", "baa"); 
    mystrspn("xyz", "xyzabc"); 
    mystrspn("xyz", "abcxyz"); 
	
}
