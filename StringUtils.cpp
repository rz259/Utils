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


char * StringUtils::toUpper(const char *s)
{
	char *value = (char *) calloc(1, strlen(s));
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
