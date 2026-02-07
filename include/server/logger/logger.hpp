#pragma once

#include <chrono>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <sstream>

struct Logger
{
  constexpr Logger () = default;
  template <typename Type>
  friend Logger &
  operator<< (Logger &&log, Type &&value)
  {
    auto timestamp = [] {
      constexpr auto format = "%Y-%m-%d %H:%M:%S";
      using datetime = std::chrono::system_clock;
      auto time = datetime::to_time_t (datetime::now ());
      auto localtime = std::localtime (&time);
      auto strstr = std::stringstream{};
      strstr << std::put_time (localtime, format);
      return strstr.str ();
    };
    log.stream.get () << '[' << timestamp () << ']' << " LOG: " << value;
    return log;
  }
  template <typename Type>
  friend Logger &
  operator<< (Logger &log, Type &&value)
  {
    log.stream.get () << " " << value;
    return log;
  }

  virtual ~Logger () { stream.get () << std::endl; }

private:
  std::reference_wrapper<std::ostream> stream = std::cout;
};