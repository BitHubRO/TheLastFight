#ifndef CUSTOM_STRUCTURES_H_INCLUDED
#define CUSTOM_STRUCTURES_H_INCLUDED

/*************************************************************/
/* Custom_structures.h - Header file for custom structures   */
/* Copyright: 2022                                           */
/* License: Tehnical University of Cluj-Napoca               */
/* Author: Marian Elisei and Antonia Lutsch                  */
/* Version: 08-01-2023                                       */
/* Updates: -                                                */
/*************************************************************/


typedef struct{

    int life, attack, armor, heal;

}Character;

typedef struct{
    int heal, protection, attack;
}Buff;
#endif // CUSTOM_STRUCTURES_H_INCLUDED
