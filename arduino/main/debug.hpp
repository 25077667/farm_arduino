#ifndef __DEBUG_HPP__
#define __DEBUG_HPP__

#ifndef NDEBUG
#define Serial_debug(x) Serial.println((x))
#else

constexpr void do_nothing(const char *) noexcept
{
}

#define Serial_debug(x) do_nothing(#x)
#endif

#endif