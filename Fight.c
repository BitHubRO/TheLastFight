#include "Fight.h"
#include "Custom_structures.h"
#include "Monster.h"
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
//#include<unistd.h>

/*************************************************************************/
/* FUNCTION NAME: Player_Choice                                          */
/* DESCRIPTION: gets the player's choice                                 */
/* ARGUMENT LIST:                                                        */
/* Argument              Type      IO   Description                      */
/* _____________________ _________ ____ _________________________________*/
/*                                                                       */
/* RETURN VALUE: int 1 for attack, 2 for dodge, 3 for heal               */
/* CHANGES: -                                                            */
/*************************************************************************/

int Player_Choice(){
    int p_choice;

    printf("What do you want to do this round?\n1 -> attack\n2 -> dodge\n3 -> heal\n");
    scanf("%d",&p_choice);

    return p_choice;
}

/*************************************************************************/
/* FUNCTION NAME: The_Fight                                              */
/* DESCRIPTION: emulates a fight with the monster                        */
/* ARGUMENT LIST:                                                        */
/* Argument              Type       IO   Description                     */
/* _____________________ _________  ____ ________________________________*/
/* Player                Character* I    points to the variable that     */
/*                                       stores the player stats         */
/* Monster               Character  I    points to the variable that     */
/*                                       stores the monster stats        */
/* round                 int        I    the round number                */
/* level                 int        I    level                           */
/* RETURN VALUE: void                                                    */
/* CHANGES: -                                                            */
/*************************************************************************/

void The_Fight(Character *Player, Character *Monster, int round, int level){

    Buff p,m;

    p.attack     = 0;
    p.heal       = 0;
    p.protection = 0;

    m.attack     = 0;
    m.heal       = 0;
    m.protection = 0;


    char ASCII_minotaur2[]   = "ASCII_minotaur2.txt";

    rare_special_events(&p, round);
    file_print(ASCII_minotaur2);
    printf("\n\n");


    int player_choice = Player_Choice();

    //srand(time(NULL));
    int monster_choice = MonsterChoice(level);
    normal_special_events(monster_choice, &m, round, level);

    if(monster_choice == 0)
        printf("The monster missed!");
    else if(monster_choice == 1)
        {
            if(player_choice == 2)
                printf("The monster tried attack you!");
            else
                printf("The monster attacked you!");
        }
        else if(monster_choice == 3)
            printf("The monster healed!");
            else
                printf("The monster dodged!");


    //1-> attack  2->dodge  3->heal

    switch (player_choice)
    {
        case 1:
        {
           Case_Attack(Player,Monster, monster_choice, p, m);
           break;
        }
        case 2:
        {
            Case_Dodge(Player, Monster, monster_choice, p, m);
            break;
        }
        case 3:
        {
            Case_Heal(Player, Monster, monster_choice, p, m);
            break;
        }
    }
    //free(monster_choice);
    //sleep(5);
}

/*************************************************************************/
/* FUNCTION NAME: Display_Stats                                          */
/* DESCRIPTION: distplays the stats of the player and monster            */
/* ARGUMENT LIST:                                                        */
/* Argument              Type      IO   Description                      */
/* _____________________ _________ ____ _________________________________*/
/* Player                Character* I    points to the variable that     */
/*                                       stores the player stats         */
/* Monster               Character  I    points to the variable that     */
/*                                       stores the monster stats        */
/* RETURN VALUE: void                                                    */
/* CHANGES: -                                                            */
/*************************************************************************/

void Display_Stats(Character *Player, Character *Monster){
    system("cls");
    printf("Your HP:%d \t\t\t\t\t\t\t\t\t\t\t\t Monster HP:%d\nYour attack:%d \t\t\t\t\t\t\t\t\t\t\t\t Monster attack:%d\nYour armor:%d \t\t\t\t\t\t\t\t\t\t\t\t Monster armor:%d\n", Player->life, Monster->life, Player->attack, Monster->attack, Player->armor, Monster->armor);
    printf("---------------------------------------------------------------------------------------------------------------------------------------\n\n\n");

}

/*************************************************************************/
/* FUNCTION NAME: stop_fight                                             */
/* DESCRIPTION: verifies if the fight can continue                       */
/* ARGUMENT LIST:                                                        */
/* Argument              Type      IO   Description                      */
/* _____________________ _________ ____ _________________________________*/
/* Player                Character* I    points to the variable that     */
/*                                       stores the player stats         */
/* Monster               Character  I    points to the variable that     */
/*                                       stores the monster stats        */
/* RETURN VALUE: int 0 for continue, 1 for stop                          */
/* CHANGES: -                                                            */
/*************************************************************************/

int stop_fight(Character *Player, Character *Monster){
    if(Player->life<=0 || Monster->life<=0)
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tThe fight has ended!");
            //sleep(3);
            return 1;
        }
    return 0;
}

