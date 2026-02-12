#include <cs50.h>
#include <stdio.h>

#define MAX 100

typedef struct
{
    char *name;
    char *tel;
    char *email;
} Contact;

void add_contact(Contact contacts[], int *count);

void list_contacts(Contact contacts[], int count);

void save_contacts(Contact contacts[], int count);

void load_contacts(Contact contacts[], int *count);
