#include <stdio.h>
#include "shell.h"
#include <string.h>

#include <stdlib.h>
#define path "E:\\Company\\job:"
extern const cmd_line_t cmd_table[];
extern tsm_tbl_t tsm_screen_table;
extern tsm_t *tsm_screen_tbl[];
extern tsm_tbl_t tsm_buzzer_table;
extern tsm_t *tsm_buzzer_tbl[];


int main(){
    system("cls");

    printf("\n");
    /* khởi tạo table screen */
    tsm_init(&tsm_screen_table, tsm_screen_tbl, SCREEN_ST0ATE_INIT);

    /* khởi tạo table buzzer */
    tsm_init(&tsm_buzzer_table, tsm_buzzer_tbl, BUZZER_STATE_UNCONNECT);
    
    char cmd[100] = "screen mode_5\n";
    printf("test\"")
    cmd_line_parser(cmd_table, cmd);

    return 0;
}