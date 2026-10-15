#include "contact.h"

/* logic for the list contact:*/

void listContacts(AddressBook *addressBook) 
{  
  int count = addressBook->countcontact;
  if(count == 0)
  {
  printf(RED"---> NO,contacts are saved <---\n"RESET);
  return;
  }   
  Contact tempContacts[count]; // temporary array to store the contacts for sorting.
  for (int i = 0; i < count; i++)
  {
    tempContacts[i] = addressBook->contacts[i];
  }

 for (int i = 0; i < count - 1; i++)  //Bubble sort logic for sort the contact.
  {
  for (int j = 0; j < count - i - 1; j++) 
  {
    if (strcasecmp(tempContacts[j].name, tempContacts[j + 1].name) > 0) //compare the contact name and swap it to the A-Z order.
    {
      Contact tem = tempContacts[j];  
      tempContacts[j] = tempContacts[j + 1];
      tempContacts[j + 1] = tem;
    }
  }
    }
     printf(GREEN"\n\t\t--------> LIST OF THE CONTACTS <--------\n"RESET);   // list of the sorted contact showcase table.
     printf("==========================================================================\n");
     printf("|%-5s|%-20s|%-15s|%-30s|\n","S.NO","NAME","PHONE.NO","MAIL ID");
     printf("==========================================================================\n");
     for (int i=0; i < count; i++)
     {
      printf("|%-5d|%-20s|%-15s|%-30s|\n", i+1,tempContacts[i].name, tempContacts[i].phone,tempContacts[i].mail);
     }
      printf("==========================================================================\n");
}

/*load contact logic:*/

void initialize(AddressBook *addressBook)
{
    addressBook->countcontact = 0;   
    loadContactsFromFile(addressBook);
}

/*save contact logic:*/

void saveAndExit(AddressBook *addressBook) 
{
    savetoFile(addressBook); 
    exit(EXIT_SUCCESS); // Exit the program
}

/*createcontact logic:*/

void createContact(AddressBook *addressBook) 
{
   char name[50],phone[20],mail[50]; // temporary variabls to get data from the user.
   int ret;

   do
  {
     printf(GREEN"Enter Name to create:"RESET);
     scanf(" %[^\n]",name);
     ret = validname(name); // function call for the name validation.
      if(ret == 1)
      {
       strcpy(addressBook->contacts[addressBook->countcontact].name, name); // by using bulit-in function copy temp value to created array.
      }
      else
      {
        printf(RED"--> Invalid Name <--\n"RESET);
      }
  }while(ret == 0);

   do 
  {
     printf(GREEN"Enter Phone Number to create:"RESET);
     scanf(" %[^\n]", phone);
     ret = validphone(addressBook,phone); // function call for the phone validation.
     if(ret == 1)
      {
        strcpy(addressBook->contacts[addressBook->countcontact].phone, phone);// by using bulit-in function copy temp value to created array.
      }
      else if (ret == 0)
      {
        printf(RED"--> Invalid Phone number <--\n"RESET);
      }
      else if(ret == -1)
      {
        printf(RED"---> Phone number is already exists! <---\n"RESET);
      }
  } while(ret == 0 || ret == -1);

  do 
  {
    printf(GREEN"Enter mail ID to create:"RESET);
    scanf(" %[^\n]", mail);
    ret = validmail(addressBook,mail); //function call for the mail validation.
   if(ret == 1)
      {
        strcpy(addressBook->contacts[addressBook->countcontact].mail, mail);// by using bulit-in function copy temp value to created array.
      }
      else if(ret == 0)
      {
        printf(RED"--> Invalid Mail ID <--\n"RESET);
      }
      else if(ret == -1)
      {
        printf(RED"---> Mail is already exists <---\n"RESET);
      }
  } while(ret == 0 || ret == -1);

  addressBook->countcontact++; //here it will count the contacts.

    char option;
    printf(GREEN"DO you want add another contact? (Y/N):"RESET);  // ask for the for another contact to add. 
    scanf(" %c",&option);

    if(option == 'Y' || option == 'y')
    {
      createContact(addressBook);   // funtion call for add the contact again.
    }
    else if(option == 'N' ||option == 'n')
    {
      printf(BLUE"---> Contacts are saved successfully <---\n"RESET);  
      return ;
    }
    else
    {
       printf(RED"---> invalid option (enter 'Y' or 'N') <---\n"RESET);
       return;
    }
}

/*searchcontact logic:*/

