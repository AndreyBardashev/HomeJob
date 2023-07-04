#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define STR_LEN 31  //String length = 30 symbols
#define NUM_LEN 16  //Number length = 15 symbols

struct recordNode {

        unsigned char name[STR_LEN];
	unsigned char surname[STR_LEN];
        unsigned char number[NUM_LEN];
        struct recordNode *nextPointer;

     };

typedef struct recordNode RecordNode;
typedef RecordNode *RecordNodePtr;

int add_new_contact(RecordNodePtr *topPtr)
  {
     RecordNodePtr newPtr;
     newPtr = malloc (sizeof(RecordNode));
     if (newPtr != NULL)
        {
           printf("Add new contact\n");     
           printf("Enter name (max 30 symbols):\n");
           scanf("%30s",newPtr->name);
           printf("Enter surname (max 30 symbols):\n");
           scanf("%30s",newPtr->surname);
           printf("Enter number (max 15 symbols):\n");
           scanf("%15s",newPtr->number);
           printf("\n");
           printf ("You are entered the name:%s\n",newPtr->name);
           printf ("You are entered the surname:%s\n",newPtr->surname);
           printf ("You are entered the surname:%s\n",newPtr->number);
           newPtr -> nextPointer = *topPtr;
           *topPtr = newPtr;
        }
     else printf ("\nNo memory available\n");
     return 0;
  }
  
int isEmpty (RecordNodePtr topPtr)
{
    return topPtr == NULL;
}

int delete_contact(RecordNodePtr *topPtr)
  {
     RecordNodePtr prevPtr, currPtr, tempPtr;
     int result = 1;
     char surname[STR_LEN];
     printf("Delete contact\n");
     printf("Enter surname (30 symbols):\n");
     scanf("%30s",surname);
     printf ("You are entered the surname:%s\n",surname);
     do
        {   
           result = strcmp((*topPtr)->surname, surname);
           if (result == 0)
              {
                printf("\n");
                printf ("You are entered the name:%s\n",(*topPtr)->name);
                printf ("You are entered the surname:%s\n",(*topPtr)->surname);
                printf ("You are entered the surname:%s\n",(*topPtr)->number);
                tempPtr =*topPtr;
                *topPtr = (*topPtr)->nextPointer;
                free (tempPtr);
               }
             else break;
        }
     while (*topPtr != NULL);
     if (*topPtr != NULL)
        {
           prevPtr = *topPtr;
           currPtr = (*topPtr)->nextPointer;
           while (currPtr != NULL)
              {
                 result = 1;
                 result = strcmp(currPtr->surname, surname);
                 if (result == 0)
                     {
                        printf("\n");
                        printf ("You are entered the name:%s\n",currPtr->name);
                        printf ("You are entered the surname:%s\n",currPtr->surname);
                        printf ("You are entered the surname:%s\n",currPtr->number);
                        tempPtr = currPtr;
                        prevPtr->nextPointer = currPtr->nextPointer;
                        free(tempPtr);
                        currPtr=prevPtr->nextPointer;
                        continue;
                      }
                   prevPtr = currPtr;
                   currPtr = currPtr->nextPointer;
               }
         }
     return 0;
  }

int search_contact(RecordNodePtr currentPtr)
  {
     int result = 1;
     char surname[STR_LEN];
     printf("Search contact\n");
     printf("Enter surname (30 symbols):\n");
     scanf("%30s",surname);
     printf ("You are entered the surname:%s\n",surname);
     do
        {            
           result = 1;
           result = strcmp(currentPtr->surname, surname);
           if ( result == 0 )
              {            
                 printf("\n");
                 printf ("You are entered the name:%s\n",currentPtr->name);
                 printf ("You are entered the surname:%s\n",currentPtr->surname);
                 printf ("You are entered the surname:%s\n",currentPtr->number);
                 printf("\n");
               }
           currentPtr = currentPtr -> nextPointer;
        }
     while (currentPtr != NULL);
     return 0;
  }

int view_address_book(RecordNodePtr currentPtr)
  {
     printf("View phonebook:\n");
     while (currentPtr != NULL)
        {            
           printf("name:%s\n",currentPtr->name);
           printf("surname:%s\n",currentPtr->surname);
           printf("number:%s\n",currentPtr->number);
           currentPtr = currentPtr -> nextPointer;
         }
     return 0;
  }

int main(void)
  {  
     RecordNodePtr recordPtr = NULL;
     int bool;
     while (1)
       { 
          printf ("Phonebook version 0.000.00002/fixed\n");
          printf ("Now you are using the multifunctional phonebook\n");
          printf ("1. Add new contact\n2. Delete contact\n3. Search contact\n4. View address book\n5. Exit\n");
          scanf("%d",&bool);
          switch(bool)
             {
               case 1:
                  add_new_contact(&recordPtr);
                  break;
               case 2:
                  if (!isEmpty(recordPtr)) delete_contact(&recordPtr);
                   else printf ("Phonebook is empty\n");
                  break;
               case 3:
                  if (!isEmpty(recordPtr)) search_contact(recordPtr);
                   else printf ("Phonebook is empty\n");
                  break;
               case 4:
                  if (!isEmpty(recordPtr)) view_address_book(recordPtr);
                   else printf ("Phonebook is empty\n");
                  break;
               case 5:
                  return 0;
               default:
                  break;
             }
        }
    return 0;
  }  
