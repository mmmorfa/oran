#ifndef SM_NEW_READ_WRITE_AGENT_H
#define SM_NEW_READ_WRITE_AGENT_H

#include "../../../src/agent/e2_agent_api.h"

void init_new_sm(void);

void free_new_sm(void);

bool read_new_sm(void*);

void read_new_setup_sm(void*);

sm_ag_if_ans_t write_ctrl_new_sm(void const*);

#endif
