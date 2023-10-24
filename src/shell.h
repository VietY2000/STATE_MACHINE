#ifndef __SHELL_H__
#define __SHELL_H__
#include "screen.h"

#include "buzzer.h"

#define MAX_CMD_SIZE                    12

typedef void (*func_cmd_parser)(char* cmd);

typedef struct {
    char *cmd;
    
    func_cmd_parser func;
} cmd_line_t;

void cmd_line_parser(const cmd_line_t *cmd_table, char* cmd);
void clear_parser(char* cmd);
#endif /* __SHELL_H__ */