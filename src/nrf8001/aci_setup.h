/* Copyright (c) 2014, Nordic Semiconductor ASA
 *
 * This program and the accompanying materials are made available under the
 * terms of the The MIT License which is available at
 * https://opensource.org/licenses/MIT.
 *
 * SPDX-License-Identifier: MIT
 */

/** 
 * @file
 * @brief ACI setup functions
 * @ingroup aci
 */

#include <stdint.h>
#include "lib_aci.h"

#ifndef H_ACI_SETUP
#define H_ACI_SETUP

#define SETUP_SUCCESS                        0
#define SETUP_FAIL_COMMAND_QUEUE_NOT_EMPTY   1
#define SETUP_FAIL_EVENT_QUEUE_NOT_EMPTY     2
#define SETUP_FAIL_TIMEOUT                   3
#define SETUP_FAIL_NOT_SETUP_EVENT           4
#define SETUP_FAIL_NOT_COMMAND_RESPONSE      5

bool aci_setup_fill(aci_state_t *aci_stat, uint8_t *num_cmd_offset);
/** @brief Setup the nRF8001 device
 *  @details
 *  Performs ACI Setup by transmitting the setup messages generated by nRFgo Studio to the
 *  nRF8001, and should be called when the nRF8001 starts or resets.
 *  Once all messages are sent, the nRF8001 will send a Device Started Event.
 *  The function requires that the Command queue is empty when it is invoked, and will fail
 *  otherwise.
 *  @returns An integer indicating the reason the function terminated
 */
uint8_t do_aci_setup(aci_state_t *aci_stat);

#endif
