#include "tsm.h"
#include <stdio.h>
void tsm_init(tsm_tbl_t *tsm_tbl, tsm_t **tbl, tsm_state_t state){

    if(tsm_tbl == TSM_NULL_TABLE){
        printf("NULL TABLE\n");
        return;
    }
    /* assign state table */
    tsm_tbl->table = tbl;
    /* init state */
    tsm_tran(tsm_tbl, state);

}

void tsm_dispatch(tsm_tbl_t *tsm_tbl, uint8_t sig){
    tsm_t *expect_table = tsm_tbl->table[tsm_tbl->state];

    /* find the signal */
    while(expect_table->sig != TSM_NULL_MSG && expect_table->sig != sig){
        expect_table++;
    }

    // 
    /* update state table */
    if(expect_table->next_state != TSM_NULL_STATE && expect_table->next_state != tsm_tbl->state){
        tsm_tran(tsm_tbl,expect_table->next_state);
    }

    /* handle the sig with expect table */
    if(expect_table->func != TSM_NULL_FUNC){
        expect_table->func();
    }
}

void tsm_tran(tsm_tbl_t *tsm_tbl, tsm_state_t state){
    tsm_tbl->state = state;
}