#include <stdio.h>
#include <stdlib.h>
// windows only import of conio.h
#if defined(_WIN32)
#include <conio.h>
#endif

#include "char_creation.h"
#include "Custom_structures.h"



/*************************************************************************/
/* FUNCTION NAME: file_print                                             */
/* DESCRIPTION: prints the contents of a chosen file                     */
/* ARGUMENT LIST:                                                        */
/* Argument             Type       IO   Description                      */
/* ____________________ __________ ____ ________________________________ */
/* filename             char *     I    points to the variable that      */
/*                                      accesses the text file           */
/* RETURN VALUE: void                                                    */
/* CHANGES: -                                                            */
/*************************************************************************/


void file_print(const char *filename) {
    FILE *fptr;
    char c;

    fptr = fopen(filename, "r");

    c = fgetc(fptr);
    while (c != EOF) {
        printf("%c", c);
        c = fgetc(fptr);
    }

    fclose(fptr);
}

/*************************************************************************/
/* FUNCTION NAME: choose_race                                            */
/* DESCRIPTION: allows player to choose a race for character             */
/* ARGUMENT LIST:                                                        */
/* Argument             Type       IO   Description                      */
/* ____________________ __________ ____ _________________________________*/
/* Player               Character* I    points to the variable that      */
/*                                       stores the player stats         */
/* RETURN VALUE: void                                                    */
/* CHANGES: changes attack, heal or protection                           */
/*************************************************************************/

void choose_race(Character *Player) {
    char intro_choose_race[] = "intro_choose_race.txt";
    char witch_choose_race[] = "witch_choose_race.txt";
    char ASCII_witch[] = "ASCII_witch.txt";
    char goblin_choose_race[] = "goblin_choose_race.txt";
    char ASCII_goblin[] = "ASCII_goblin.txt";
    char skeleton_choose_race[] = "skeleton_choose_race.txt";
    char ASCII_skeleton[] = "ASCII_skeleton.txt";
    int choice_read = 0, choice_race = 0;

#if defined(_WIN32)
    system("cls");
#else
    system("clear");
#endif
    center_text();
    file_print(intro_choose_race);
    scanf("%d", &choice_read);

    while (choice_race != 1) {
        switch (choice_read) {
            case 1:
#if defined(_WIN32)
                system("cls");
#else
                system("clear");
#endif
                center_text();
                file_print(witch_choose_race);
                file_print(ASCII_witch);
                printf("\n");
                scanf("%d", &choice_race);

                if (choice_race == 1) {
                    Player->heal += 2;
                    Player->life = 20;
                } else {
                    choice_read = 0;
                    choice_race = 0;
                }
                break;
            case 2:
#if defined(_WIN32)
                system("cls");
#else
                system("clear");
#endif
                center_text();
                file_print(goblin_choose_race);
                file_print(ASCII_goblin);
                printf("\n");
                scanf("%d", &choice_race);

                if (choice_race == 1) {
                    Player->attack += 2;
                    Player->life = 20;
                } else {
                    choice_read = 0;
                    choice_race = 0;
                }
                break;
            case 3:
#if defined(_WIN32)
                system("cls");
#else
                system("clear");
#endif
                center_text();
                file_print(skeleton_choose_race);
                file_print(ASCII_skeleton);
                printf("\n");
                scanf("%d", &choice_race);

                if (choice_race == 1) {
                    Player->armor += 2;
                    Player->life = 18;
                } else {
                    choice_read = 0;
                    choice_race = 0;
                }
                break;
        }
        if (choice_race != 1) {
#if defined(_WIN32)
            system("cls");
#else
            system("clear");
#endif
            center_text();
            file_print(intro_choose_race);
            scanf("%d", &choice_read);
        }
    }
}

/*************************************************************************/
/* FUNCTION NAME: choose_name                                            */
/* DESCRIPTION: allows player to choose a name for character             */
/* ARGUMENT LIST:                                                        */
/* Argument             Type     IO   Description                        */
/* ____________________ ________ ____ ___________________________________*/
/* name_p               char *   I    points to the variable that        */
/*                                    stores the name                    */
/* RETURN VALUE: void                                                    */
/* CHANGES: changes the name in the array of char name_p                 */
/*************************************************************************/


void choose_name(char *name_p) {
    char intro_choose_name[] = "intro_choose_name.txt";
    int choice_thanks = 0;


#if defined(_WIN32)
    system("cls");
#else
    system("clear");
#endif
    center_text();
    file_print(intro_choose_name);
    scanf("%s", name_p);


#if defined(_WIN32)
    system("cls");
#else
    system("clear");
#endif
    center_text();
    printf("\t\t\t\t\t\tWhat a nice name you have, %s!!", name_p);
    printf("\n\t\t\t\t\t\t\t\t 1. Thanks!\n");
    scanf("%d", &choice_thanks);

#if defined(_WIN32)
    system("cls");
#else
    system("clear");
#endif
}

