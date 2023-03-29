#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#if defined(_WIN32)
#include <windows.h>
#endif
#include <time.h>

#include "char_creation.h"
#include "Custom_structures.h"


/*************************************************************************/
/* FUNCTION NAME: rare_special_events                                    */
/* DESCRIPTION: determines and prints a rare special event               */
/* ARGUMENT LIST:                                                        */
/* Argument              Type     IO   Description                       */
/* _____________________ ________ ____ __________________________________*/
/* p                     Buff*    I    points to the player's temporary  */
/*                                     buffs                             */
/* round                 int      I    the round number                  */
/* RETURN VALUE: void                                                    */
/* CHANGES: -                                                            */
/*************************************************************************/

void rare_special_events(Buff *p, int round)
{
    char attack_rare_special[]  = "attack_rare_special.txt";
    char heal_rare_special[]    = "heal_rare_special.txt";
    char protect_rare_special[] = "protect_rare_special.txt";
    //srand(time(NULL));
    int case_random = rand()%3+1;


    if (round != 1 && sqrt(round) * sqrt(round) == round)
    {
        //random function in variable case_random
        switch (case_random)
        {
            case 1:
            {
                file_print(attack_rare_special);
                p->attack+= 2;

                break;
            }

            case 2:
            {
                file_print(protect_rare_special);
                p -> protection += 2;


                break;
            }

            case 3:
            {
                file_print(heal_rare_special);
                p->heal += 2;

                break;
            }

        }
    }
}

/*************************************************************************/
/* FUNCTION NAME: normal_special_events                                  */
/* DESCRIPTION: determines and prints a normal special event             */
/* ARGUMENT LIST:                                                        */
/* Argument                Type     IO   Description                     */
/* _______________________ ________ ____ ________________________________*/
/* choice_m                int      I    Choice of the monster           */
/* p                       Buff*    I    points to monster's temporary   */
/*                                       buffs                           */
/* round                   int      I    the round number                */
/* level                   int      I    level                           */
/* RETURN VALUE: void                                                    */
/* CHANGES: the values for the monster's buffs for a round               */
/*************************************************************************/

void normal_special_events(int choice_m, Buff *m, int round, int level)
{
    char attack_normal_special[]  = "attack_normal_special.txt";
    char heal_normal_special[]    = "heal_normal_special.txt";
    char armor_normal_special[]   = "armor_normal_special.txt";

    if(level <= 3 && round % 3 == 0)
        switch (choice_m)
        {
            case 1:
            {
                if(round % 2 == 0)
                {
                    file_print(attack_normal_special);
                    m->attack -= 2;
                }
                else
                {
                    file_print(armor_normal_special);
                    m->protection -= 2;
                }
                break;
            }

            case 3:
            {
                file_print(heal_normal_special);
                m->heal -= 2;
                break;
            }
        }
    else if(round % 5 == 0)
        switch (choice_m)
        {
            case 1:
                file_print(attack_normal_special);
                m->attack -= 2;

                break;
            case 2:
                file_print(heal_normal_special);
                m->heal -= 2;

                break;
            case 3:
                file_print(armor_normal_special);
                m->protection -= 2;

                break;
        }
    }

