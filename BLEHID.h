#ifndef _BLE_HID_H_
#define _BLE_HID_H_

#include "BLEPeripheral.h"

// #define USE_BOOT_PROTOCOL_MODE

class BLEHID
{
  public:
    BLEHID(unsigned char req, unsigned char rdy, unsigned char rst);

    void begin();

    BLECentral central();
    bool connected();

    size_t write(uint8_t k);

  private:
    BLEPeripheral                   _blePeripheral;
    BLEBondStore                    _bleBondStore;
    BLEService                      _hidService;

#ifdef USE_BOOT_PROTOCOL_MODE
    BLEUnsignedCharCharacteristic   _hidProtocolModeCharacteristic;
    BLECharacteristic               _bootKeyboardInputReportCharacateristic;
#endif
    BLEConstantCharacteristic       _hidReportMapCharacteristic;
    BLEConstantCharacteristic       _hidInformationCharacteristic;
    BLEUnsignedCharCharacteristic   _hidControlPointCharacteristic;

    BLECharacteristic               _hidReportCharacteristic1;
    BLEDescriptor                   _reportReferenceDescriptor1;
};

#endif