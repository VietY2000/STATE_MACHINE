#include "screen.h"
#include <string.h>
#include <stdio.h>

tsm_tbl_t tsm_screen_table;

const screen_t screen_table[] = {
    {"init",                     SCREEN_INIT},
    {"wakeup",                   SCREEN_WAKEUP},
    {"sleep",                    SCREEN_SLEEP},
    {"mode_3",                   SCREEN_MODE_3},
    {"mode_4",                   SCREEN_MODE_4},

    {"mode_5",                   SCREEN_MODE_5},
    {(char*)0, (uint8_t)0}
};

static tsm_t screen_init_tbl[] = {
    {SCREEN_INIT,       SCREEN_STATE_IDLING,        func_screen_init},

    {TSM_NULL_MSG,      TSM_NULL_STATE,             TSM_NULL_FUNC}
};

static tsm_t screen_idling_tbl[] = {
    {SCREEN_WAKEUP,     SCREEN_STATE_IDLING,        func_screen_wakeup},
    {SCREEN_SLEEP,      SCREEN_STATE_SLEEP,         func_screen_sleep},
    {SCREEN_MODE_3,     SCREEN_STATE_IDLING,        func_screen_mode_3},
    {SCREEN_MODE_4,     SCREEN_STATE_IDLING,        func_screen_mode_4},
    {SCREEN_MODE_5,     SCREEN_STATE_IDLING,        func_screen_mode_5},  

    {TSM_NULL_MSG,      TSM_NULL_STATE,             TSM_NULL_FUNC}
};

static tsm_t screen_sleep_tbl[] = {
    {SCREEN_WAKEUP,     SCREEN_STATE_IDLING,        func_screen_wakeup},

    {TSM_NULL_MSG,      TSM_NULL_STATE,             TSM_NULL_FUNC}
};

tsm_t *tsm_screen_tbl[] = {
    (tsm_t*)0,
    screen_init_tbl,
    screen_idling_tbl,
    screen_sleep_tbl
};

void screen_parser(char *cmd){
    int index = 0;

    uint8_t sig;
    while(screen_table[index].cmd){
        if(strcmp(screen_table[index].cmd, cmd) == 0){

            sig = screen_table[index].sig;
        }
        index++;
    }

    tsm_dispatch(&tsm_screen_table,sig);
}

void func_screen_init(){
    printf("SCREEN INIT\n");
    for(int p = 0; p < 100000000; ++p){}
    tsm_dispatch(&tsm_screen_table,SCREEN_WAKEUP);
}

void func_screen_wakeup(){
    printf("SCREEN WAKEUP\n");
}

void func_screen_sleep(){
    printf("SCREEN GO TO SLEEP\n");
}

void func_screen_mode_3(){
    printf("SCREEN MODE 3\n");
}

void func_screen_mode_4(){
    printf("SCREEN MODE 4\n");
}

void func_screen_mode_5(){
    printf("SCREEN MODE 5\n");
}