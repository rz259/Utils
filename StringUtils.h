/*
 * utils.h
 *
 *  Created on: 17.09.2020
 *      Author: RudolfZiegaus
 */

#ifndef STRINGUTILS_H_
#define STRINGUTILS_H_

#include <stdint.h>
#include <Arduino.h>

class StringUtils
{
	public:
		static char* toHexString(const uint8_t *data, int bufferSize);
		static char * toHexString(const uint8_t *data, int bufferSize, const char *separator);
		static void toHexString(char *outputBuffer, int outputBufferSize, const uint8_t *data, int bufferSize);
		static void toHexString(char *outputBuffer, int outputBufferSize, const uint8_t *data, int bufferSize, const char *separator);
    static String hexValueToString(const uint8_t *data, int bufferSize, const char *prefix = "", const char *separator = "");
		
		static void hexStringToByteArray(uint8_t * result, int outputSize, const char *data, int length);
		
    static char* toUpper(const char *s);

};

#endif /* STRINGUTILS_H_ */
