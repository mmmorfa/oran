/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.1  (the "License"); you may not use this file
 * except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.openairinterface.org/?page_id=698
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *-------------------------------------------------------------------------------
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
 */



#include "new_enc_plain.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

byte_array_t new_enc_event_trigger_plain(new_event_trigger_t const* event_trigger)
{
  assert(event_trigger != NULL);
  byte_array_t  ba = {0};
 
  ba.len = sizeof(event_trigger->ms);
  ba.buf = malloc(ba.len);
  assert(ba.buf != NULL && "Memory exhausted");

  memcpy(ba.buf, &event_trigger->ms, ba.len);

  return ba;
}

byte_array_t new_enc_action_def_plain(new_action_def_t const* action_def)
{
  assert(0!=0 && "Not implemented");

  assert(action_def != NULL);
  byte_array_t  ba = {0};
  return ba;
}

byte_array_t new_enc_ind_hdr_plain(new_ind_hdr_t const* ind_hdr)
{
  assert(ind_hdr != NULL);

  byte_array_t ba = {0};

  ba.len = sizeof(new_ind_hdr_t);

  ba.buf = calloc(ba.len, sizeof(uint8_t));
  assert(ba.buf != NULL && "memory exhausted");
  memcpy(ba.buf, ind_hdr, ba.len);

  return ba;
}

byte_array_t new_enc_ind_msg_plain(new_ind_msg_t const* ind_msg)
{
  assert(ind_msg != NULL);

  byte_array_t ba = {0};

  size_t const sz = sizeof(ind_msg->len) + 
                  sizeof(new_radio_bearer_stats_t)*ind_msg->len + 
                  sizeof(ind_msg->tstamp);

//  printf("Size of the byte array = %lu\n", sz);

  ba.buf = malloc(sz); 
  assert(ba.buf != NULL && "Memory exhausted");

  memcpy(ba.buf, &ind_msg->len, sizeof(ind_msg->len));

  void* it = ba.buf + sizeof(ind_msg->len);
  for(uint32_t i = 0; i < ind_msg->len ; ++i){
    memcpy(it, &ind_msg->rb[i], sizeof(ind_msg->rb[i]));
    it += sizeof(ind_msg->rb[i]);
  }

  memcpy(it, &ind_msg->tstamp, sizeof(ind_msg->tstamp));
  it += sizeof(ind_msg->tstamp);

  assert(it == ba.buf + sz && "Mismatch of data layout");

  ba.len = sz;
  return ba;
}

byte_array_t new_enc_call_proc_id_plain(new_call_proc_id_t const* call_proc_id)
{
  assert(0!=0 && "Not implemented");

  assert(call_proc_id != NULL);
  byte_array_t  ba = {0};
  return ba;
}

byte_array_t new_enc_ctrl_hdr_plain(new_ctrl_hdr_t const* ctrl_hdr)
{
  assert(ctrl_hdr != NULL);
  byte_array_t  ba = {0};
  ba.len = sizeof(new_ctrl_hdr_t);
  ba.buf = calloc(ba.len, sizeof(uint8_t)); 
  assert(ba.buf != NULL && "Memory exhausted");

  memcpy(ba.buf, ctrl_hdr, ba.len);

  return ba;
}

byte_array_t new_enc_ctrl_msg_plain(new_ctrl_msg_t const* ctrl_msg)
{
  assert(ctrl_msg != NULL);

  byte_array_t  ba = {0};
  ba.len = sizeof(new_ctrl_hdr_t);

  ba.buf = calloc(ba.len ,sizeof(uint8_t)); 
  assert(ba.buf != NULL && "Memory exhausted");

  memcpy(ba.buf, ctrl_msg, ba.len);

  return ba;
}

byte_array_t new_enc_ctrl_out_plain(new_ctrl_out_t const* ctrl) 
{
  assert(0!=0 && "Not implemented");

  assert( ctrl != NULL );
  byte_array_t  ba = {0};
  return ba;
}

byte_array_t new_enc_func_def_plain(new_func_def_t const* func)
{
  assert(0!=0 && "Not implemented");

  assert(func != NULL);
  byte_array_t  ba = {0};
  return ba;
}

