#include "../../../../src/xApp/e42_xapp_api.h"
#include "../../../../src/util/alg_ds/alg/defer.h"
#include "../../../../src/util/time_now_us.h"

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

//  Call back function 
// Implement what you're going to read from your service model
static
void sm_cb_new(sm_ag_if_rd_t const* rd)
{
  assert(rd != NULL);
  assert(rd->type ==INDICATION_MSG_AGENT_IF_ANS_V0);
  assert(rd->ind.type == NEW_STATS_V0);
  printf("Antes de time now us");

  int64_t now = time_now_us();
  printf("Current time: %ld\n", now);
  printf("Timestamp: %ld\n", rd->ind.new_ind.msg.tstamp);
  printf("NEW ind_msg latency = %ld \n", now - rd->ind.new_ind.msg.tstamp);
}

int main(int argc, char *argv[])
{
  // init the config of xApp
  fr_args_t args = init_fr_args(argc, argv);

  // init xApp
  init_xapp_api(&args);
  sleep(1);

  // Get the state of connection E2 nodes
  e2_node_arr_xapp_t nodes = e2_nodes_xapp_api();
  defer({ free_e2_node_arr_xapp(&nodes); });

  assert(nodes.len > 0);

  printf("Connected E2 nodes = %d\n", nodes.len);

  // new indication
  // Set the interval time of indication message

  sm_ans_xapp_t* new_handle = NULL;
  const char* i_3 = "1_ms";
  // if there is more than one E2 node connected to the RIC
  if(nodes.len > 0){
    // Create an array of with length of nodes
    printf("Estic dins if de nodes");
    new_handle = calloc( nodes.len, sizeof(sm_ans_xapp_t));
    assert(new_handle != NULL);
  }

  for (int i = 0; i < nodes.len; i++) {
    e2_node_connected_xapp_t* n = &nodes.n[i];
    for (size_t j = 0; j < n->len_rf; j++)
      printf("Registered node %d ran func id = %d \n ", i, n->rf[j].id);
    // generate subscription request
    new_handle[i] = report_sm_xapp_api(&nodes.n[i].id, 149, (void*)i_3, sm_cb_new);
    assert(new_handle[i].success == true);
    printf("Estic al xapp new sortint de report_sm_xapp_api");
  }

  sleep(2);


  for(int i = 0; i < nodes.len; ++i){
    // Remove the handle previously returned
    printf("Estic al xapp new just abans de rm_report_sm_xapp_api");
    rm_report_sm_xapp_api(new_handle[i].u.handle); //gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg
    printf("Estic al xapp new just despres de rm_report_sm_xapp_api");
  }

  if(nodes.len > 0){
    printf("Estic al xapp new just dins el if de nodes");
    free(new_handle);    
    printf("Estic al xapp new just dins el if de nodes despres de free");
  }

  //Stop the xApp
  while(try_stop_xapp_api() == false)
    usleep(1000);

  printf("Test xApp run SUCCESSFULLY\n");
}