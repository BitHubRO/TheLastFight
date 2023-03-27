#ifndef CHAR_CREATION_H_INCLUDED
#define CHAR_CREATION_H_INCLUDED

#include <stdlib.h>
#include "Custom_structures.h"

/*************************************************************/
/* char_creation.h - Header file for module char_creation    */
/* Copyright: 2022                                           */
/* License: Tehnical University of Cluj-Napoca               */
/* Author: Marian Elisei and Antonia Lutsch                  */
/* Version: 08-01-2023                                       */
/* Updates: -                                                */
/*************************************************************/


extern void file_print();
extern void center_text();
extern void choose_race(Character *Player);
extern void choose_name(char *);
extern void choose_item(Character *Player);
extern int choose_diff();


#endif // CHAR_CREATION_H_INCLUDED
