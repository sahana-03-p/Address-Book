#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include <ctype.h>

//Function to list contacts based on sorting criteria
void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    // Sort contacts based on the chosen criteria
    
    switch(sortCriteria)
    {
        case 1: //Sort by name
                for(size_t i = 0; i < (addressBook -> contactCount) - 1; i++)
                {
                    for(size_t j = 0; j < (addressBook -> contactCount) - i - 1; j++)
                    {
                        if(strcasecmp(addressBook -> contacts[j].name,addressBook -> contacts[j+1].name) > 0)
                        {
                            Contact  temp =  addressBook -> contacts[j];
                            addressBook -> contacts[j] = addressBook -> contacts[j+1];
                            addressBook -> contacts[j+1] = temp;
                        }
                    }
                }

                //Printing header
                printf("%-30s%-30s%-30s\n","Name","Phone","Email");

                //Printing contacts
                for(size_t i = 0; i < addressBook -> contactCount; i++)
                {
                    printf("%-30s%-30s%-30s\n",addressBook -> contacts[i].name,
                                               addressBook -> contacts[i].phone,
                                               addressBook -> contacts[i].email);
                }
                break;
        case 2: //Sort by phone
                for(size_t i = 0; i < (addressBook -> contactCount) - 1; i++)
                {
                    for(size_t j = 0; j < (addressBook -> contactCount) - i - 1; j++)
                    {
                        if(strcasecmp(addressBook -> contacts[j].phone,addressBook -> contacts[j+1].phone) > 0)
                        {
                            Contact  temp =  addressBook -> contacts[j];
                            addressBook -> contacts[j] = addressBook -> contacts[j+1];
                            addressBook -> contacts[j+1] = temp;
                        }
                    }
                }

                //Printing header
                printf("%-30s%-30s%-30s\n","Name","Phone","Email");

                //Printing contacts
                for(size_t i = 0; i < addressBook -> contactCount; i++)
                {
                    printf("%-30s%-30s%-30s\n",addressBook -> contacts[i].name,
                                               addressBook -> contacts[i].phone,
                                               addressBook -> contacts[i].email);
                }
                break;
        case 3: //Sort by email
                for(size_t i = 0; i < (addressBook -> contactCount) - 1; i++)
                {
                    for(size_t j = 0; j < (addressBook -> contactCount) - i - 1; j++)
                    {
                        if(strcasecmp(addressBook -> contacts[j].email,addressBook -> contacts[j+1].email) > 0)
                        {
                            Contact  temp =  addressBook -> contacts[j];
                            addressBook -> contacts[j] = addressBook -> contacts[j+1];
                            addressBook -> contacts[j+1] = temp;
                        }
                    }
                }

                //Printing header
                printf("%-30s%-30s%-30s\n","Name","Phone","Email");

                //Printing contacts
                for(size_t i = 0; i < addressBook -> contactCount; i++)
                {
                    printf("%-30s%-30s%-30s\n",addressBook -> contacts[i].name,
                                               addressBook -> contacts[i].phone,
                                               addressBook -> contacts[i].email);
                }
                break;

        case 4: //Printing without sorting
                printf("Name                           Phone                           Email\n");

                for(size_t i = 0; i < addressBook -> contactCount; i++)
                {
                    printf("%-30s%-30s%-30s\n",addressBook -> contacts[i].name,
                                               addressBook -> contacts[i].phone,
                                               addressBook -> contacts[i].email);
                }
                break;
    }
    
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}

//Function to create new contacts
void createContact(AddressBook *addressBook)
{ 
    char name[50];
    char phone[15];
    char email[30];
    
    // Read inputs
    printf("Enter the Name : ");
    getchar();
    scanf("%[^\n]",name);

    // validation of name
    int ret = validate_name(name);

    if(ret == 0)
    {
        printf("Entered name is Invalid!");
        return;
    }

    printf("Enter the Phone number : ");
    scanf("%s",phone);

    int result = validate_phone_number(phone,addressBook);

    // Validation of phone
    if(result == 0)
    {
        printf("Entered phone number is not valid!\n");
        return;
    }

    printf("Enter the Email ID : ");
    scanf("%s",email);

    // Validation of email
    int res = validate_email(email,addressBook);

    if(res == 0)
    {
        printf("Entered mail is not valid!\n");
        return;
    }

    // Store contacts 
    strcpy(addressBook->contacts[addressBook->contactCount].name, name);
    strcpy(addressBook->contacts[addressBook->contactCount].phone, phone);
    strcpy(addressBook->contacts[addressBook->contactCount].email, email);

    addressBook->contactCount++;

    printf("Contact added!\n");
    
}   

