/*
DOCUMENTATION:
--------------------------------------------------------------------------
Name: Aravind Ganesh K
Reg.no: 25031_014
Start date: 10/12/2025
End date: 21/12/2025
Description : Project_1 -> Address Book Application in C Language.
WORKING: This is a simple address book application that allows users to create, search, edit, delete, and list contacts. The contacts are stored in a file for persistence.
--------------------------------------------------------------------------
-------------------------------------------------------------------------- 
*/

#include "contact.h"

int main() 
{
    int choice;
    AddressBook addressBook;
    addressBook.countcontact=0;  
    initialize(&addressBook);  //Initialize the address book data by file.
do 
 {   
    printf("-------------------------------------------------------\n");
    printf("           ------> Address Book Menu <------\n");
    printf("-------------------------------------------------------\n");
    printf(" 1) Create contact\n 2) Search contact\n 3) Edit contact\n 4) Delete contact\n 5) List all contacts\n 6) Save and Exit\n");		
    printf(GREEN"Enter your choice-> "RESET);
    scanf("%d", &choice);
       
    switch (choice) 
    {
      case 1:
        createContact(&addressBook); //function call for create contact.
        break;
      case 2:
        searchContact(&addressBook,SEARCH_ONLY); //function call for Search contact.
        break;
      case 3:
        editContact(&addressBook); //function call for Edit contact.
        break;
      case 4:
        deleteContact(&addressBook); //function call for Delete contact.
        break;
      case 5:          
         listContacts(&addressBook); //function call for List all contacts.
         break;
      case 6:
         printf(BLUE"Saving and Exiting....\n"RESET);
         savetoFile(&addressBook);//function call for Save and Exit.
         break;
      default:
        printf(RED"Invalid choice. Please try again.\n"RESET);
    }

 }while (choice != 6); 
 return 0;
}
