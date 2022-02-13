#ifndef __IRRIGATE_HPP__
#define __IRRIGATE_HPP__
#include "routine.hpp"
#include "../debug.hpp"

class Irrigate_service : public Routine
{
    const int RELAY_PIN;
    bool had_been_irrigated = false;

    String get_info(void) const noexcept;

public:
    Irrigate_service() : Irrigate_service{2} {};
    Irrigate_service(int pin_) : RELAY_PIN(pin_)
    {
        pinMode(RELAY_PIN, OUTPUT);
        Serial_debug("Irrigate info: " + get_info());
    }
    ~Irrigate_service() = default;

    virtual bool act(Goal *) override;
    virtual String name(void) const noexcept override
    {
        return String("Irrigate_service");
    };
};

#endif