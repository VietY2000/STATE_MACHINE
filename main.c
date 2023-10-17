#include "tsm.h"
#include <stdio.h>
#include <stdlib.h>

extern tsm_t *tsm_tbl[];
int main(){
    msg_t *msg = (msg_t*) malloc(sizeof(msg_t));
    msg->sig = 1;
    tsm_func(tsm_tbl, msg);
    return 0;
}