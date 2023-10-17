#ifndef __TSM_H__
#define __TSM_H__
#include <stdint.h>

#define TSM_NULL_MSG ((uint8_t)0)
#define TSM_NULL_FUNC ((tsm_func_f)0)

typedef enum {
    INIT = 0,
    IDLING = 1,
    SLEEP = 2
} state;

typedef struct {
    uint8_t sig;
} msg_t;

typedef void (*tsm_func_f)();

typedef struct {
    uint8_t sig;
    state next_state;

    tsm_func_f func;
} tsm_t;

void tsm_func(tsm_t *tsm_table[], msg_t *msg);
static void init_func();
static void wakeup_func();
static void mode3_func();
static void mode4_func();
static void mode5_func();
static void sleep_func();

#endif /* __TSM_H__ */