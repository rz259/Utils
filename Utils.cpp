#include "Utils.h"
#include "Wire.h"

void Utils::sleep(int ms)

{
  int count;

  for (count = 0; count < ms; count++)
  {
    delay(1);
    yield();
  }
}

boolean Utils::isI2CPresent(uint8_t address)
{
  // Serial.print(" Scanning I2C Address: ");
  // Serial.println(address, HEX);
  Wire.beginTransmission(address);
  uint8_t ec=Wire.endTransmission(true);
  if (ec==0)
    return true;
  else
    return false;
}

