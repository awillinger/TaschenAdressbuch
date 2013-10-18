/*
  Name of file  : adressbuch.h
  Author        : Jakob Klepp <jklepp@student.tgm.ac.at>
  Version       : 20131018.1
  Description   : Stellt die structs PERSON und ADDRESS zu verfuegung
                  ausserdem Funktionen zum auflisten, einlesen, entfernen 
                  aendern von Personen
                  und zum ausgeben der Adressdaten einer Person
*/
#include <stdlib.h>

/* boolean typ */ 
typedef int bool;
#define TRUE 1
#define FALSE 0

/*! \brief Struktur von Adressdaten
 */
typedef struct 
{
    char street_address_l1[64];
    char street_address_l2[64];
    char city[64];
    char country[64];
    char state[64];
    char postal_code[24];
} ADDRESS;

/*! \brief Struktur von Personendaten
 */
typedef struct
{
    char fname[64];
    char sname[64];
    ADDRESS address;
    char telephone[24];
    char email[256];
} PERSON;

/*! \brief listet die Namen der Personen
 *
 * \param 
 *
 * \param
 */
void list_p(const size_t p_size, const PERSON **people);

/*! \brief liest einen neuen Eintrag von der Commanline ein
 *
 * \param
 *
 * \param
 *
 * \return
 */
PERSON* readin_p(size_t *p_size, PERSON **people);

/*! \brief entfernt eine Person aus dem Adressbuch
 *
 * \param
 *
 * \param
 *
 * \param
 *
 * \return
 */
bool remove_p(size_t *p_size, PERSON **people, PERSON *person);

/*! \brief aendert eine Person, fragt Benutzer nach aenderungswuenschen
 *
 * \param
 *
 * \param
 *
 * \param
 *
 * \return
 */
PERSON* modify_p(size_t *p_size, PERSON **people, PERSON *person);

/*! \brief zeigt alle Daten zu einer Person an
 *
 * \param
 *
 * \return
 */
bool show_p(const PERSON *person);


/*! \brief buffer leeren */
void clear_buffer(void);