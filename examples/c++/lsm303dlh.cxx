/*
 * Author: Brendan Le Foll <brendan.le.foll@intel.com>
 * Copyright (c) 2014 Intel Corporation.
 *
 * This program and the accompanying materials are made available under the
 * terms of the The MIT License which is available at
 * https://opensource.org/licenses/MIT.
 *
 * SPDX-License-Identifier: MIT
 */

#include <iostream>
#include <stdint.h>

//! [Interesting]
#include "lsm303dlh.hpp"

int
main(int argc, char** argv)
{
    // Instantiate LSM303DLH compass on I2C
    upm::LSM303DLH sensor(0);

    // Get the coordinate data
    sensor.getCoordinates();
    int16_t* coor = sensor.getRawCoorData(); // in XYZ order.
    // The sensor returns XZY, but the driver compensates and makes it XYZ

    // Print out the X, Y, and Z coordinate data using two different methods
    std::cout << "coor: rX " << (int) coor[0] << " - rY " << (int) coor[1] << " - rZ "
              << (int) coor[2] << std::endl;
    std::cout << "coor: gX " << sensor.getCoorX() << " - gY " << sensor.getCoorY() << " - gZ "
              << sensor.getCoorZ() << std::endl;

    // Get and print out the heading
    std::cout << "heading: " << sensor.getHeading() << std::endl;

    // Get the acceleration
    sensor.getAcceleration();
    int16_t* accel = sensor.getRawAccelData();
    // Print out the X, Y, and Z acceleration data using two different methods
    std::cout << "acc: rX " << (int) accel[0] << " - rY " << (int) accel[1] << " - Z "
              << (int) accel[2] << std::endl;
    std::cout << "acc: gX " << sensor.getAccelX() << " - gY " << sensor.getAccelY() << " - gZ "
              << sensor.getAccelZ() << std::endl;

    return 0;
}
//! [Interesting]
