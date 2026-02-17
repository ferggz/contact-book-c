#ifndef CONTACTS_H
#define CONTACTS_H

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

void free_contacts(Contact contacts[], int count);

void clear_contacts(Contact contacts[], int *count);

#endif