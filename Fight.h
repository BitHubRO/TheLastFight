#ifndef FIGHT_H_INCLUDED
#define FIGHT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "special_events.h"
#include "Custom_structures.h"

/*************************************************************/
/* Fight.h - Header file for module Fight                    */
/* Copyright: 2022                                           */
/* License: Tehnical University of Cluj-Napoca               */
/* Author: Marian Elisei and Antonia Lutsch                  */
/* Version: 08-01-2023                                       */
/* Updates: -                                                */
/*************************************************************/


extern int Player_Choice();
extern void Display_Stats();
extern void The_Fight();
extern int stop_fight();
extern void Case_Attack(Character*, Character*, int , Buff, Buff);
extern void Case_Dodge(Character*, Character*, int , Buff, Buff);
extern void Case_Heal(Character*, Character*, int , Buff, Buff);

#endif // FIGHT_H_INCLUDED
