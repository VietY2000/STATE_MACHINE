#ifndef __TSM_H__
#define __TSM_H__
#include <stdint.h>

#define TSM_NULL_MSG ((uint8_t)0)
#define TSM_NULL_FUNC ((tsm_func_f)0)
#define TSM_NULL_TABLE ((tsm_tbl_t*)0)
#define TSM_NULL_STATE ((tsm_state_t)0)
typedef uint8_t tsm_state_t;
typedef void (*tsm_func_f)();

typedef struct {

    uint8_t sig;
    tsm_state_t next_state;
    tsm_func_f func;
} tsm_t;

typedef struct {
    tsm_state_t state;
    tsm_t **table;
} tsm_tbl_t;

void tsm_init(tsm_tbl_t *tsm_tbl, tsm_t **tbl, tsm_state_t state);
void tsm_dispatch(tsm_tbl_t *tsm_tbl, uint8_t sig);
void tsm_tran(tsm_tbl_t *tsm_tbl, tsm_state_t state);

#endif /* __TSM_H__ */