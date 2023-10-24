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
    tsm_init(&tsm_screen_table, tsm_screen_tbl, SCREEN_STATE_INIT);

    /* khởi tạo table buzzer */
    tsm_init(&tsm_buzzer_table, tsm_buzzer_tbl, BUZZER_STATE_UNCONNECT);
    
    while(1) {
        printf(path);

        char cmd[100];
        fgets(cmd,sizeof(cmd),stdin);
        if(strcmp(cmd,"0xFF\n") == 0 || strcmp(cmd,"0xff\n") == 0){
            break;
        }
        cmd_line_parser(cmd_table, cmd);
    }
    return 0;
}