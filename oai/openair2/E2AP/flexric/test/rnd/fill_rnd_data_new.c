#include "fill_rnd_data_new.h"
#include "../../src/util/time_now_us.h"

#include <assert.h>
#include <stdlib.h>
#include <time.h>
void fill_new_ind_data(new_ind_data_t* ind){
  assert(ind != NULL);

  srand(time(0));

  int const mod = 1024;

  // Get indication message
  new_ind_msg_t* ind_msg = &ind->msg;
  
  // Set time now  
  ind_msg->tstamp = time_now_us();

  // Set random number of messages  
  ind_msg->len = rand()%4;
  if(ind_msg->len > 0 ){  
    ind_msg->rb = calloc(ind_msg->len, sizeof(new_radio_bearer_stats_t) );
    assert(ind_msg->rb != NULL);
  }
    
  for(uint32_t i = 0; i < ind_msg->len; ++i){
    new_radio_bearer_stats_t* rb = &ind_msg->rb[i];
      
    // Fill dummy data in your data structure  
    rb->data1=abs(rand()%mod);
    rb->data2=abs(rand()%mod); 
  }
}