// ============================================================================
// File: sortedll.c (Spring 2022)
// ============================================================================
// This program allows the user to manipulate the contents of a list of
// integers in a singly-linked list. The list items are maintained in sorted
// ascending order, and duplicate values are permitted.
// ============================================================================

#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <ctype.h>
#include    "sortedll.h"

// lNOde struct int value, struct Lnode *next 

// ==== main ==================================================================
//
// ============================================================================

int     main(void)
{
    auto    int             intVal;
    auto    LNode           *headPtr = NULL;
    auto    char            buf[BUFLEN];
    auto    int             numItems;

    do  {
        // ask the user what they want to do and handle their choice
        DisplayMenu();
        printf("Please enter a selection: ");
        fgets(buf, BUFLEN, stdin);
        *buf = toupper(*buf);
        switch (*buf)
            {
            case   'A':
                printf("Please enter an integer value to add: ");
                fgets(buf, BUFLEN, stdin);
                if (1 != sscanf(buf, "%d", &intVal))
                    {
                    puts("Error reading the integer value...");
                    }
                else
                    {
                    headPtr = AddItem(headPtr, intVal);
                    }
                break;

            case   'R':
                if (NULL == headPtr)
                    {
                    puts("The list is already empty...");
                    }
                else
                    {
                    printf("Please enter an integer value to remove: ");
                    fgets(buf, BUFLEN, stdin);
                    if (1 != sscanf(buf, "%d", &intVal))
                        {
                        puts("Error reading the integer value...");
                        }
                    else
                        {
                        headPtr = RemoveItem(headPtr, intVal);
                        }
                    }
                break;

            case   'D':
                // display the current contents of the list
                numItems = DisplayList(headPtr);
                printf("*** main -- currently there %s %d node%s in the list...\n"
                                    , (numItems != 1) ? "are" : "is"
                                    , numItems
                                    , (numItems != 1) ? "s" : "");
                break;

            case   'F':
            case   'Q':
                // user wants to either clear the list or quit the program, so
                // release all nodes in the list
                numItems = FreeList(&headPtr);
                printf("*** main -- there %s %d node%s released...\n"
                                    , (numItems != 1) ? "were" : "was"
                                    , numItems
                                    , (numItems != 1) ? "s" : "");
                break;

            default:
                puts("Unrecognized option; please try again.");
                break;
            }

        // write out a blank line before next loop iteration
        puts("");

        } while ('Q' != *buf);

    puts("Thanks for playing!  Bye!!\n");
    return  0;

}  // end of "main"



// ==== AddItem ===============================================================
//
// This function inserts an item into the list by dynamically allocating a node
// to store the value and locating the correct position for the new item so
// that the list is maintained in ascending sorted order.
//
// Input:
//      headPtr [IN]        -- a pointer to the first node in the list
//
//      newItem [IN]        -- the new item to insert into the list
//
// Output:
//      A pointer to the head of the list.

// ============================================================================

LNode*  AddItem(LNode  *headPtr, int  newItem)
{

	auto LNode *nodePtr; // type of LNocde ptr
	nodePtr = malloc(sizeof(LNode)); // allocating a node from the heap & storing tis adress in nodeptr
//	nodePtr = headPtr; // coping head adrress to node ptr // NOT SURE IF THIS RIGHT?, 
	nodePtr->value = newItem;
	auto LNode *loopPtr = headPtr;
//	currentPtr = malloc(sizeof(LNode));
//	currentPtr = headPtr;*/
	
	if(headPtr == NULL)// case 1:  first node
	{
		nodePtr->next = NULL;
		return nodePtr;
		
	}
	else if(newItem < headPtr->value)// case 2:  adding before the head
			{
				//nodePtr->value = newItem;
				nodePtr->next = headPtr;
				return nodePtr;
			}
	while(loopPtr->next != NULL)
	{	
		 if(newItem > loopPtr->value && newItem < loopPtr->next->value) // adding in between two nodes
			{
			nodePtr->next = loopPtr->next;
			loopPtr->next = nodePtr;
			return headPtr;
			}
		loopPtr = loopPtr->next;
		
	
    }

	// Add at end
	loopPtr->next = nodePtr;
	nodePtr->next = NULL;

			
    
    return headPtr;

}  // end of "AddItem"



