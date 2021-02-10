/*
 * Base64.h
 *
 *  Created on: 30.09.2020
 *      Author: Rudolf
 */

#ifndef BASE64UTILS_H
#define BASE64UTILS_H

#include <stdlib.h>
#include <stdint.h>

class Base64
{
	public:
		static char *    encode(const uint8_t *src, size_t len, size_t *out_len);
		static uint8_t * decode(const char *src, size_t len, size_t *out_len);
};


#endif /* BASE64UTILS_H */



