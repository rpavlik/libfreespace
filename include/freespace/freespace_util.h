/*
 * This file is part of libfreespace.
 *
 * Copyright (c) 2013 Hillcrest Laboratories, Inc.
 *
 * libfreespace is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef FREESPACE_UTIL_H_
#define FREESPACE_UTIL_H_

#include "freespace/freespace_codecs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup util Utility Functions API
 *
 * This page describes the utility functions API for supporting
 * communications and operations with Freespace(r) devices.
 */

/** This struct is used to exchange values for a sensor.
 * It contains 4 axes so that it can hold quaternions.
 * It is used as a general container for sensors with 1 to 4 axes.
 */
struct MultiAxisSensor {
    float w; /** temperature or quaternion w */
    float x; /** x axis or compass heading or activity classification */
    float y; /** y axis or power management flags */
    float z; /** z axis */
};

/** @ingroup util
 *
 * Get the acceleration values from a MEOut packet
 * For MEOut Format 0 and 3 units are m/s^2
 * For MEOut Format 1 units are g
 *
 * @param meOutPkt a pointer to the MEOut packet to extract the acceleration from
 * @param sensor a pointer to where to store the extracted values
 * @return 0 if successful
 *         -1 if the format flag was not set for the acceleration field
 *         -2 if the meOutPkt does not contain acceleration at all
 *         -3 if the format select number is unrecognized
 */
LIBFREESPACE_API int freespace_util_getAcceleration(struct freespace_MotionEngineOutput const * meOutPkt,
                                                    struct MultiAxisSensor * sensor);

/** @ingroup util
 *
 * Get the acceleration without gravity values from a MEOut packet
 * For MEOut Format 0 and 3 units are m/s^2
 * For MEOut Format 1 units are g
 *
 * @param meOutPkt a pointer to the MEOut packet to extract the acceleration no grav from
 * @param sensor a pointer to where to store the extracted values
 * @return 0 if successful
 *         -1 if the format flag was not set for the acceleration field
 *         -2 if the meOutPkt does not contain acceleration at all
 *         -3 if the format select number is unrecognized
 */
LIBFREESPACE_API int freespace_util_getAccNoGravity(struct freespace_MotionEngineOutput const * meOutPkt,
                                                    struct MultiAxisSensor * sensor);

/** @ingroup util
 *
 * Get the angular velocity values from a MEOut packet
 * For MEOut Format 0 and 3 units are rads/s
 * For MEOut Format 1 units are deg/s
 *
 * @param meOutPkt a pointer to the MEOut packet to extract the angular velocity from
 * @param sensor a pointer to where to store the extracted values
 * @return 0 if successful
 *         -1 if the format flag was not set for the angVel field
 *         -2 if the meOutPkt does not contain angVel at all
 *         -3 if the format select number is unrecognized
 */
LIBFREESPACE_API int freespace_util_getAngularVelocity(struct freespace_MotionEngineOutput const * meOutPkt,
                                                       struct MultiAxisSensor * sensor);

/** @ingroup util
 *
 * Get the magnetometer values from a MEOut packet
 * For MEOut Format 0 and 1 units are gauss
 * For MEOut Format 3 units are uTesla
 *
 * @param meOutPkt a pointer to the MEOut packet to extract the magnetometer from
 * @param sensor a pointer to where to store the extracted values
 * @return 0 if successful
 *         -1 if the format flag was not set for the mag field
 *         -2 if the meOutPkt does not contain mag at all
 *         -3 if the format select number is unrecognized
 */
LIBFREESPACE_API int freespace_util_getMagnetometer(struct freespace_MotionEngineOutput const * meOutPkt,
                                                    struct MultiAxisSensor * sensor);

/** @ingroup util
 *
 * Get the temperature values from a MEOut packet
 * For MEOut Format 0 and 3 units are degrees C
 *
 * @param meOutPkt a pointer to the MEOut packet to extract the magnetometer from
 * @param sensor a pointer to where to store the extracted values
 * @return 0 if successful
 *         -1 if the format flag was not set for the temperature field
 *         -2 if the meOutPkt does not contain temperature at all
 *         -3 if the format select number is unrecognized
 */
LIBFREESPACE_API int freespace_util_getTemperature(struct freespace_MotionEngineOutput const * meOutPkt,
                                                   struct MultiAxisSensor * sensor);

/** @ingroup util
 *
 * Get the inclination values from a MEOut packet
 * For MEOut Format 1 units are degrees
 *
 * @param meOutPkt a pointer to the MEOut packet to extract the inclination from
 * @param sensor a pointer to where to store the extracted values
 * @return 0 if successful
 *         -1 if the format flag was not set for the inclination field
 *         -2 if the meOutPkt does not contain inclination at all
 *         -3 if the format select number is unrecognized
 */
LIBFREESPACE_API int freespace_util_getInclination(struct freespace_MotionEngineOutput const * meOutPkt,
                                                   struct MultiAxisSensor * sensor);

/** @ingroup util
 *
 * Get the compass heading from a MEOut packet
 * For MEOut Format 1 units are degrees
 *
 * @param meOutPkt a pointer to the MEOut packet to extract the compass heading from
 * @param sensor a pointer to where to store the extracted values
 * @return 0 if successful
 *         -1 if the format flag was not set for the compass heading field
 *         -2 if the meOutPkt does not contain compass heading at all
 *         -3 if the format select number is unrecognized
 */
LIBFREESPACE_API int freespace_util_getCompassHeading(struct freespace_MotionEngineOutput const * meOutPkt,
                                                      struct MultiAxisSensor * sensor);

/** @ingroup util
 *
 * Get the angular position values from a MEOut packet
 *
 * @param meOutPkt a pointer to the MEOut packet to extract the angular position from
 * @param sensor a pointer to where to store the extracted values
 * @return 0 if successful
 *         -1 if the format flag was not set for the angular position field
 *         -2 if the meOutPkt does not contain angular position at all
 *         -3 if the format select number is unrecognized
 */
LIBFREESPACE_API int freespace_util_getAngPos(struct freespace_MotionEngineOutput const * meOutPkt,
                                              struct MultiAxisSensor * sensor);

/** @ingroup util
 *
 * Get the activity classification from a MEOut packet
 * For MEOut Format 1 units are degrees
 *
 * @param meOutPkt a pointer to the MEOut packet to extract the activity classification from
 * @param sensor a pointer to where to store the extracted values
 * @return 0 if successful
 *         -1 if the format flag was not set for the activity classification field
 *         -2 if the meOutPkt does not contain activity classification at all
 *         -3 if the format select number is unrecognized
 */
LIBFREESPACE_API int freespace_util_getActClass(struct freespace_MotionEngineOutput const * meOutPkt,
                                                struct MultiAxisSensor * sensor);

#ifdef __cplusplus
}
#endif

#endif /* FREESPACE_H_ */
