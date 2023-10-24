#include <stdio.h>
#include "shell.h"
#include <string.h>

#include <stdlib.h>
extern const cmd_line_t cmd_table[];
extern tsm_tbl_t tsm_screen_table;
extern tsm_t *tsm_screen_tbl[];
extern tsm_tbl_t tsm_buzzer_table;
extern tsm_t *tsm_buzzer_tbl[];


int main(){
    system("cls");

    printf("\n");
    /* khởi tạo table screen */
    tsm_init(&tsm_screen_table, tsm_screen_tbl, SCREEN_STATE_INIT);

    /* khởi tạo table buzzer */
    tsm_init(&tsm_buzzer_table, tsm_buzzer_tbl, BUZZER_STATE_UNCONNECT);
    

    char cmd[100] = "buzzer tone_5\n";
    printf("test cmd: buzzer tone_5\n");
    cmd_line_parser(cmd_table, cmd);
    printf("**********************************************************************\n");

    strcpy(cmd,"buzzer connect\n");
    printf("test cmd: buzzer connect\n");
    cmd_line_parser(cmd_table, cmd);
    printf("**********************************************************************\n");

    strcpy(cmd,"buzzer tone_3\n");
    printf("test cmd: buzzer tone_3\n");
    cmd_line_parser(cmd_table, cmd);
    printf("**********************************************************************\n");

    strcpy(cmd,"buzzer unconnect\n");
    printf("test cmd: buzzer unconnect\n");
    cmd_line_parser(cmd_table, cmd);
    printf("**********************************************************************\n");

    strcpy(cmd,"buzzer tone_5\n");
    printf("test cmd: buzzer tone_5\n");
    cmd_line_parser(cmd_table, cmd);
    printf("**********************************************************************\n");
    return 0;

}