/*************************************************************************/
/* FUNCTION NAME: Case_Attack                                            */
/* DESCRIPTION: posibilities if the player choses to attack              */
/* ARGUMENT LIST:                                                        */
/* Argument              Type      IO   Description                      */
/* _____________________ _________ ____ _________________________________*/
/* Player                Character* I    points to the variable that     */
/*                                       stores the player stats         */
/* Monster               Character  I    points to the variable that     */
/*                                       stores the monster stats        */
/* monster_choice        int        I    the choice of the monster       */
/* p                     Buff       I    buffs for player                */
/* m                     Buff       I    buffs for monster               */
/* RETURN VALUE: void                                                    */
/* CHANGES: Player's and/or Monster HP                                   */
/*************************************************************************/

void Case_Attack(Character *Player, Character *Monster, int monster_choice, Buff p, Buff m)
{
    if(monster_choice == 0)
    {
        Monster->life -= Player->attack + p.attack - Monster->armor ;
        MonsterLines(0);
    }

    if(monster_choice == 1)
    {
        Monster->life -= Player->attack + p.attack - Monster->armor - m.protection;
        if(Player->armor + p.protection > Monster->attack + m.attack)
           {
               printf("\nYou are really protected!");
               MonsterLines(0);
           }
        else
        {
            Player->life -= Monster->attack + m.attack - Player->armor -p.protection;
            MonsterLines(1);
        }

    }

    if(monster_choice == 2)
    {
        MonsterLines(2);
    }
    if(monster_choice == 3)
    {
        Monster->life -= Player->attack +p.attack - (Monster->armor + Monster->heal + m.heal +m.protection);
        MonsterLines(3);
    }
}

/*************************************************************************/
/* FUNCTION NAME: Case_Dodge                                             */
/* DESCRIPTION: posibilities if the player choses to dodge               */
/* ARGUMENT LIST:                                                        */
/* Argument              Type      IO   Description                      */
/* _____________________ _________ ____ _________________________________*/
/* Player                Character* I    points to the variable that     */
/*                                       stores the player stats         */
/* Monster               Character  I    points to the variable that     */
/*                                       stores the monster stats        */
/* monster_choice        int        I    the choice of the monster       */
/* p                     Buff       I    buffs for player                */
/* m                     Buff       I    buffs for monster               */
/* RETURN VALUE: void                                                    */
/* CHANGES: Player's and/or Monster HP                                   */
/*************************************************************************/

void Case_Dodge(Character *Player, Character *Monster, int monster_choice, Buff p, Buff m)
{
    if(monster_choice == 0)
    {
        printf("Nothing happened this round!\n");
    }

    if(monster_choice == 1)
    {
        //Monster->life -= Player->attack + p.attack - Monster->armor + m.protection;
        //Player->life -= Monster->attack + m.attack - Player->armor +p.protection;
        printf("You dodged the monster's attack!\n");
        MonsterLines(0);
    }

    if(monster_choice == 2)
    {
        printf("Both tried to dodge.. nothing... nice!\n");
        MonsterLines(2);
    }

    if(monster_choice == 3)
    {
        printf("Good job! You let the monster to heal in peace..");
        Monster->life += Monster->heal + m.heal;
        MonsterLines(3);
    }
}

/*************************************************************************/
/* FUNCTION NAME: Case_Attack                                            */
/* DESCRIPTION: posibilities if the player choses to heal                */
/* ARGUMENT LIST:                                                        */
/* Argument              Type      IO   Description                      */
/* _____________________ _________ ____ _________________________________*/
/* Player                Character* I    points to the variable that     */
/*                                       stores the player stats         */
/* Monster               Character  I    points to the variable that     */
/*                                       stores the monster stats        */
/* monster_choice        int        I    the choice of the monster       */
/* p                     Buff       I    buffs for player                */
/* m                     Buff       I    buffs for monster               */
/* RETURN VALUE: void                                                    */
/* CHANGES: Player's and/or Monster HP                                   */
/*************************************************************************/

void Case_Heal(Character *Player, Character *Monster, int monster_choice, Buff p, Buff m)
{
    if(monster_choice == 0)
    {
        Player->life += Player->heal + p.heal;
        MonsterLines(0);
    }

    if(monster_choice == 1)
    {
        if(Player->armor + p.protection + Player->heal + p.heal > Monster->attack + m.attack)
           {
               printf("\nYou are really protected!\n");
               Player->life += Player->heal + p.heal;
               MonsterLines(0);
           }
        else
        {
            Player->life -= Monster->attack + m.attack - Player->armor -p.protection;
            Player->life += Player->heal + p.heal;
            MonsterLines(1);
        }

    }

    if(monster_choice == 2)
    {
        Player->life += Player->heal + p.heal;
        MonsterLines(0);
    }

    if(monster_choice == 3)
    {
        printf("Selfcare time!");
        Player->life += Player->heal + p.heal;
        Monster->life +=  Monster->heal + m.heal;
        MonsterLines(3);
    }
}
