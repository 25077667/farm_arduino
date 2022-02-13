#define BAUD_RATE 115200

#include <memory>
#include <vector>
#include "routine/bluetooth.hpp"
#include "routine/rtc.hpp"
#include "routine/irrigate.hpp"
#include "debug.hpp"

std::vector<std::unique_ptr<Routine>> Work_list;
Goal goal;

void setup()
{
    Serial.begin(BAUD_RATE);

    Work_list.push_back(std::make_unique<RTC_service>{});
    Work_list.push_back(std::make_unique<Bluetooth_service>{});
    Work_list.push_back(std::make_unique<Irrigate_service>{});

    Serial_debug("Init done");
}

void loop()
{
    for (const auto &service : Work_list)
        if (service->act(&goal))
            Serial_debug(service->name() + " act failed");
}
