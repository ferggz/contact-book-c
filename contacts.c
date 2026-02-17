#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "contacts.h"

void add_contact(Contact contacts[], int *count)
{
    if (*count >= MAX)
    {
        printf("Contact list is full.\n");
        return;
    }

    contacts[*count].name = get_string("What's your contact name? ");
    contacts[*count].tel = get_string("What's your contact telephone number? ");
    contacts[*count].email = get_string("What's your contact email address? ");

    (*count)++;
}

void list_contacts(Contact contacts[], int count)
{
    if (count == 0)
    {
        printf("No contacts yet.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        printf("%s, %s, %s\n", contacts[i].name, contacts[i].tel, contacts[i].email);
    }
}

void save_contacts(Contact contacts[], int count)
{

    FILE *file = fopen("contacts.csv", "w");
    if (file == NULL)
    {
        printf("Failed.\n");
        return;
    }

    for (int s = 0; s < count; s++)
    {
        fprintf(file, "%s,%s,%s\n", contacts[s].name, contacts[s].tel, contacts[s].email);
    }

    fclose(file);
    printf("Contacts saved.\n");
}

void load_contacts(Contact contacts[], int *count)
{
    FILE *file = fopen("contacts.csv", "r");
    if (file == NULL)
    {
        return;
    }

    char line[200];

    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (*count >= MAX)
        {
            printf("Can't load more contacts. Surpassed limit (%d).\n", MAX);
            break;
        }

        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n')
        {
            line[len - 1] = '\0';
        }

        char *token1 = strtok(line, ",");
        char *token2 = strtok(NULL, ",");
        char *token3 = strtok(NULL, ",");

        if (token1 == NULL || token2 == NULL || token3 == NULL)
        {
            printf("Invalid CSV line skipped: %s.\n", line);
            continue;
        }

        contacts[*count].name = strdup(token1);
        contacts[*count].tel = strdup(token2);
        contacts[*count].email = strdup(token3);

        (*count)++;
    }

    fclose(file);
}

void free_contacts(Contact contacts[], int count)
{
    for (int i = 0; i < count; i++) 
    {
        free(contacts[i].name); 
        free(contacts[i].tel);
        free(contacts[i].email);

        contacts[i].name = NULL; 
        contacts[i].tel = NULL;
        contacts[i].email = NULL;
    }
}

void clear_contacts(Contact contacts[], int *count)
{
    free_contacts(contacts, *count);
    *count = 0;
}