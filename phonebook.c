#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAS_LEN 100 //Massive length
#define STR_LEN 31  //String length = 30 symbols
#define NUM_LEN 16  //Number length = 15 symbols

struct record {

        unsigned char name[STR_LEN];
	unsigned char surname[STR_LEN];
        unsigned char number[NUM_LEN];

     };

int add_new_contact(struct record *pointer)
  {
     int i;
     printf("Add new contact\n");
     for (i = 0; i < MAS_LEN; i++)
        {
          if ( (pointer+i)->surname[0]==0 )
                   {            
                      printf("Enter name (max 30 symbols):\n");
                      scanf("%30s",(pointer+i)->name);
                      printf("Enter surname (max 30 symbols):\n");
                      scanf("%30s",(pointer+i)->surname);
                      printf("Enter number (max 15 symbols):\n");
                      scanf("%15s",(pointer+i)->number);
                      printf("\n");
                      printf ("You are entered the name:%s\n",(pointer+i)->name);
                      printf ("You are entered the surname:%s\n",(pointer+i)->surname);
                      printf ("You are entered the surname:%s\n",(pointer+i)->number);
                      break;
                    }
         }          
     return 0;
  }

int delete_contact(struct record *pointer)
  {
     int i, result;
     char surname[STR_LEN];
     printf("Delete contact\n");
     printf("Enter surname (30 symbols):\n");
     scanf("%30s",surname);
     printf ("You are entered the surname:%s\n",surname);
     for (i = 0; i < MAS_LEN; i++)
        {
          result = strcmp((pointer+i)->surname, surname);
          if ( result == 0 )
                   {            
                  
                      printf ("You are entered the name:%s\n",(pointer+i)->name);
                      printf ("You are entered the surname:%s\n",(pointer+i)->surname);
                      printf ("You are entered the surname:%s\n",(pointer+i)->number);
                      printf("\n");
                      (pointer+i)->surname[0]=0;
                   }
         } 
     return 0;
  }

int search_contact(struct record *pointer)
  {
     int i, result;
     char surname[STR_LEN]; 
     printf("Search contact\n");
     printf("Enter surname (30 symbols):\n");
     scanf("%30s",surname);
     printf ("You are entered the surname:%s\n",surname);
     for (i = 0; i < MAS_LEN; i++)
        {
          result = strcmp((pointer+i)->surname, surname);
          if ( result == 0 )
                   {            
                  
                      printf ("You are entered the name:%s\n",(pointer+i)->name);
                      printf ("You are entered the surname:%s\n",(pointer+i)->surname);
                      printf ("You are entered the surname:%s\n",(pointer+i)->number);
                      printf("\n");
                   }
         } 
     return 0;
  }

int view_address_book(struct record *pointer)
  {
     int i, j = 0;
     printf("View address book:\n");
     for (i = 0; i < MAS_LEN; i++)
        {
          if ( (pointer+i)->name[j]!=0 && (pointer+i)->surname[j]!=0 && (pointer+i)->number[j]!=0)
                   {            
                      printf("name:%s\n",(pointer+i)->name);
                      printf("surname:%s\n",(pointer+i)->surname);
                      printf("number:%s\n",(pointer+i)->number);
                   }
         }
     return 0;
  }

int main(void)
  {  
     struct record phonebook[MAS_LEN];
     int i, j = 0;
     for (i = 0; i < MAS_LEN; i++)
        {
           phonebook[i].name[j]=0;
           phonebook[i].surname[j]=0;
           phonebook[i].number[j]=0;
        }
     unsigned char bool;
     while (1)
       { 
          printf ("Phonebook version 0.000.00001/fixed\n");
          printf ("Make your choise - please press key from '1' to '5'\n");
          printf ("1. Add new contact\n2. Delete contact\n3. Search contact\n4. View address book\n5. Exit\n");
          scanf("%u",&bool);
          switch(bool)
             {
               case 1:
                  add_new_contact(phonebook);
                  break;
               case 2:
                  delete_contact(phonebook); 
                  break;
               case 3:
                  search_contact(phonebook); 
                  break;
               case 4:
                  view_address_book(phonebook);
                  break;
               case 5:
                  return 0;
               default:
                  break;
             }
        }
    return 0;
  }  
