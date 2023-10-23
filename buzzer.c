#include "buzzer.h"
#include <string.h>
#include <stdio.h>

tsm_tbl_t tsm_buzzer_table;

const buzzer_t buzzer_table[] = {
    {"connect",                 BUZZER_CONNECT},
    {"unconnect",               BUZZER_UNCONNECT},
    {"tone_3",                  BUZZER_TONE_3},
    {"tone_4",                  BUZZER_TONE_4},
    {"tone_5",                  BUZZER_TONE_5},

    {(char*)0, (uint8_t)0}
};

static tsm_t buzzer_unconnect_tbl[] = {
    {BUZZER_CONNECT,        BUZZER_STATE_CONNECT,       func_buzzer_connect},

    {TSM_NULL_MSG,          TSM_NULL_STATE,             TSM_NULL_FUNC}
};
static tsm_t buzzer_connect_tbl[] = {

    {BUZZER_UNCONNECT,      BUZZER_STATE_UNCONNECT,     func_buzzer_unconnect},
    {BUZZER_TONE_3,         BUZZER_STATE_CONNECT,       func_buzzer_tone_3},
    {BUZZER_TONE_4,         BUZZER_STATE_CONNECT,       func_buzzer_tone_4},
    {BUZZER_TONE_5,         BUZZER_STATE_CONNECT,       func_buzzer_tone_5},

    {TSM_NULL_MSG,          TSM_NULL_STATE,             TSM_NULL_FUNC}
};

tsm_t *tsm_buzzer_tbl[] = {
    (tsm_t*)0,
    buzzer_unconnect_tbl,
    buzzer_connect_tbl
};

void buzzer_parser(char *cmd){
    int index = 0;

    uint8_t sig;
    while(buzzer_table[index].cmd){
        if(strcmp(buzzer_table[index].cmd, cmd) == 0){

            sig = buzzer_table[index].sig;
        }
        index++;
    }

    tsm_dispatch(&tsm_buzzer_table,sig);
}


void func_buzzer_connect(){
    printf("BUZZER CONNECT\n");
}

void func_buzzer_unconnect(){
    printf("BUZZER UNCONNECT\n");
}

void func_buzzer_tone_3(){
    printf("BUZZER PLAY TONE 3\n");
}

void func_buzzer_tone_4(){
    printf("BUZZER PLAY TONE 4\n");
}

void func_buzzer_tone_5(){
    printf("BUZZER PLAY TONE 5\n");
}