/*
 * ControlMeaage.h
 *
 *  Created on: 2017. 4. 19.
 *      Author: JOON
 */

#ifndef SRC_CONTROLMEAAGE_H_
#define SRC_CONTROLMEAAGE_H_

#include <stdint.h>

struct __attribute__((packed)) DriveControlMeaage {
#ifdef WORDS_BIGENDIAN
	uint8_t version:2;
	uint8_t isForword:1;
	uint8_t isRight:1;
	uint8_t reserved:4;
#else
	uint8_t reserved:4;
	uint8_t isRight :1;
	uint8_t isForword :1;
	uint8_t version :2;
#endif //WORDS_BIGENDIAN
	uint8_t speed;
	uint8_t steering;
};

#endif /* SRC_CONTROLMEAAGE_H_ */
