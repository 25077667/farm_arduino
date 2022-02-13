#ifndef __RTC_HPP__
#define __RTC_HPP__

#include <DS3231.h>
#include <Wire.h>
#include "routine.hpp"
#include "../debug.hpp"

class RTC_service : public Routine
{
    DS3231 RTC_Clock;

public:
    RTC_service()
    {
        // DS3231 is communicating via I2C
        // Enable the I2C
        Wire.begin();

        delay(2); // Wait for the RTC hardware
        Serial_debug("RTC init time:" + get_fmt_time());
    }
    ~RTC_service() = default;
    String RTC_service::get_fmt_time(void) const noexcept;
    virtual bool act(Goal *) override;
    virtual String name(void) const noexcept override
    {
        return String("RTC_service");
    };
};

#endif