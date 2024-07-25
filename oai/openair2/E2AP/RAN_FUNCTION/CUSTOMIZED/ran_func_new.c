#include "ran_func_new.h"
#include <assert.h>

static
const int mod_id = 0;


bool read_new_sm(void* data)
{
  assert(data != NULL);

  new_ind_data_t* new = (new_ind_data_t*)data;
  //fill_mac_ind_data(mac);

  new->msg.tstamp = time_now_us();

  NR_UEs_t *UE_info = &RC.nrmac[mod_id]->UE_info;
  size_t num_ues = 0;
  UE_iterator(UE_info->list, ue) {
    if (ue)
      num_ues += 1;
  }

  new->msg.len = num_ues;
  if(new->msg.len > 0){
    new->msg.rb = calloc(new->msg.len, sizeof(new_radio_bearer_stats_t));
    assert(new->msg.rb != NULL && "Memory exhausted" );
  }

  size_t i = 0; //TODO
  UE_iterator(UE_info->list, UE) {
    const NR_UE_sched_ctrl_t* sched_ctrl = &UE->UE_sched_ctrl;
    new_radio_bearer_stats_t* rd = &new->msg.rb[i];

    rd->data1 = RC.nrmac[mod_id]->frame;
    rd->data2 = RC.nrmac[mod_id]->slot;

    rd->data3 = UE->mac_stats.dl.total_bytes;
 
    rd->data4 = UE->rnti;

    ++i;
  }

  return num_ues > 0;
}

void read_new_setup_sm(void* data)
{
  assert(data != NULL);
  assert(0 !=0 && "Not supported");
}

sm_ag_if_ans_t write_ctrl_new_sm(void const* data)
{
  assert(data != NULL);
  assert(0 !=0 && "Not supported");
}
