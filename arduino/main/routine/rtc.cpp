#include "rtc.hpp"

String RTC_service::get_fmt_time(void) const noexcept
{
    bool century = false;
    bool SET_12_HR = false;
    bool pmFlag = false;

    const String year = String((int)RTC_Clock.getYear()); // Last 2 digits only
    const String month = String((int)RTC_Clock.getMonth(century));
    const String date = String((int)RTC_Clock.getDate());
    const String hour = String((int)RTC_Clock.getHour(SET_12_HR, pmFlag));
    const String minute = String((int)RTC_Clock.getMinute());
    const String second = String((int)RTC_Clock.getSecond());

    return year + "/" + month + "/" + date + " " + hour + ":" + minute + ":" + second;
}

bool RTC_service::act(Goal *g) override
{
    Serial_debug(String("Current time: ") + get_fmt_time());
    const int cur_hour_ = RTC_Clock.getHour();
    if (g->cur_hour != cur_hour_)
        g->cur_hour = cur_hour_;
    return 0;
}