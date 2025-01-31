#ifndef SM_NEW_READ_WRITE_AGENT_H
#define SM_NEW_READ_WRITE_AGENT_H

#include "openair2/E2AP/flexric/src/agent/../sm/sm_io.h"
#include "common/ran_context.h"
#include "openair2/LAYER2/NR_MAC_gNB/mac_proto.h"
#include "openair2/E2AP/flexric/src/util/time_now_us.h"


bool read_new_sm(void*);

void read_new_setup_sm(void*);

sm_ag_if_ans_t write_ctrl_new_sm(void const*);

#endif
