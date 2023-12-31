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
    

    char cmd[100] = "screen mode_5\n";
    printf("test cmd: screen mode_5\n");
    cmd_line_parser(cmd_table, cmd);
    printf("**********************************************************************\n");

    strcpy(cmd,"screen init\n");
    printf("test cmd: screen init\n");
    cmd_line_parser(cmd_table, cmd);
    printf("**********************************************************************\n");

    strcpy(cmd,"screen mode_5\n");
    printf("test cmd: screen mode_5\n");
    cmd_line_parser(cmd_table, cmd);
    printf("**********************************************************************\n");

    strcpy(cmd,"screen sleep\n");
    printf("test cmd: screen sleep\n");
    cmd_line_parser(cmd_table, cmd);
    printf("**********************************************************************\n");

    strcpy(cmd,"screen mode_3\n");
    printf("test cmd: screen mode_3\n");
    cmd_line_parser(cmd_table, cmd);
    printf("**********************************************************************\n");


    strcpy(cmd,"screen wakeup\n");
    printf("test cmd: screen wakeup\n");
    cmd_line_parser(cmd_table, cmd);

    printf("**********************************************************************\n");

    strcpy(cmd,"screen mode_5\n");
    printf("test cmd: screen mode_5\n");
    cmd_line_parser(cmd_table, cmd);
    printf("**********************************************************************\n");
    return 0;
}