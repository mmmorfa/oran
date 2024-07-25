#include "sm_new.h"
#include "../../../test/rnd/fill_rnd_data_new.h"
#include <assert.h>

void init_new_sm(void)
{
  // No data allocated
}

void free_new_sm(void)
{
  // No data allocated
}

bool read_new_sm(void * data)
{
  assert(data != NULL);

  new_ind_data_t* new = (new_ind_data_t*)(data);
  fill_new_ind_data(new);
  return true;
}

void read_new_setup_sm(void* data)
{
  assert(data != NULL);
  assert(0 !=0 && "Not supported");
}

sm_ag_if_ans_t write_ctrl_new_sm(void const* src)
{
  assert(src != NULL);
  assert(0 !=0 && "Not supported");
}
