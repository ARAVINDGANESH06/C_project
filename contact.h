#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

#define RESET   "\033[0m"
#define BLACK   "\033[0;30m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE   "\033[0;37m"

#define SEARCH_ONLY   0 // just diplay the search results.
#define SELECT_ONE    1 // select one from multiple search results.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*Structure definitions:*/
typedef struct { 
    char name[50];
    char phone[20];
    char mail[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS]; //array of structure to store the contacts.
    int countcontact;
} AddressBook;

/*functions declarations: */
void createContact(AddressBook *addressBook); 
 int validname(char name[]);
 int validphone( AddressBook * addressBook,char phone[]);
 int validmail( AddressBook * addressBook,char mail[]);

 int searchContact(AddressBook *addressBook,int mode);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);

void listContacts(AddressBook *addressBook);

void initialize(AddressBook *addressBook);
void loadContactsFromFile(AddressBook *addressBook);

void saveContactsToFile(AddressBook *AddressBook);

void savetoFile(AddressBook * addressBook);

#endif
