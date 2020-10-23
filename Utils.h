#ifndef UTILS_H
#define UTILS_H
#include <inttypes.h>
#include <Arduino.h>

class Utils
{
  public:
    static void    sleep(int ms);
    static boolean isI2CPresent(uint8_t address);
	

  protected:

  private:
};

#endif // UTILS_H
