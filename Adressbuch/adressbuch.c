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

    for(i=0;;);

    return offset ? TRUE : FALSE;
}

PERSON* modify_p(size_t *p_size, PERSON **people, PERSON *person)
{

}

bool show_p(const PERSON *person)
{

}

void clear_buffer()
{
    char c;

    // alle zeichen aus dem Puffer lesen, dadurch wird er geleert
    while((c = getchar()) != EOF && c != '\n');
}