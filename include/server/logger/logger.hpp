#pragma once

#include <functional>
#include <iostream>
#include <ostream>

struct Logger
{
  constexpr Logger () = default;
  template <typename Type>
  friend Logger &
  operator<< (Logger &&log, Type &&value)
  {
    log.stream.get () << "LOG: " << value << " ";
    return log;
  }
  template <typename Type>
  friend Logger &
  operator<< (Logger &log, Type &&value)
  {
    log.stream.get () << value << " ";
    return log;
  }

  virtual ~Logger () { stream.get () << std::endl; }

private:
  std::reference_wrapper<std::ostream> stream = std::cout;
};