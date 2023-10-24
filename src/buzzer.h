#ifndef __BUZZER_H__
#define __BUZZER_H__
#include <stdint.h>

#include <stdio.h>

#include "tsm.h"

/* define state */
#define BUZZER_STATE_UNCONNECT  (1)
#define BUZZER_STATE_CONNECT    (2)


/* define signal */
enum {
    BUZZER_CONNECT = 1,
    BUZZER_UNCONNECT,
    BUZZER_TONE_3,
    BUZZER_TONE_4,
    BUZZER_TONE_5
};


typedef struct {
    char *cmd;
    uint8_t sig;
} buzzer_t;

void buzzer_parser(char *cmd);
void func_buzzer_connect();
void func_buzzer_unconnect();
void func_buzzer_tone_3();
void func_buzzer_tone_4();
void func_buzzer_tone_5();

#endif /* __BUZZER_H__ */