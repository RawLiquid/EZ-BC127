#include "BC127.h"

BC127::opResult BC127::enableGPIOControl()
{
  static opResult result = stdSetParam("GPIO_CONFIG", "ON 0");

#if DEBUG_BC127
  Serial.print("BC127 | SET GPIO_CONFIG=ON 0..." + convertCommandResultToString(result) + "\r");
#endif
  return result;
}

BC127::opResult BC127::disableGPIOControl()
{
  static opResult result = stdSetParam("GPIO_CONFIG", "OFF 8");

#if DEBUG_BC127
  Serial.print("BC127 | SET GPIO_CONFIG=OFF 8..." + convertCommandResultToString(result) + "\r");
#endif
  return result;
}

BC127::opResult BC127::enableAutoData(bool shouldReboot)
{
  static opResult result = stdSetParam("AUTO_DATA", "ON ON");

#if DEBUG_BC127
  Serial.print("BC127 | SET AUTO_DATA=ON ON..." + convertCommandResultToString(result) + "\r");
#endif

  if (shouldReboot)
  {
    reset();
  }

  return result;
}

BC127::opResult BC127::disableAutoData(bool shouldReboot)
{
  static opResult result = stdSetParam("AUTO_DATA", "ON ON");

#if DEBUG_BC127
  Serial.print("BC127 | SET AUTO_DATA=OFF OFF..." + convertCommandResultToString(result) + "\r");
#endif

  if (shouldReboot)
  {
    reset();
  }

  return result;
}

BC127::opResult BC127::enableAutoConn(bool shouldReboot)
{
  static opResult result = stdSetParam("AUTOCONN", "1");

#if DEBUG_BC127
  Serial.print("BC127 | SET AUTOCONN=1..." + convertCommandResultToString(result) + "\r");
#endif

  if (shouldReboot)
  {
    reset();
  }

  return result;
}

BC127::opResult BC127::disableAutoConn(bool shouldReboot)
{
  static opResult result = stdSetParam("AUTOCONN", "0");

#if DEBUG_BC127
  Serial.print("BC127 | SET AUTOCONN=0..." + convertCommandResultToString(result) + "\r");
#endif

  if (shouldReboot)
  {
    reset();
  }

  return result;
}

BC127::opResult BC127::enableHDAudio()
{
  static opResult result = stdSetParam("CODEC", "3");

#if DEBUG_BC127
  Serial.print("BC127 | SET CODEC=3..." + convertCommandResultToString(result) + "\r");
#endif
  return result;
}

BC127::opResult BC127::disableAdvertisingOnStartup()
{
  static opResult result = stdSetParam("BT_STATE_CONFIG", "0 0");

#if DEBUG_BC127
  Serial.print("BC127 | SET BT_STATE_CONFIG=0 0..." + convertCommandResultToString(result) + "\r");
#endif
  return result;
}

BC127::opResult BC127::disableiOSBatteryIndicator()
{
  static opResult result = stdSetParam("ENABLE_BATT_IND", "OFF");

#if DEBUG_BC127
  Serial.print("BC127 | SET ENABLE_BATT_IND=OFF..." + convertCommandResultToString(result) + "\r");
#endif
  return result;
}

BC127::opResult BC127::enableBLEAdvertising()
{
  static opResult result = stdSetParam("BLE_CONFIG", "0 ON 40 ON");

#if DEBUG_BC127
  Serial.print("BC127 | CMD BLE_CONFIG 0 ON 40 ON..." + convertCommandResultToString(result) + "\r");
#endif
  return result;
}

BC127::opResult BC127::disableAdvertising()
{
  static opResult result = stdSetParam("BLE_CONFIG", "0 OFF 40 ON");

#if DEBUG_BC127
  Serial.print("BC127 | SET BLE_CONFIG=0 OFF 40 ON..." + convertCommandResultToString(result) + "\r");
#endif
  return result;
}

BC127::opResult BC127::setName(String name, bool shouldReboot)
{
  static opResult result = stdSetParam("NAME", name);

#if DEBUG_BC127
  Serial.print("BC127 | SET NAME=" + name + "..." + convertCommandResultToString(result) + "\r");
#endif

  if (shouldReboot)
  {
    reset();
  }

  return result;
}

BC127::opResult BC127::setShortName(String name, bool shouldReboot)
{
  static opResult result = stdSetParam("NAME_SHORT", name);

#if DEBUG_BC127
  Serial.print("BC127 | SET NAME_SHORT=" + name + "..." + convertCommandResultToString(result) + "\r");
#endif

  if (shouldReboot)
  {
    reset();
  }

  return result;
}

BC127::opResult BC127::setMaxNumOfReconnectionAttempts(int  maxNum,
                                                       bool shouldReboot)
{
  static opResult result = stdSetParam("MAX_REC", String(maxNum));

#if DEBUG_BC127
  Serial.print("BC127 | SET MAX_REC=" + String(maxNum) + "..." + convertCommandResultToString(result) + "\r");
#endif

  if (shouldReboot)
  {
    reset();
  }

  return result;
}

BC127::opResult BC127::setUARTConfig()
{
  static String   uartConfig = String(_serialBaud) + " OFF 0";
  static opResult result     = stdSetParam("UART_CONFIG", uartConfig);

#if DEBUG_BC127
  Serial.print("BC127 | SET UART_CONFIG=" + uartConfig + "..." + convertCommandResultToString(result) + "\r");
#endif
  return result;
}

BC127::opResult BC127::setVolConfig()
{
  static String   volConfig = "A 60 10 0";
  static opResult result    = stdSetParam("BT_VOL_CONFIG", volConfig);

#if DEBUG_BC127
  Serial.print("BC127 | SET BT_VOL_CONFIG=" + volConfig + "..." + convertCommandResultToString(result) + "\r");
#endif
  return result;
}

BC127::opResult BC127::setCodType()
{
  static opResult result = stdSetParam("COD", _codType);

#if DEBUG_BC127
  Serial.print("BC127 | SET COD=" + _codType + "..." + convertCommandResultToString(result) + "\r");
#endif
  return result;
}
