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
#include <string.h>
#include "adressbuch.h"

int main(int argc, char** argv)
{
    PERSON **people = NULL;
    people = malloc(0);

    size_t p_size = 0;
    bool stop = FALSE;
    //readin_p(&p_size, people);

    printf("Was wollen sie machen?\n");
    help();
    while(!stop)
    {
        printf("[h 0|l 0|a 0|r index|m index|s index|q 0]\n");
        stop = input(&p_size, people);
        printf("\n");
    }
    return EXIT_SUCCESS;
}

void help(void)
{
    printf("                                  [ Hilfe ]\n");
    printf("=============================================================================\n");
    printf("                     Diese Befehle stehen zur verfuegung:\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("Help     0 - Zeigt diese Hilfestellung an.\n");
    printf("List     0 - Listet alle eingetragenen Personen auf und zeigt ihren Index an.\n");
    printf("Add      0 - Fuegt eine neue Person hinzu.\n");
    printf("Rm   index - Entfernt die Person am angegebenen Index.\n");
    printf("Mod  index - Aendert die Person am angegebenen Index.\n");
    printf("Show index - Zeigt alle Daten zu der Person am angegebenen Index.\n");
    printf("Quit     0 - Beendet das Programm\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\n");
}

bool input(size_t *p_size, PERSON **people)
{
    char input_string[5];
    int index;
    //muss doch irgendwie moeglich sein die eingabe der zahl optional zu machen
    scanf("%s %d", input_string, &index);
    clear_buffer();
    switch(input_string[0])
    {
        case 'h':case 'H':case '?':
            help();
            break;
        case 'l':case 'L':
            list_p(*p_size, people);
            break;
        case 'a':case 'A':
            readin_p(p_size, people);
            break;
        case 'r':case 'R':
            remove_p(p_size, people, people[index]);
            break;
        case 'm':case 'M':
            modify_p(people[index]);
            break;
        case 's':case 'S':
            show_p(people[index]);
            break;
        case 'q':case 'Q':
            return TRUE;
    }
    return FALSE; //Benutzer will das Programm nicht beenden
}

void list_p(const size_t p_size, PERSON **people)
{
    size_t i;
    for(i = 0; i < p_size; ++i)
    {
        if(*(people+i) != NULL 
        &&  (*(people+i))->fname != NULL 
        &&  (*(people+i))->sname != NULL)
        {
            printf("[%zu] %s %s\n", i, (*people+i)->fname, (*people+i)->sname);
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
    people = realloc(people, sizeof(void*) * ((int)++(*p_size)));
    people[(int)(*p_size)-1] = pperson; //Im Falle einer Seg Fault hier suchen

    return pperson;
}

bool remove_p(size_t *p_size, PERSON **people, PERSON *person)
{
    int offset = 0;
    int i;

    for(i = 0; i < *p_size; ++i)
    {
        if(person == people[i])
        {    
            ++offset;
        }
        people[i - offset] = people[i]; 
    }

    p_size -= offset;

    free(person); //Person von ihren Qualen befreien
    return offset ? TRUE : FALSE; //Wenn offset=0 wurde offensichtlich nichts 
                                  //geloescht
}

void modify_p(PERSON *person)
{   
    char chars24[24];
    char chars64[64];
    char chars256[256];

    printf("Aendern einer Person.\n");
    printf("Bei Eingaben die mit . beginnen wird der alte Wert behalten.\n");

    printf("Vorname        [%s]: ", (*person).fname);
    scanf("%s", chars64);
    clear_buffer();
    if('.' != chars64[0])
    {
        memmove(&((*person).fname), chars64, 64);    
    }

    printf("Nachname       [%s]: ", (*person).sname);
    scanf("%s", chars64);
    clear_buffer();
    if('.' != chars64[0])
    {
        memmove(&((*person).sname), chars64, 64);    
    }

    printf("Telephonnummer [%s]: ", (*person).telephone);
    scanf("%s", chars24);
    clear_buffer();
    if('.' != chars24[0])
    {
        memmove(&((*person).telephone), chars24, 24);    
    }

    printf("Emailadresse   [%s]: ", (*person).email);
    scanf("%s", chars256);
    clear_buffer();
    if('.' != chars256[0])
    {
        memmove(&((*person).email), chars256, 256);    
    }

    printf("Strasse 1      [%s]: ", (*person).address.street_address_l1);
    scanf("%s", chars64);
    clear_buffer();
    if('.' != chars64[0])
    {
        memmove(&((*person).address.street_address_l1), chars64, 64);    
    }

    printf("Strasse 2      [%s]: ", (*person).address.street_address_l2);
    scanf("%s", chars64);
    clear_buffer();
    if('.' != chars64[0])
    {
        memmove(&((*person).address.street_address_l2), chars64, 64);    
    }

    printf("Stadt          [%s]: ", (*person).address.city);
    scanf("%s", chars64);
    clear_buffer();
    if('.' != chars64[0])
    {
        memmove(&((*person).address.city), chars64, 64);    
    }

    printf("Land           [%s]: ", (*person).address.country);
    scanf("%s", chars64);
    clear_buffer();
    if('.' != chars64[0])
    {
        memmove(&((*person).address.country), chars64, 64);    
    }

    printf("Staat          [%s]: ", (*person).address.state);
    scanf("%s", chars64);
    clear_buffer();
    if('.' != chars64[0])
    {
        memmove(&((*person).address.state), chars64, 64);    
    }

    printf("Postleitzahl   [%s]: ", (*person).address.postal_code);
    scanf("%s", chars24);
    clear_buffer();
    if('.' != chars24[0])
    {
        memmove(&((*person).address.postal_code), chars24, 24);    
    }
}

void show_p(const PERSON *person)
{
    printf("Vorname       : %s\n", (*person).fname);

    printf("Nachname      : %s\n", (*person).sname);

    printf("Telephonnummer: %s\n", (*person).telephone);

    printf("Emailadresse  : %s\n", (*person).email);

    printf("Strasse 1     : %s\n", (*person).address.street_address_l1);

    printf("Strasse 2     : %s\n", (*person).address.street_address_l2);

    printf("Stadt         : %s\n", (*person).address.city);

    printf("Land          : %s\n", (*person).address.country);

    printf("Staat         : %s\n", (*person).address.state);

    printf("Postleitzahl  : %s\n", (*person).address.postal_code);
}

void clear_buffer()
{
    char c;

    // alle zeichen aus dem Puffer lesen, dadurch wird er geleert
    while((c = getchar()) != EOF && c != '\n');
}