#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Custom_structures.h"

/*************************************************************/
/* mosnter.h - Header file for module monster                */
/* Copyright: 2022                                           */
/* License: Tehnical University of Cluj-Napoca               */
/* Author: Marian Elisei and Antonia Lutsch                  */
/* Version: 08-01-2023                                       */
/* Updates: -                                                */
/*************************************************************/


extern void MonsterParameters(Character *monst, int level);
extern int MonsterChoice(int level);
extern void MonsterLines(int choice);


#endif // MONSTER_H_INCLUDED