int searchContact(AddressBook *addressBook, int mode)
{
    int choice;
    char search[50]; // temporary variable to get search detail from the user.
    int count = addressBook->countcontact;

    if (count == 0)
    {
        printf(RED"---> NO contacts are saved <---\n"RESET);
        return -1;
    }

    printf(BLUE"-------> Search contact by Menu <-------\n"RESET);// search menu showcase.
    printf(" 1) By Name\n 2) By Phone Number\n 3) By Mail\n 4) Exit\n");
    printf(GREEN"Enter your choice->"RESET);
    scanf("%d", &choice);
    getchar();

    switch (choice) // get input from the user based on the choice.
    {
    case 1:
      printf(GREEN"Enter the name to search:"RESET);
      scanf(" %[^\n]", search);
      break;
    case 2:
      printf(GREEN"Enter the phone number to search:"RESET);
      scanf(" %[^\n]", search);
      break;
    case 3:
      printf(GREEN"Enter the mail ID to search:"RESET);
      scanf(" %[^\n]", search);
      break;
    case 4:
        return -1;
    default:
        printf(RED"--> Invalid choice <--\n"RESET);
        return -1;
    }

    int matchcount = 0; // counter for matching contacts.
    int matchindices[count]; // array to store indices of matching contacts.

    for (int i = 0; i < count; i++)
    {
        int match = 0;

        if (choice == 1) // check for the choice and compare the entered detail with saved contact detail.
          match = (strcasecmp(addressBook->contacts[i].name, search) == 0);
        else if (choice == 2)
          match = (strcasecmp(addressBook->contacts[i].phone, search) == 0);
        else if (choice == 3)
          match = (strcasecmp(addressBook->contacts[i].mail, search) == 0);

        if (match)
        {
            matchindices[matchcount++] = i; // store the index of the matching contact.
        if (matchcount == 1)
        {
          printf(GREEN"\n\t\t--------> SEARCH RESULTS <--------\n"RESET); // search result showcase table.
          printf("==========================================================================\n");
          printf("|%-5s|%-20s|%-15s|%-30s|\n", "S.NO", "NAME", "PHONE.NO", "MAIL ID");
          printf("==========================================================================\n");
        }
          printf("|%-5d|%-20s|%-15s|%-30s|\n",matchcount,addressBook->contacts[i].name, addressBook->contacts[i].phone,addressBook->contacts[i].mail);
        }
    }
    
    if (matchcount == 0 )
    {
      printf(RED"---> No matching contact found <---\n"RESET);
       return -1;
    }
    printf("==========================================================================\n");
  
  if (mode == SEARCH_ONLY)
   {
     return -1; //only display at the search contact. 
   }


    if (matchcount == 1) // single match handling.
    {
        return matchindices[0];
    }
    printf(GREEN"Multiple contacts found\n"RESET); // multiple match handling.
    printf(BLUE"Select By:\n"RESET);
    printf(" 1) S.NO\n 2) Phone number\n 3) Exit\n");

    int selectchoice;
    printf(GREEN"Select the choice->"RESET); // get input from the user based on the choice.
    scanf("%d", &selectchoice);

    if (selectchoice == 1)
    {
      int sno;
      printf(GREEN"Enter the S.NO-> "RESET);
      scanf("%d", &sno);

    if (sno > 0 && sno <= matchcount)
      return matchindices[sno - 1]; // return the index of the selected contact.
    else
      return -1;
    }
    else if (selectchoice == 2)
    {
      char ph[20];
      printf(GREEN"Enter the phone number-> "RESET);
      scanf("%s", ph);

     for (int i = 0; i < matchcount; i++)
    {
      int idx = matchindices[i];
      if (strcmp(addressBook->contacts[idx].phone, ph) == 0)
      return idx; // return the index of the selected contact.
     }
      return -1;
    }
    return -1;
}

/*editcontact logic:*/

