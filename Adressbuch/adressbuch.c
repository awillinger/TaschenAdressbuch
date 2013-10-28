/*
  Name of file  : adressbuch.c
  Author        : Jakob Klepp <jklepp@student.tgm.ac.at>
  Version       : 20131018.1
  Description   : Ein Addressbuch mit CLI Menu
                  unter verwendung von zwei Structs (PERSON, ADDRESS)
                  Call-By-Referenc und dynamischer Speicherverwaltung
*/
#include <stdio.h>
#include <stdlib.h>
#include "adressbuch.h"

int main(int argc, char** argv)
{
    PERSON **people = NULL;
    size_t p_size = 0;
    bool stop = FALSE;
    readin_p(&p_size, people);
    while(!stop)
    {
        printf("Was wollen sie machen?\n");
    }
    return EXIT_SUCCESS;
}

void list_p(const size_t p_size, const PERSON **people)
{
    size_t i;
    for(i = 0; i < p_size; ++i)
    {
        if(*(people+i) != NULL 
        &&  (*(people+i))->fname != NULL 
        &&  (*(people+i))->sname != NULL)
        {
            printf("%s %s\n", (*people+i)->fname, (*people+i)->sname);
        }
    }
}

PERSON* readin_p(size_t *p_size, PERSON **people)
{
    PERSON *pperson = NULL;
    pperson = malloc(sizeof(PERSON));
    if(pperson == NULL)
    {
        printf("Kein Speicher verfuegbar um pperson zu allokieren.\n");
    }

    printf("Vorname       : ");
    scanf("%s", (*pperson).fname);
    clear_buffer();

    printf("Nachname      : ");
    scanf("%s", (*pperson).sname);
    clear_buffer();

    printf("Telephonnummer: ");
    scanf("%s", (*pperson).telephone);
    clear_buffer();

    printf("Emailadresse  : ");
    scanf("%s", (*pperson).email);
    clear_buffer();

    printf("Strasse       : ");
    scanf("%s", (*pperson).address.street_address_l1);
    clear_buffer();

    printf("Strasse       : ");
    scanf("%s", (*pperson).address.street_address_l2);
    clear_buffer();

    printf("Stadt         : ");
    scanf("%s", (*pperson).address.city);
    clear_buffer();

    printf("Land          : ");
    scanf("%s", (*pperson).address.country);
    clear_buffer();

    printf("Staat         : ");
    scanf("%s", (*pperson).address.state);
    clear_buffer();

    printf("Postleitzahl  : ");
    scanf("%s", (*pperson).address.postal_code);
    clear_buffer();

    //pperson zu people hinzufuegen
    people = realloc(people, sizeof(people) * ((int)++p_size));
    people[(int)p_size-1] = &pperson; //Im Falle einer Seg Fault hier suchen

    return pperson;
}

bool remove_p(size_t *p_size, PERSON **people, PERSON *person)
{
    int offset = 0;
    int i;

    for(i = 0; i < p_size; ++i)
    {
        if(person == people[i])
        {    
            ++offset;
        }
        people[i - offset] = people[i]; 
    }

    p_size -= offset;

    free(person); //Person von ihren Qualen befreien
    return offset ? TRUE : FALSE; //Wenn offset=0 wurde offensichtlich nichts geloescht
}

PERSON* modify_p(size_t *p_size, PERSON *person)
{   
    char chars24[24];
    char chars64[64];
    char chars256[256];

    printf("Aendern einer Person.\n");
    printf("Bei Eingaben die mit . beginnen wird der alte Wert behalten.\n");

    printf("Vorname        [%s]: ", (*pperson).fname);
    scanf("%s", chars64);
    clear_buffer();
    if('.' != chars64[0])
    {
        memmove(&((*pperson).fname), chars64, 64);    
    }

    printf("Nachname       [%s]: ", (*pperson).sname);
    scanf("%s", chars64);
    clear_buffer();
    if('.' != chars64[0])
    {
        memmove(&((*pperson).sname), chars64, 64);    
    }

    printf("Telephonnummer [%s]: ", (*pperson).telephone);
    scanf("%s", chars24);
    clear_buffer();
    if('.' != chars24[0])
    {
        memmove(&((*pperson).telephone), chars24, 24);    
    }

    printf("Emailadresse   [%s]: ", (*pperson).email);
    scanf("%s", chars256);
    clear_buffer();
    if('.' != chars256[0])
    {
        memmove(&((*pperson).email), chars256, 256);    
    }

    printf("Strasse 1      [%s]: ", (*pperson).address.street_address_l1);
    scanf("%s", chars64);
    clear_buffer();
    if('.' != chars64[0])
    {
        memmove(&((*pperson).address.street_address_l1), chars64, 64);    
    }

    printf("Strasse 2      [%s]: ", (*pperson).address.street_address_l2);
    scanf("%s", chars64);
    clear_buffer();
    if('.' != chars64[0])
    {
        memmove(&((*pperson).address.street_address_l2), chars64, 64);    
    }

    printf("Stadt          [%s]: ", (*pperson).address.city);
    scanf("%s", chars64);
    clear_buffer();
    if('.' != chars64[0])
    {
        memmove(&((*pperson).address.city), chars64, 64);    
    }

    printf("Land           [%s]: ", (*pperson).address.country);
    scanf("%s", chars64);
    clear_buffer();
    if('.' != chars64[0])
    {
        memmove(&((*pperson).address.country), chars64, 64);    
    }

    printf("Staat          [%s]: ", (*pperson).address.state);
    scanf("%s", chars64);
    clear_buffer();
    if('.' != chars64[0])
    {
        memmove(&((*pperson).address.state), chars64, 64);    
    }

    printf("Postleitzahl   [%s]: ", (*pperson).address.postal_code);
    scanf("%s", chars24);
    clear_buffer();
    if('.' != chars24[0])
    {
        memmove(&((*pperson).address.postal_code), chars24, 24);    
    }

    return person;
}

void show_p(const PERSON *person)
{
    printf("Vorname       : %s\n", (*pperson).fname);

    printf("Nachname      : %s\n", (*pperson).sname);

    printf("Telephonnummer: %s\n", (*pperson).telephone);

    printf("Emailadresse  : %s\n", (*pperson).email);

    printf("Strasse 1     : %s\n", (*pperson).address.street_address_l1);

    printf("Strasse 2     : %s\n", (*pperson).address.street_address_l2);

    printf("Stadt         : %s\n", (*pperson).address.city);

    printf("Land          : %s\n", (*pperson).address.country);

    printf("Staat         : %s\n", (*pperson).address.state);

    printf("Postleitzahl  : %s\n", (*pperson).address.postal_code);
}

void clear_buffer()
{
    char c;

    // alle zeichen aus dem Puffer lesen, dadurch wird er geleert
    while((c = getchar()) != EOF && c != '\n');
}