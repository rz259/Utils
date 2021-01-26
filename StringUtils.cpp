/*
 * utils.cpp
 *
 *  Created on: 17.09.2020
 *      Author: RudolfZiegaus
 */

#include "StringUtils.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char * StringUtils::toHexString(const uint8_t *data, int bufferSize)
{
	return toHexString(data, bufferSize, "");
}

char * StringUtils::toHexString(const uint8_t *data, int bufferSize, const char *separator)
{
	int size = (2+strlen(separator))*bufferSize+1;
	char *result = (char *) calloc(1, size);

	for (int i = 0; i < bufferSize; i++)
	{
    if (i < bufferSize - 1)
    {
      sprintf(result+i*(2+strlen(separator)), "%02X%s", data[i], separator);
    }
    else
    {
      sprintf(result+i*(2+strlen(separator)), "%02X", data[i]);
    }
	}
	return result;
}


void StringUtils::toHexString(char *outputBuffer, int outputBufferSize, const uint8_t *data, int bufferSize)
{
	return toHexString(outputBuffer, outputBufferSize, data, bufferSize, "");
}


void StringUtils::toHexString(char *outputBuffer, int outputBufferSize, const uint8_t *data, int bufferSize, const char *separator)
{
	char *result = (char *) calloc(1, (2+strlen(separator))*bufferSize+1);

	for (int i = 0; i < bufferSize; i++)
	{
    if (i < bufferSize - 1)
    {
      sprintf(result+i*(2+strlen(separator)), "%02X%s", data[i], separator);
    }
    else
    {
      sprintf(result+i*(2+strlen(separator)), "%02X", data[i]);
    }
	}
	strncpy(outputBuffer, result, outputBufferSize);
	free(result);
}


String StringUtils::hexValueToString(const uint8_t *data, int bufferSize, const char *prefix, const char *separator)
{
	int separatorLength = strlen(separator);
	int prefixLength    = strlen(prefix);
	int size = (2 + separatorLength + prefixLength)*bufferSize+1;
	char s[20]; 
	String result;

  result = "";
	for (int i = 0; i < bufferSize; i++)
	{
    if (i < bufferSize - 1)
    {
      sprintf(s, "%s%02X%s", prefix, data[i], separator);
    }
    else
    {
      sprintf(s, "%s%02X", prefix, data[i]);
    }
		result += String(s);
	}
	return result;
}

/*
  preconditions:  
    - input string must have even length
		- no separators between bytes
		- no prefix (e. g. 0x) allowed
		
*/


void StringUtils::hexStringToByteArray(uint8_t *result, int outputSize, const char *data, int length)
{
	char s[3];
	uint8_t b;
	int index, count;
	
	// input string must have even length
  if (length % 2 == 1)	
		return;
	if (outputSize < length / 2)
		return;
	memset(result, 0, outputSize);
	
	for (index = 0, count = 0; index < length; index += 2, count++)
	{
	  strncpy(s, &data[index], 2);
		s[2] = 0x00;
		b = strtol(s, NULL, 16);
		result[count] = b;
	}
	
}


char * StringUtils::toUpper(const char *s)
{
	char *value = (char *) calloc(1, strlen(s)+1);
	char *p;

	p = value;
	while (*s)
	{
		*p = toupper(*s);
		s++;
		p++;
	}
	*p = '\0';
	return value;
}
