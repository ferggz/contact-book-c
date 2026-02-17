#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>
#include "contacts.h"

int main(void)
{
    Contact contacts[MAX];
    int count = 0;
    load_contacts(contacts, &count);
    printf("Loaded %i contacts.\n", count);

    int option;

    while (true)
    {
        printf("1. Add contact\n");
        printf("2. List contacts\n");
        printf("3. Save contacts\n");
        printf("4. Exit\n");

        option = get_int("Choose an option: ");

        switch (option)
        {
            case 1:
            add_contact(contacts, &count);
            break;

            case 2:
            list_contacts(contacts, count);
            break;

            case 3:
            save_contacts(contacts, count);
            break;

            case 4:
            free_contacts(contacts, count);
            printf("Bye!\n");
            return 0;

            default:
            printf("Invalid option.\n");
            break;
        }
    }
}
