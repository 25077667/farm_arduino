#include "bluetooth.hpp"

bool Bluetooth_service::act(Goal *g)
{
    if (!avaliable())
    {
        Serial_debug(name() + " is not avaliable now.");
        return 0;
    }

    String readin = this->BT.readString();

    if (readin[0] == 'm')
        g->morning = (readin[1] - '0') * 10 + (readin[2] - '0');
    else if (readin[0] == 'a')
        g->night = (readin[1] - '0') * 10 + (readin[2] - '0');
    else if (readin[0] == 's')
    {
        int index = 1;
        unsigned long duration = 0;
        while (readin[index] != 'q')
            duration = duration * 10 + (readin[index++] - '0');

        g->irrigate_duration = duration;
    }
    else if (readin[0] == 'w')
        g->force_enable_relay = !!(readin[1] ^ '0');
    else
        return 1;
    return 0;
}