/*************************************************************************/
/* FUNCTION NAME: center_text                                            */
/* DESCRIPTION: shifts text lower on the console                         */
/* ARGUMENT LIST:                                                        */
/* Argument             Type     IO   Description                        */
/* ____________________ ________ ____ ___________________________________*/
/* -                    -        -    -                                  */
/* RETURN VALUE: void                                                    */
/* CHANGES: jumps a specific number of lines                             */
/*************************************************************************/


void center_text() {
    int n = 10;
    int i = 0;
    for (i = 0; i <= n; i++) {
        printf("\n");
    }
}

/*************************************************************************/
/* FUNCTION NAME: choose_item                                            */
/* DESCRIPTION: allows player to choose an item for character            */
/* ARGUMENT LIST:                                                        */
/* Argument             Type     IO   Description                        */
/* ____________________ ________ ____ ___________________________________*/
/* Player               Character* I    points to the variable that      */
/*                                      stores the player stats          */
/* RETURN VALUE: void                                                    */
/* CHANGES: changes attack, heal or protection                           */
/*************************************************************************/


void choose_item(Character *Player) {
    char intro_choose_item[] = "intro_choose_item.txt";
    char sword_choose_item[] = "sword_choose_item.txt";
    char ASCII_sword[] = "ASCII_sword.txt";
    char shield_choose_item[] = "shield_choose_item.txt";
    char ASCII_shield[] = "ASCII_shield.txt";
    char ring_choose_item[] = "ring_choose_item.txt";
    char ASCII_ring[] = "ASCII_ring.txt";
    int choice_read = 0, choice_item = 0;

    center_text();
    file_print(intro_choose_item);
    scanf("%d", &choice_read);

    while (choice_item != 1) {
        switch (choice_read) {
            case 1:

#if defined(_WIN32)
                system("cls");
#else
                system("clear");
#endif
                center_text();
                file_print(sword_choose_item);
                file_print(ASCII_sword);
                printf("\n");
                scanf("%d", &choice_item);

                if (choice_item == 1) {
                    Player->attack += 1;
                } else {
                    choice_read = 0;
                    choice_item = 0;
                }
                break;
            case 2:
#if defined(_WIN32)
                system("cls");
#else
                system("clear");
#endif
                center_text();
                file_print(ring_choose_item);
                file_print(ASCII_ring);
                printf("\n");
                scanf("%d", &choice_item);

                if (choice_item == 1) {
                    Player->heal += 1;
                } else {
                    choice_read = 0;
                    choice_item = 0;
                }
                break;
            case 3:
#if defined(_WIN32)
                system("cls");
#else
                system("clear");
#endif
                center_text();
                file_print(shield_choose_item);
                file_print(ASCII_shield);
                printf("\n");
                scanf("%d", &choice_item);

                if (choice_item == 1) {
                    Player->armor += 2;
                    //hp_p = 18;
                } else {
                    choice_read = 0;
                    choice_item = 0;
                }
                break;
        }
        if (choice_item != 1) {
#if defined(_WIN32)
            system("cls");
#else
            system("clear");
#endif
            center_text();
            file_print(intro_choose_item);
            scanf("%d", &choice_read);
        }
    }
}

/*************************************************************************/
/* FUNCTION NAME: choose_diff                                            */
/* DESCRIPTION: allows player to choose a difficiulty for game           */
/* ARGUMENT LIST:                                                        */
/* Argument             Type     IO   Description                        */
/* ____________________ ________ ____ ___________________________________*/
/* -                    -        -    -                                  */
/* RETURN VALUE: void                                                    */
/* CHANGES: -                                                            */
/*************************************************************************/


int choose_diff() {
    int level;
    char intro_choose_diff[] = "intro_choose_diff.txt";
    char outro_choose_diff[] = "outro_choose_diff.txt";
    int start_game = 0;

#if defined(_WIN32)
    system("cls");
#else
    system("clear");
#endif
    center_text();
    file_print(intro_choose_diff);

    scanf("%d", &level);

#if defined(_WIN32)
    system("cls");
#else
    system("clear");
#endif
    center_text();
    file_print(outro_choose_diff);

    scanf("%d", &start_game);
#if defined(_WIN32)
    system("cls");
#else
    system("clear");
#endif

    return level;
}
