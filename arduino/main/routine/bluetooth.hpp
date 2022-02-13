#ifndef __BLUETOOTH_HPP__
#define __BLUETOOTH_HPP__

#ifndef BAUD_RATE
#define BAUD_RATE 115200
#endif

#include "routine.hpp"
#include "../debug.hpp"

#include <BluetoothSerial.h>

class Bluetooth_service : public Routine
{
    BluetoothSerial BT;

    inline bool avaliable() const noexcept { return BT.available(); }

public:
    Bluetooth_service()
    {
        BT.begin(BAUD_RATE);
        BT.begin("FARM");

        Serial_debug("Bluetooth init done");
    }
    ~Bluetooth_service() = default;

    virtual bool act(Goal *) override;
    virtual String name(void) const noexcept override
    {
        return String("Bluetooth_service");
    };
};

#endif