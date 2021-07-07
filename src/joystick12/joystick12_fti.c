/*
 * Author: Noel Eck <noel.eck@intel.com>
 * Copyright (c) 2015 Intel Corporation.
 *
 * This program and the accompanying materials are made available under the
 * terms of the The MIT License which is available at
 * https://opensource.org/licenses/MIT.
 *
 * SPDX-License-Identifier: MIT
 */

#include <string.h>
#include <stdlib.h>

#include "joystick12.h"
#include "upm_fti.h"
#include "fti/upm_sensor.h"
#include "fti/upm_joystick.h"

/** 
 * This file implements the Function Table Interface (FTI) for this sensor
 */

const char upm_joystick12_name[] = "JOYSTICK12";
const char upm_joystick12_description[] = "Analog joystick sensor";
const upm_protocol_t upm_joystick12_protocol[] = {UPM_ANALOG};
const upm_sensor_t upm_joystick12_category[] = {UPM_JOYSTICK};

// forward declarations
const void* upm_joystick12_get_ft(upm_sensor_t sensor_type);
void* upm_joystick12_init_str(const char* protocol, const char* params);
void upm_joystick12_close(void* dev);
const upm_sensor_descriptor_t upm_joystick12_get_descriptor();
upm_result_t upm_joystick12_set_offset_x(const void* dev, float offset);
upm_result_t upm_joystick12_set_offset_y(const void* dev, float offset);
upm_result_t upm_joystick12_set_scale_x(const void* dev, float scale);
upm_result_t upm_joystick12_set_scale_y(const void* dev, float scale);
upm_result_t upm_joystick12_get_value_x(const void* dev, float *value);
upm_result_t upm_joystick12_get_value_y(const void* dev, float *value);



/* This sensor implementes 2 function tables */
/* 1. Generic base function table */
static const upm_sensor_ft ft_gen =
{
    .upm_sensor_init_name = &upm_joystick12_init_str,
    .upm_sensor_close = &upm_joystick12_close,
    .upm_sensor_get_descriptor = &upm_joystick12_get_descriptor
};

/* 2. JOYSTICK function table */
static const upm_joystick_ft ft_joystick =
{
    .upm_joystick_set_offset_x = &upm_joystick12_set_offset_x,
    .upm_joystick_set_offset_y = &upm_joystick12_set_offset_y,
    .upm_joystick_set_scale_x = &upm_joystick12_set_scale_x,
    .upm_joystick_set_scale_y = &upm_joystick12_set_scale_y,
    .upm_joystick_get_value_x = &upm_joystick12_get_value_x,
    .upm_joystick_get_value_y = &upm_joystick12_get_value_y
};

const void* upm_joystick12_get_ft(upm_sensor_t sensor_type)
{
    switch(sensor_type)
    {
        case UPM_SENSOR:
            return &ft_gen;
        case UPM_JOYSTICK:
            return &ft_joystick;
        default:
            return NULL;
    }
}

void* upm_joystick12_init_str(const char* protocol, const char* params)
{
    fprintf(stderr, "String initialization - not implemented, using ain0 = x ain1 = y: %s\n", __FILENAME__);
    return joystick12_init(0, 1);
}

void upm_joystick12_close(void* dev)
{
    joystick12_close((joystick12_context)dev);
}

const upm_sensor_descriptor_t upm_joystick12_get_descriptor()
{
    /* Fill in the descriptor */
    upm_sensor_descriptor_t usd;
    usd.name = upm_joystick12_name;
    usd.description = upm_joystick12_description;
    usd.protocol_size = 1;
    usd.protocol = upm_joystick12_protocol;
    usd.category_size = 1;
    usd.category = upm_joystick12_category;

    return usd;
}

upm_result_t upm_joystick12_set_offset_x(const void* dev, float offset)
{
    return joystick12_set_offset_x((joystick12_context)dev, offset);
}

upm_result_t upm_joystick12_set_offset_y(const void* dev, float offset)
{
    return joystick12_set_offset_y((joystick12_context)dev, offset);
}

upm_result_t upm_joystick12_set_scale_x(const void* dev, float scale)
{
    return joystick12_set_scale_x((joystick12_context)dev, scale);
}

upm_result_t upm_joystick12_set_scale_y(const void* dev, float scale)
{
    return joystick12_set_scale_y((joystick12_context)dev, scale);
}

upm_result_t upm_joystick12_get_value_x(const void* dev, float *value)
{
    return joystick12_get_value_x((joystick12_context)dev, value);
}

upm_result_t upm_joystick12_get_value_y(const void* dev, float *value)
{
    return joystick12_get_value_y((joystick12_context)dev, value);
}

