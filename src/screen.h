#ifndef __SCREEN_H__
#define __SCREEN_H__
#include <stdint.h>

#include <stdio.h>

#include "tsm.h"

/* define state */
#define SCREEN_STATE_INIT    (1)
#define SCREEN_STATE_IDLING  (2)
#define SCREEN_STATE_SLEEP   (3)

/* define signal */
enum {
    SCREEN_INIT = 1,
    SCREEN_WAKEUP,
    SCREEN_SLEEP,
    SCREEN_MODE_3,
    SCREEN_MODE_4,
    SCREEN_MODE_5
};

typedef struct {
    char *cmd;
    uint8_t sig;
} screen_t;

void screen_parser(char *cmd);
void func_screen_init();
void func_screen_wakeup();
void func_screen_sleep();
void func_screen_mode_3();
void func_screen_mode_4();
void func_screen_mode_5();

#endif /* __SCREEN_H__ */