// ==== DisplayList ===========================================================
//
// This function displays all of the values contained in the linked list to the
// standard output stream.
//
// Input:
//      headPtr [IN]        -- a pointer to the first node in the list
//
// Output:
//      The total number of nodes displayed is returned.
//
// ============================================================================

int     DisplayList(const LNode  *nodePtr)
{
    auto    int         counter = 0;

    // if the list is empty, indicate as such and return zero
    if (NULL == nodePtr)
        {
        // puts("*** DisplayList -- the list is currently empty...");
        return 0;
        }

    while (NULL != nodePtr)
        {
        printf("%d\n", nodePtr->value);
        nodePtr = nodePtr->next;
        counter++;
        }

    return counter;

}  // end of "DisplayList"



// ==== DisplayMenu ===========================================================
//
// This function displays the menu to stdout.
//
// Input:
//      Nothing
//
// Output:
//      Nothing
//
// ============================================================================

void    DisplayMenu(void)
{
    // write out a leading blank line, followed by menu items
    puts("A)dd a value");
    puts("R)emove a value");
    puts("D)isplay the list");
    puts("F)ree the list");
    puts("Q)uit");

}  // end of "DisplayMenu"



// ==== FreeList ==============================================================
//
// This function traverses the linked list and releases the memory allocated
// for each individual node, and the caller's head node pointer is set to NULL.
//
// Input:
//      headPtr [IN/OUT]    -- the address of the caller's head node pointer
//
// Output:
//      The total number of nodes released is returned.
//
// ============================================================================

int     FreeList(LNode  **headPtr)
{
//	LNode *loopPtr = *headPtr;  
	
	int counter = 0;
	while(headPtr != NULL && *headPtr != NULL)
	{
	LNode *tempPtr = (*headPtr)->next;
	free(*headPtr);
	*headPtr = tempPtr;
	++counter;  	
	}
	/*
	if(loopPtr != NULL && loopPtr->next == NULL) // if only head exist free it
	 	{
	 		printf("head is being released rn..");
	 		RemoveItem(*headPtr,(*headPtr)->value);
	 		//free(headPtr);
	 		return 1;
	 	}
//	 else if(loopPtr->next !=NULL) // more than just head exist,  loop through UNTIL end of list
//	 {
		while(loopPtr->next != NULL) 
		 {
			printf("releasing every node...");
			RemoveItem(*headPtr,(*headPtr)->value);
			loopPtr = loopPtr->next;
			++counter;
		 } 

		//	RemoveItem(*headPtr,(*headPtr)->value);
			//loopPtr = loopPtr->next;
		//	++counter;
	//		}*/
		
return counter;
	// call remove function giving i looptr
}  // end of "FreeList"



// ==== RemoveItem ============================================================
//
// This function removes an item from the list.  If the target item is located
// in the list, the memory allocated for its node is released and any adjacent
// nodes are joined so as not to break the list.
//
// Input:
//      headPtr [IN]        -- a pointer to the first node in the list
//
//      target [IN]         -- the item to remove
//
// Output:
//      A pointer to the (potentially new) head of the list
//
// ============================================================================

LNode*  RemoveItem(LNode  *headPtr, int  target)
{
auto LNode *tempPtr;
/* auto LNode *nodePtr;
 nodePtr = malloc(sizeof(LNode));
 nodePtr = headPtr;   */
auto LNode *loopPtr = headPtr;

 if(headPtr->value == target) {
 	// Remove head
 	if(headPtr->next == NULL) // if only head exist delete it
 	{
 		free(headPtr);
 		return NULL;
 	}
 	else // if head and another node exist
 	{
	 	tempPtr = headPtr->next;
	 	free(headPtr); // delete head
	 	return tempPtr; // return new head
 	}
 }

 while(loopPtr->next != NULL && loopPtr->next->value != target) //loop through until next is the target
 {
 	loopPtr = loopPtr->next;
 }

 if(loopPtr->next == NULL) {
 	// Not found
 	return headPtr;
 }
 else if(loopPtr->next->value == target) {
 	// Remove loopPtr->next
 	tempPtr = loopPtr->next->next;
 	  free(loopPtr->next);
 	 loopPtr->next = tempPtr; // skip the next 
 }
 

 return headPtr;
 

}  // end of "RemoveItem"
