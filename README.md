    /*********************************************************************************/
    /* TABLE STATE MACHINE */


    /*******************            init_t             *******************/
        sig                 next_state                  fun_parser
        1                   IDLING                      init_func
        TSM_NULL_MSG        INIT                        TSM_NULL_FUNC
    /*********************************************************************/

    /*******************            idling_t           *******************/
        1                   IDLING                      wakeup_func

        2                   SLEEP                       sleep_func
        3                   IDLING                      mode3_func
        4                   IDLING                      mode4_func
        5                   IDLING                      mode5_func
        TSM_NULL_MSG        IDLING                      TSM_NULL_FUNC
    /*********************************************************************/

    /*******************            sleep_t            *******************/
        1                   IDLING                      wakeup_func

        TSM_NULL_MSG        SLEEP                       TSM_NULL_FUNC
    /*********************************************************************/