#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
    
    FILE *fptr = fopen("contacts.csv","w"); // Open file in write mode

    fprintf(fptr,"%d\n",addressBook -> contactCount); // print output

    for(size_t i = 0; i < addressBook -> contactCount; i++)  
    {
        // Print name, phone no, email
        fprintf(fptr,"%s, %s, %s\n",addressBook -> contacts[i].name, addressBook -> contacts[i].phone, addressBook -> contacts[i].email);
    }

    fclose(fptr); // Close file
}

void loadContactsFromFile(AddressBook *addressBook) {
    
    FILE *fptr = fopen("contacts.csv","r"); // Open file in read mode

    fscanf(fptr,"%d\n",&(addressBook -> contactCount)); // Reading input

    for(size_t i = 0; i < addressBook -> contactCount; i++)
    {
         // Print name, phone no, email
        fscanf(fptr,"%[^,], %[^,], %[^\n]\n",addressBook -> contacts[i].name, addressBook -> contacts[i].phone, addressBook -> contacts[i].email);
    }

    fclose(fptr); // Close file
}