// Function to search contacts
int searchContact(AddressBook *addressBook) 
{
    char search[50];
    int found = 0;
    int choice;

    // Print Menu 
    printf("\n........Search Menu........\n");

    printf("1.Search by Name\n");
    printf("2.Search by Phone Number\n"); 
    printf("3.Search by Email ID\n");   

    // Read inputs
    printf("Enter your choice :");
    scanf("%d",&choice);

    printf("Enter the Name/Phone number/Email ID you want to search:");
    getchar();
    scanf("%[^\n]",search);

    printf("%-10s%-30s%-30s%-30s\n","index","Name","Phone","Email");
    
        switch(choice)
        {
            case 1: // Search by name
                for(int i = 0; i < addressBook -> contactCount; i++)
                {
                    if(strcasecmp(addressBook -> contacts[i].name,search) == 0)
                    {
                        printf("%-10d%-30s%-30s%-30s\n",i,addressBook -> contacts[i].name,
                                                          addressBook -> contacts[i].phone,
                                                          addressBook -> contacts[i].email);
                        found = 1;
                    }
                }
                    break;
                    
            case 2: // Search by phone
                for(int i = 0; i < addressBook -> contactCount; i++)
                {
                   if(strcasecmp(addressBook -> contacts[i].phone,search) == 0)
                   {
                       printf("%-10d%-30s%-30s%-30s\n",i,addressBook -> contacts[i].name,
                                                         addressBook -> contacts[i].phone,
                                                         addressBook -> contacts[i].email);
                       found = 1;
                   }
                }
                   break;

            case 3: // Search by email
                for(int i = 0; i < addressBook -> contactCount; i++)
                {
                   if(strcasecmp(addressBook -> contacts[i].email,search) == 0)
                   {
                       printf("%-10d%-30s%-30s%-30s\n",i,addressBook -> contacts[i].name,
                                                         addressBook -> contacts[i].phone,
                                                         addressBook -> contacts[i].email);
                       found = 1;
                   }
                }
                   break;

            default: // Invalid choice
                   printf("Invalid choice!\n");
                   return 0;
        }

    if(found == 0)
    {
        printf("No contacts found");
        return 0;
    }

    return 1;
}

// Function to edit contact
void editContact(AddressBook *addressBook)
{
    // To edit 1st search for a entered contact
    int ret = searchContact(addressBook);

    if(ret == 0)
    {
        printf("Contact is not found\n");
    }
    else
    {
        printf("Contact is found\n");
    }

    if(addressBook->contactCount == 0) 
    {
        printf("No contacts available to edit.\n");
        return;
    }

    int choice;
    int index;
    char name[30];
    char phone[20];
    char email[40];

    // Print the menu
    printf("\n........Edit Menu........\n");
    printf("1.Edit by Name\n");
    printf("2.Edit by Phone Number\n"); 
    printf("3.Edit by Email ID\n");   

    // Read the inputs
    printf("Enter your choice :");
    scanf("%d",&choice);

    printf("Enter the index of contact you want to edit: ");
    scanf("%d",&index);

    // Check index
    if(index < 0 || index >= addressBook->contactCount)
    {
        printf("Invalid index!\n");
        return;
    }

    //confirm before editing
    char confirm;
    printf("Are you sure want to edit this contact? (y/n): ");
    getchar(); // clear buffer
    scanf("%c",&confirm);

    if(confirm != 'y' && confirm != 'Y')
    {
        printf("Can't edit the contact.\n");
        return;
    }

    switch(choice)
    {
        case 1: // Edit by name
                printf("Enter the Name:");
                getchar();
                scanf("%[^\n]",name);

                // Validation of name
                int ret = validate_name(name);

                 if(ret == 0)
                {
                    printf("Entered name is Invalid!");
                    return;
                }
                
                strcpy(addressBook -> contacts[index].name,name);
                break;
        case 2: // Edit by phone
                printf("Enter the Phone Number:");
                getchar();
                scanf("%[^\n]",phone);

                // Validation of phone
                int result = validate_phone_number(phone,addressBook);

                if(result == 0)
                {
                    printf("Entered phone number is not valid!\n");
                    return;
                }
                
                strcpy(addressBook -> contacts[index].phone,phone);
                break;
        case 3: // Edit by email
                printf("Enter the Email ID:");
                getchar();
                scanf("%[^\n]",email);
                
                // Validation of email
                int res = validate_email(email,addressBook);

                if(res == 0)
                {
                    printf("Entered mail is not valid!\n");
                    return;
                }
                strcpy(addressBook -> contacts[index].email,email);
                break;
        default: //Invalid choice
                printf("Invalid choice!\n");
                return;
    }
    printf("Contact updated successfully!\n");
}

