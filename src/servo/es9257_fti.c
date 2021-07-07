/*
 * Author: Yevgeniy Kiveisha <yevgeniy.kiveisha@intel.com>
 *         Abhishek Malik <abhishek.malik@intel.com>
 * Copyright (c) 2014 Intel Corporation.
 *
 * This program and the accompanying materials are made available under the
 * terms of the The MIT License which is available at
 * https://opensource.org/licenses/MIT.
 *
 * SPDX-License-Identifier: MIT
 */

#include "es9257.h"

#include "upm_fti.h"

/** 
 * This file implements the Function Table Interface (FTI) for this sensor
 */

const char upm_es9257_name[] = "ES9257";
const char upm_es9257_description[] = "Grove Servo Motor";
const upm_protocol_t upm_es9257_protocol[] = {UPM_PWM};
const upm_sensor_t upm_es9257_category[] = {UPM_SERVO};

// forward declarations
const upm_sensor_descriptor_t upm_es9257_get_descriptor ();
const void* upm_es9257_get_ft(upm_sensor_t sensor_type);
void* upm_es9257_init_name();
upm_result_t upm_es9257_set_angle(void* dev, int32_t angle);
void upm_es9257_close(void* dev);

const upm_sensor_descriptor_t upm_es9257_get_descriptor (){
    upm_sensor_descriptor_t usd;
    usd.name = upm_es9257_name;
    usd.description = upm_es9257_description;
    usd.protocol_size = 1;
    usd.protocol = upm_es9257_protocol;
    usd.category_size = 1;
    usd.category = upm_es9257_category;
    return usd;
}

static const upm_sensor_ft ft =
{
    .upm_sensor_init_name = &upm_es9257_init_name,
    .upm_sensor_close = &upm_es9257_close,
    .upm_sensor_get_descriptor = &upm_es9257_get_descriptor
};

static const upm_servo_ft sft =
{
    .upm_servo_set_angle = &upm_es9257_set_angle
};

const void* upm_es9257_get_ft(upm_sensor_t sensor_type){
    if(sensor_type == UPM_SERVO){
        return &sft;
    }
    else if(sensor_type == UPM_SENSOR){
        return &ft;
    }
    return NULL;
}

void* upm_es9257_init_name(){
    return NULL;
}

void upm_es9257_close(void* dev){
    es9257_halt((es9257_context)dev);
}

upm_result_t upm_es9257_set_angle(void* dev, int32_t angle){
    return es9257_set_angle((es9257_context)dev, angle);
}