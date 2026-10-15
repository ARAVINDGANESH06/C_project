#include "contact.h"

/* load the contact from the file */

void loadContactsFromFile(AddressBook *addressBook)
{
    FILE *fptr = fopen("contact.csv", "r"); // open the file to read.
    
    if (fptr == NULL)
    {
       printf(RED"->ERROR :: file doesn't exists<-"RESET);  // file validation.
       return;
    }

    fscanf(fptr, "#%d\n", &addressBook->countcontact); //get total count from the file. 

    for (int i = 0; i < addressBook->countcontact; i++) //loop to get the data.
    {   
      fscanf(fptr, "%[^,],%[^,],%[^\n]\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].mail);
    }

    fclose(fptr); // close the file.
}

/* save contact logic */

void savetoFile(AddressBook *addressBook)

{
  FILE*fptr = fopen("contact.csv","w");  // open the file in write mode.
   
  int count = addressBook ->countcontact;

   if(fptr == NULL)                      // file validation.
   {
    printf(RED"->ERROR :: file doesn't exists<-"RESET);
    return ;
   }

   fprintf(fptr,"#%d\n",count); // store the total count in file.

   for(int i=0;i<count;i++)// loop to store entered data (or) detail in the file.
   {
     fprintf(fptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].mail);
   }

   fclose(fptr); // close the file.
} 