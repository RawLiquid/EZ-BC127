#include "BC127.h"

BC127::opResult BC127::enableConnectableAndDiscoverable()
{
  static opResult result = stdCmd("BT_STATE ON ON");
#if DEBUG_BC127
  Serial.print("Setting connectable and discoverable to true: BT_STATE ON ON -> " + commandResult(result) + "\r");
#endif
  return result;
}

BC127::opResult BC127::resetPIO4()
{
  static opResult result = stdCmd("PIO 4 OFF");
#if DEBUG_BC127
  Serial.print("Resetting PIO 4: PIO 4 OFF -> " + commandResult(result) + "\r");
#endif
  return result;
}

BC127::opResult BC127::enableBLEAdvertising()
{
  static opResult result = stdSetParam("BLE_CONFIG", "0 ON 40 ON");
#if DEBUG_BC127
  Serial.print("Enabling BLE Advertising: BLE_CONFIG 0 ON 40 ON -> " + commandResult(result) + "\r");
#endif
  return result;
}