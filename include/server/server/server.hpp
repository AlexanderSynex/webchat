#pragma once

#include <cstddef>
#include <string_view>
#include <unordered_map>

class Server
{
  using session_id = std::size_t;
  using client_id = std::size_t;

public:
  constexpr Server () = default;

  virtual ~Server();

  Server(std::string_view host, std::size_t port);

private:
  std::unordered_multimap<session_id, client_id> sessions = {};
};
