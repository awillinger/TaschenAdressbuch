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
#include 'adressbuch.h'

int main(int argc, char** argv)
{
    PERSON **people = NULL;
    size_t p_size = 0;
    bool_t stop = false;
    while(!stop)
    {
        printf("Was wollen sie machen?\n");
    }
    return EXIT_SUCCESS;
}

void list(const size_t *p_size, const PERSON **people)
{
    size_t i;
    for(i = 0; i < *p_size; ++i)
    {
        if(*(people+i) != NULL 
        &&  (**(people+i)).fname != NULL 
        &&  (**(people+i)).sname != NULL)
        {
            printf("%s %s\n", *(*people+i).fname, *(*people+i).sname);
        }
    }
}

PERSON* readin(size_t *p_size, PERSON **people)
{
    PERSON *person = NULL;
    person = malloc(sizeof(PERSON));
    if(person == NULL)
    {
        return NULL;
    }
    printf("\n");

    return person;
}

bool_t remove(size_t *p_size, PERSON **people, PERSON *person)
{

}

PERSON* modify(size_t *p_size, PERSON **people, PERSON *person)
{

}

bool_t show(const PERSON *person)
{

}