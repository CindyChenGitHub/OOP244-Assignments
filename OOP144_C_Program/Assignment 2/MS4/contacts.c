/********************************************************************** 
// ICP144 Assignment 2 
// File contacts.c
// Version 1.0 
// Date 2017/12/08 
// Author Cindy Chen 
//-------------------------------------------
//Assignment: 2
//Milestone:  4
/**********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include "contacts.h"
#include "contactHelpers.h"



// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:
void getName(struct Name* fullname)
{
    printf("Please enter the contact's first name: ");
    scanf("%31[^\n]", fullname->firstName);
    clearKeyboard();

    printf("Do you want to enter a middle initial(s)? (y or n): ");
    if (yes()) {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%[^\n]", fullname->middleInitial);
        clearKeyboard();
    }

    printf("Please enter the contact's last name: ");
    scanf("%36[^\n]", fullname->lastName);
    clearKeyboard();
}

// getAddress:
void getAddress(struct Address* fulladress)
{
    printf("Please enter the contact's street number: ");
    fulladress->streetNumber = getInt();

    printf("Please enter the contact's street name: ");
    scanf("%41[^\n]", fulladress->street);
    clearKeyboard();

    printf("Do you want to enter an apartment number? (y or n): ");
    if (yes()) {
        printf("Please enter the contact's apartment number: ");
        fulladress->apartmentNumber = getInt();
        //clearKeyboard();
    }
    printf("Please enter the contact's postal code: ");
    scanf("%8[^\n]", fulladress->postalCode);
    clearKeyboard();

    printf("Please enter the contact's city: ");
    scanf("%41[^\n]", fulladress->city);
    clearKeyboard();
}

// getNumbers:
void getNumbers(struct Numbers* phonenumber)
{
    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(phonenumber->cell);
    printf("Do you want to enter a home phone number? (y or n): ");
    if (yes()) {
        printf("Please enter the contact's home phone number: ");
        getTenDigitPhone(phonenumber->home);

    }

    printf("Do you want to enter a business phone number? (y or n): ");
    if (yes()) {
        printf("Please enter the contact's business phone number: ");
        getTenDigitPhone(phonenumber->business);

    }
}

// getContact:
void getContact(struct Contact* contact)
{
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}
