#include <stdio.h>
#include <stdlib.h>
#include "monster.h"
#include "start_end.h"
#include "char_creation.h"
#include "Custom_structures.h"
#include "Fight.h"


int main()
{
    char name_p[100]={""};
    char suggestion_start_game[] = "suggestion_start_game.txt";
    int level, choice_suggestion = 0;
    Character me, monst;
    me.life   = 5;
    me.armor  = 2;
    me.attack = 5;
    me.heal   = 2;
    monst.life   = 0;
    monst.attack = 0;
    monst.armor  = 0;
    monst.heal   = 0;

#if defined(_WIN32)
    system("cls");
#else
    system("clear");
#endif
    center_text();
    file_print(suggestion_start_game);
    scanf("%d", &choice_suggestion);

    while (choice_while != 4)
    {
        start_game();
        choose_race(&me);
        choose_name(&name_p);
        choose_item(&me);
        level = choose_diff();
        MonsterParameters(&monst, level);
        mid_game();
        int round = 1;
        while(stop_fight(&me,&monst) == 0)
        {
            Display_Stats(&me,&monst);
            The_Fight(&me,&monst,round,level);
            round++;
        }

        end_game(&me, name_p);
    }
    return 0;
}
