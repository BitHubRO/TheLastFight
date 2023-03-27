#include <stdio.h>
#include <stdlib.h>

#include "char_creation.h"
#include "start_end.h"
#include "Custom_structures.h"

extern int choice_while = 0;


/*************************************************************************/
/* FUNCTION NAME: start_game                                             */
/* DESCRIPTION: prints the menu and story at the start of the game       */
/* ARGUMENT LIST:                                                        */
/* Argument              Type     IO   Description                       */
/* _____________________ ________ ____ __________________________________*/
/* -                    -        -    -                                  */
/* RETURN VALUE: void                                                    */
/* CHANGES: -                                                            */
/*************************************************************************/



void start_game()
{

    char screen1_start_game[]    = "screen1_start_game.txt";
    char screen2_start_game[]    = "screen2_start_game.txt";
    char how_start_game[]        = "how_start_game.txt";
    char menu_start_game[]       = "menu_start_game.txt";
    char more_start_game[]       = "more_start_game.txt";
    char ready_start_game[]      = "ready_start_game.txt";
    char quit_start_game[]       = "quit_start_game.txt";
    char ASCII_dungeon[]         = "ASCII_dungeon.txt";
    int choice_intern = 0, choice_start = 0;


    while (choice_start != 1)
    {
            system("cls");
            center_text();
            file_print(menu_start_game);
            scanf("%d", &choice_while);

        switch (choice_while)
        {
            case 1:
                system("cls");
                center_text();
                file_print(ready_start_game);
                scanf("%d", &choice_start);

                if (choice_start == 1)
                {
                    system("cls");
                    printf("\n\n\n");
                    file_print(screen1_start_game);
                    file_print(ASCII_dungeon);
                    scanf("%d", &choice_intern);

                    system("cls");
                    center_text();
                    file_print(screen2_start_game);
                    scanf("%d", &choice_intern);

                    break;
                }
            default:
                system("cls");
                center_text();
                file_print(quit_start_game);

                exit(0);

                break;
            case 2:
                system("cls");
                center_text();
                file_print(how_start_game);
                scanf("%d", &choice_intern);
            break;
            case 3:
                system("cls");
                center_text();
                file_print(more_start_game);
                scanf("%d", &choice_intern);

                break;

        }
    }

}

/*************************************************************************/
/* FUNCTION NAME: mid_game                                               */
/* DESCRIPTION: prints the story at the middle of the game               */
/* ARGUMENT LIST:                                                        */
/* Argument              Type     IO   Description                       */
/* _____________________ ________ ____ __________________________________*/
/* -                    -        -    -                                  */
/* RETURN VALUE: void                                                    */
/* CHANGES: -                                                            */
/*************************************************************************/



void mid_game()
{
    char screen1_mid_game[] = "screen1_mid_game.txt";
    char screen2_mid_game[] = "screen2_mid_game.txt";
    char screen3_mid_game[] = "screen3_mid_game.txt";
    char option1_mid_game[] = "option1_mid_game.txt";
    char option2_mid_game[] = "option2_mid_game.txt";
    char option3_mid_game[] = "option3_mid_game.txt";
    char screen4_mid_game[] = "screen4_mid_game.txt";
    char screen5_mid_game[] = "screen5_mid_game.txt";
    char ASCII_gryphon[]    = "ASCII_gryphon.txt";
    char ASCII_minotaur[]   = "ASCII_minotaur.txt";
    int choice_intern = 0, choice_switch = 0;

    system("cls");
    center_text();
    file_print(screen1_mid_game);
    scanf("%d", &choice_intern);

    system("cls");
    center_text();
    file_print(screen2_mid_game);
    file_print(ASCII_gryphon);
    scanf("%d", &choice_intern);

    system("cls");
    center_text();
    file_print(screen3_mid_game);
    scanf("%d", &choice_intern);

    switch (choice_intern)
    {
        case 1:
                system("cls");
                center_text();
                file_print(option1_mid_game);
                scanf("%d", &choice_switch);

                break;
        case 2:
                system("cls");
                center_text();
                file_print(option2_mid_game);
                scanf("%d", &choice_switch);

                break;
        case 3:
                system("cls");
                center_text();
                file_print(option3_mid_game);
                scanf("%d", &choice_switch);

                break;
    }
    system("cls");
    center_text();
    file_print(screen4_mid_game);
    scanf("%d", &choice_intern);

    system("cls");
    center_text();
    file_print(screen5_mid_game);
    file_print(ASCII_minotaur);
    scanf("%d", &choice_intern);

}

/*************************************************************************/
/* FUNCTION NAME: end_game                                               */
/* DESCRIPTION: prints endscreens at the end of the game                 */
/* ARGUMENT LIST:                                                        */
/* Argument              Type     IO   Description                       */
/* _____________________ ________ ____ __________________________________*/
/* Player               Character* I    points to the variable that      */
/*                                      stores the player stats          */
/* name_p               char *     I    points to the variable that      */
/*                                      stores the name                  */
/* RETURN VALUE: void                                                    */
/* CHANGES: -                                                            */
/*************************************************************************/


void end_game(Character *Player, char *name_p)
{
    char win_end_game[]   = "win_end_game.txt";
    char lose_end_game[]  = "lose_end_game.txt";
    char ASCII_gameover[] = "ASCII_gameover.txt";
    int choice_intern = 0;

    Player->attack = 5;
    Player->heal  = 2;
    Player->armor = 2;

    if (Player->life > 0)
    {
        system("cls");
        center_text();
        file_print(ASCII_gameover);
        file_print(win_end_game);
        printf("\n\n\t\t\t\t\t\t\t You did a great job, %s!\n", name_p);
        scanf("%d", &choice_intern);
    }
    else
    {
        system("cls");
        center_text();
        file_print(ASCII_gameover);
        file_print(lose_end_game);
        printf("\n\n\t\t\t\t\t\t\t You did a great job, %s!\n", name_p);
        scanf("%d", &choice_intern);

    }
}