// Function to delete contact
void deleteContact(AddressBook *addressBook)
{
	// To delete 1st search for a entered contact
    int ret = searchContact(addressBook);

    if(ret == 0)
    {
        printf("Contact is not found\n");
    }
    else
    {
        printf("Contact is found\n");
    }
    
    if(addressBook->contactCount == 0) 
    {
        printf("No contacts available to edit.\n");
        return;
    }

    int index;

    // Read inputs
    printf("Enter the index of contact you want to delete: ");
    scanf("%d",&index);

    // Check index
    if(index < 0 || index >= addressBook->contactCount)
    {
        printf("Invalid index!\n");
        return;
    }

    //confirm before deleting
    char confirm;
    printf("Are you sure want to delete this contact? (y/n): ");
    getchar(); // clear buffer
    scanf("%c",&confirm);

    if(confirm != 'y' && confirm != 'Y')
    {
        printf("Can't delete the contact.\n");
        return;
    }

    // Shift contacts
    for(int i = index; i < addressBook -> contactCount - 1; i++)
    {
        addressBook -> contacts[i] = addressBook -> contacts[i+1];
    }

    addressBook -> contactCount--;
    printf("Contact deleted successfully!\n");
}

// Function to validate the name (only letters and spaces allowed)
int validate_name(char *name)
{
    int i = 0;
    while(name[i] != '\0')
    {
        if(!(name[i] >= 'A' && name[i] <= 'Z' || name[i] >= 'a' && name[i] <= 'z' || name[i] == ' '))
        {
                return 0;
        }
        i++;
    }
    return 1;
}

// Function to validate the phone (10 digits, unique, only numbers allowed)
int validate_phone_number(char *phone, AddressBook *addressBook)
{
    int i = 0;

    while(phone[i])
    {
        if(!(phone[i] >= '0' && phone[i] <= '9'))
        {
            return 0;
        }
        i++;
    }

    if(i != 10) // Must be 10 digits
    {
        return 0;
    }
    else if(i == 10)
    {
        for(int j = 0; j < addressBook -> contactCount; j++)
        {
            if(strcmp(addressBook -> contacts[j].phone,phone) == 0)
            {
                return 0;
            }
        }
    }
    else
    {
        return 0;
    }

    return 1;
}

// Function to validate the email 
int validate_email(char *email, AddressBook *addressBook)
{
    // Cheack duplicates
    for(int i = 0; i < addressBook -> contactCount; i++)
    {
            if(strcmp(addressBook -> contacts[i].email,email) == 0)
            {
                return 0;
            }
    }

    if(strchr(email,'@'))
    {
        char *p1 = strchr(email,'@');

        if(strchr(email,'.'))
        {
            char *p2 = strchr(email,'.');

            if((p2) > (p1)) // Dot must come after @
            {
                if(isalnum(*(p1 + 1)) && isalnum(*(p1 - 1))) // Cheack before and after the at (@) character is there or not
                {
                    if((isalnum(*(p2 + 1))) && isalnum(*(p2 - 1))) // Cheack before and after the dot (.) character is there or not
                    {
                        int j = 0;
                        while(email[j]) // Loop for checking only small characters, numeric characters, @ , underscore and dot
                        {
                            if((email[j] >= 'a' && email[j] <= 'z') ||
                                 (email[j] >= '0' && email[j] <= '9') || 
                                    email[j] == '@' || email[j] == '.' || email[j] == '_')
                            {
                                j++;
                                continue;
                            }
                            else
                            {
                                return 0; 
                            }
                        }
                        return 1;
                    }
                }
            }
        }
    }
}