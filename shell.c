#include "shell.h"
#include <string.h>
#include <stdlib.h>

const cmd_line_t cmd_table[] = {
    {"screen",      screen_parser},
    {"buzzer",      buzzer_parser},
    {"clear",       clear_parser},
    {(char*)0,      (func_cmd_parser)0}
};

void cmd_line_parser(const cmd_line_t *cmd_table, char* cmd){
    char p_cmd[2][12];

    int index_cmd = 0;
    int p = 0;
    int pos; 
    int symbol = 1;
    while(*(cmd + p)){
        if((*(cmd + p) == ' ' || *(cmd + p) == '\n')){
            if(symbol == 0){
                *(p_cmd[index_cmd] + ( p - pos)) = '\0';
                index_cmd++;
                symbol = 1;
            }
        }
        else{
            if(symbol == 1){
                pos = p;
            }
            if(index_cmd >= 2){
                return ;
            }
            p_cmd[index_cmd][p - pos] = *(cmd + p);
            symbol = 0;
        }
        p++;
    }

    if(index_cmd == 0){
        return ;
    }

    int table_index = 0;
    while(cmd_table[table_index].cmd){
        if(strcmp(cmd_table[table_index].cmd, p_cmd[0]) == 0){
            cmd_table[table_index].func(p_cmd[1]);
        }
        table_index++;

    }
    return;
}

void clear_parser(char* cmd){
    (void*)cmd;
    system("cls");
}