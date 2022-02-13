#ifndef __ROUTINE_HPP__
#define __ROUTINE_HPP__

struct Goal
{
    int morning = 0, night = 0;
    unsigned long irrigate_duration = 370370L;
    bool force_enable_relay = 0;
    int cur_hour = 0, cur_min = 0, cur_sec = 0;
};

struct Routine
{
    virtual bool act(Goal *) = 0; // Return 0 when acting success
    virtual String name(void) const noexcept = 0;
    virtual ~Routine() = 0;
};

#endif