#include "irrigate.hpp"

namespace
{
    struct Time
    {
        int hour, min, sec;
        int prev_du = 0;
    } On_[2], Off_[2];

};

bool Irrigate_service::act(Goal *g)
{
    if (!had_been_irrigated && (g->cur_hour == g->morning ||
                                g->cur_hour == g->night))
    {
        digitalWrite(RELAY_PIN, true);
    }

    digitalWrite(RELAY_PIN, g->force_enable_relay);

    return 0;
}