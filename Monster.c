#include "monster.h"
#include "Custom_structures.h"
#if defined(_WIN32)
#include <windows.h>
#endif
#include <time.h>
#include "char_creation.h"


/*************************************************************************/
/* FUNCTION NAME: MonsterParameters                                      */
/* DESCRIPTION: initializes the monster`s basic HP, attack and armor     */
/* ARGUMENT LIST:                                                        */
/* Argument              Type      IO   Description                      */
/* _____________________ _________ ____ _________________________________*/
/* monst                 Character I    points to the variable that      */
/*                                      stores the monster`s parameters  */
/*                                                                       */
/* level                 int       I    determines how powerful          */
/*                                      the monster is                   */
/* RETURN VALUE: void                                                    */
/* CHANGES: the values of the monst                                                            */
/*************************************************************************/

void MonsterParameters(Character *monst, int level){

    monst->life = 20 + 5 * level;
    monst->attack = 6 + level;
    if( level <= 3 )
        {
            monst->armor = 1;
            monst->heal = 2;
        }
    else if( level == 4)
        {
            monst->armor = 2;
            monst->heal = 3;
        }
    else
    {
         monst->armor = 3;
         monst->heal = 4;
    }


}

/*************************************************************************/
/* FUNCTION NAME: MonsterChoices                                         */
/* DESCRIPTION: determines the choice of the monster                     */
/* ARGUMENT LIST:                                                        */
/* Argument              Type      IO   Description                      */
/* _____________________ _________ ____ _________________________________*/
/* level                 int       I    determines how many choices      */
/*                                      the monster can make             */
/* RETURN VALUE: int 0 for miss, 1 for attack, 2 for dodge, 3 for heal   */
/* CHANGES: -                                                            */
/*************************************************************************/

int MonsterChoice(int level){

    //srand(time(NULL));
    int choice;
    if(level <4)
        choice = rand() % 3;
    else
        choice = rand() % 4;

    return choice;
}

/*************************************************************************/
/* FUNCTION NAME: MonsterLines                                           */
/* DESCRIPTION: displays the dialog of the monster                       */
/* ARGUMENT LIST:                                                        */
/* Argument              Type      IO   Description                      */
/* _____________________ _________ ____ _________________________________*/
/* choice                int       I    determines the line that         */
/*                                      the monster should say           */
/* RETURN VALUE: void                                                    */
/* CHANGES: -                                                            */
/*************************************************************************/

void MonsterLines(int choice)
{
    // asta trebuie facuta global undeva cred
    char oneliner[20][150];
    FILE *f_p = fopen("oneliners.txt","r");
    rewind(f_p);
    for(int i = 0; i < 19; i++)
        fgets(oneliner[i], 150, f_p);
    fclose(f_p);

    //srand(time(NULL));
    int random = rand() % 4;

    switch (choice)
    {
        case 0:{

            printf("\n%s", oneliner[random]);
            break;
        }
        case 1:{
            printf("\n%s", oneliner[random + 5]);
            break;
        }
        case 2:{
            printf("\n%s", oneliner[random + 10]);
            break;
        }
        case 3:{
            printf("\n%s", oneliner[random + 15]);
            break;
        }
    }
}