void editContact(AddressBook *addressBook)
{
  int targetindex = searchContact(addressBook,SELECT_ONE); // reuse search contact function to get the index of the contact to edit.
  if (targetindex == -1)
  {
     printf(RED"---> Contact not found <---\n"RESET);
     return;
  }

    int editChoice;   // edit menu showcase.
    printf(GREEN"\nWhat do you want to edit?\n"RESET);
    printf(" 1) Name\n 2) Phone\n 3) Mail\n 4) Cancel\n");
    printf(GREEN"Enter your choice-> "RESET);
    scanf("%d", &editChoice);
    getchar();

    char newdetail[100]; //temporary variable to get new detail from the user.
    int ret;

  switch (editChoice)
  {
   case 1:
    do
    {
      printf(GREEN"Enter new Name: "RESET);
      scanf(" %[^\n]", newdetail);
      ret = validname(newdetail); //function call for the name validation.
      if (ret == 1)
      {
        strcpy(addressBook->contacts[targetindex].name, newdetail);// by using bulit-in function copy temp value to created array.
        printf(BLUE"--> Name updated successfully.\n"RESET);
      } 
     else
     {
       printf(RED"--> Invalid Name. Try again.<--\n"RESET);
     }
    } while (ret != 1);
        break;

  case 2:
   do
    {
      printf(GREEN"Enter new Phone: "RESET);
      scanf(" %[^\n]", newdetail);
      ret = validphone(addressBook, newdetail);// function call for the phone validation.
      if (ret == 1)
      {
        strcpy(addressBook->contacts[targetindex].phone, newdetail);// by using bulit-in function copy temp value to created array.
        printf(BLUE"--> Phone updated successfully.\n"RESET);
      }
      else if (ret == 0)
      {
        printf(RED"--> Invalid Phone number <--\n"RESET);
      }
      else
      {
        printf(RED"---> Phone already exists <---\n"RESET);
      }
    } while (ret != 1);
        break;

    case 3:
     do
      {
        printf(GREEN"Enter new Mail: "RESET);
        scanf(" %[^\n]", newdetail);
        ret = validmail(addressBook, newdetail);// function call for the mail validation.
        if (ret == 1)
        {
          strcpy(addressBook->contacts[targetindex].mail, newdetail); // by using bulit-in function copy temp value to created array.
          printf(BLUE"--> Mail updated successfully.\n"RESET);
        }
        else if (ret == 0)
        {
          printf(RED"--> Invalid Mail ID <--\n"RESET);
        }
        else
        {
          printf(RED"---> Mail already exists <---\n"RESET);
        }
        } while (ret != 1);
        break;

    case 4:
        return;

    default:
        printf(RED"--> Invalid choice <--\n"RESET);
    }
}

/*deleteContact logic:*/

void deleteContact(AddressBook *addressBook)
{
   if (addressBook->countcontact == 0)
   {
     printf(RED"---> No contacts saved <---\n"RESET);
     return;
  }

    int targetindex = searchContact(addressBook,SELECT_ONE); // reuse search contact function to get the index of the contact to delete.
    if (targetindex == -1)
    {
        printf(RED"---> Contact not found <---\n"RESET);
        return;
    }

    char option;
    printf(GREEN"\nAre you sure you want to delete this contact? (Y/N): "RESET); // confirmation to delete the contact.
    scanf(" %c", &option);

  if (option == 'Y' || option == 'y')
  {
    for (int i = targetindex; i < addressBook->countcontact - 1; i++) // loop to shift the contacts after deletion.
    {
      addressBook->contacts[i] = addressBook->contacts[i + 1]; // shift contacts to fill the gap.
    }

    addressBook->countcontact--;
    printf(BLUE"---> Contact Deleted Successfully <---\n"RESET);
  }
  else
  {
    printf(RED"---> Delete cancelled <---\n"RESET);
  }
}

/*validation logic for the name*/

int validname(char name[]) 
{  
  if (name[0] == '\0')
  {
    return 0;
  }

  for(int i=0;name[i]!='\0';i++)
  {
    if(!(isalpha(name[i]) || isspace(name[i])))  // by using the built _ in function check for the name
     {
        return 0;
     }
  }
  return 1;
}

/* validation logic for the phone number*/

int validphone(AddressBook *addressBook, char phone[])  
{  
    int count = addressBook->countcontact; // store the count of countcontact in variable.
   
    if (strlen(phone) != 10)  // check length of the number.
    {
      return 0;
    }

    for (int i = 0; i < 10; i++) // check for the digit only.
    {
      if (!isdigit(phone[i]))
      return 0;
    }

    for (int i = 0; i < count; i++) 
    {
      if (strcmp(addressBook->contacts[i].phone, phone) == 0)  // chcke for the dulicates number is present are not. 
      {
       return -1;
      }
    }
    return 1;
}

/* validation logic for the mail*/

int validmail(AddressBook *addressBook, char mail[]) 
{  
   int count = addressBook->countcontact; // store the count of countcontact in variable.
    int len = strlen(mail);

    if (strchr(mail,'@') == NULL)  // check for the @ character is present are not.
    {
      return 0;
    }

    if (len < 4 || strcmp(mail + len - 4, ".com") != 0) // check for the last 4 character are end with .com.  
    {
      return 0;
    }

    for (int i = 0; i < count; i++) 
    {
        if (strcmp(addressBook->contacts[i].mail, mail) == 0)     // Check duplicates mail.
        {
          return -1;
        }
    }
    return 1;
}

