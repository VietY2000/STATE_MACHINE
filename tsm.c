#include "tsm.h"
#include <stdio.h>
static tsm_t init_t[] = {

    /* sig                          next_state              func_parser*/
    {1,                             IDLING,                 init_func},
    {TSM_NULL_MSG,                  INIT,                 TSM_NULL_FUNC}
};

static tsm_t idling_t[] = {
    {1,                             IDLING,                 wakeup_func},
    {2,                             SLEEP,                  sleep_func},

    {3,                             IDLING,                 mode3_func},
    {4,                             IDLING,                 mode4_func},
    {5,                             IDLING,                 mode5_func},
    {TSM_NULL_MSG,                  IDLING,                 TSM_NULL_FUNC}
};

static tsm_t sleep_t[] = {
    {1,                             IDLING,                 wakeup_func},
    {TSM_NULL_MSG,                  SLEEP,                 TSM_NULL_FUNC}

};

tsm_t *tsm_tbl[] = {
    init_t,
    idling_t,
    sleep_t
};

void tsm_func(tsm_t *tsm_table[], msg_t *msg){
    /* vào trạng thái init */
    tsm_t *respective_table = *(tsm_table + INIT);
    uint8_t index = 0;
    state next_state;
    /* thực hiện hàm init */
    respective_table[index].func();
    next_state = respective_table[index].next_state;

    /* đổi trạng thái sang idling*/
    respective_table = *(tsm_table + next_state);
    /* thực hiện hàm wakeup của idling */
    respective_table[index].func();
    next_state = respective_table[index].next_state;
    respective_table = *(tsm_table + next_state);

    uint8_t flag = 0;

    while(1){
        index = 0;
        scanf("%d", &msg->sig);

        while(respective_table[index].sig){
            if(respective_table[index].sig == msg->sig){
                respective_table[index].func();
                flag = 1;
                break;
            }
            index++;
            flag = 0;
        }
        if(flag){
            next_state = respective_table[index].next_state;
            respective_table = *(tsm_table + next_state);
        }
    }
}

static void init_func(){
    printf("FPT Telecom Intership! \n");
    for(int p = 0; p < 1000000000; ++p){}
}

static void wakeup_func(){
    printf("Wake up!\n");
}

static void mode3_func(){
    printf("Mode 3!\n");
}

static void mode4_func(){
    printf("Mode 4!\n");
}

static void mode5_func(){
    printf("Mode 5!\n");
}

static void sleep_func(){
    printf("Go to sleep mode!\n");
}