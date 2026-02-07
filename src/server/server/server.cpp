#include "server/server.hpp"
#include "logger/logger.hpp"

#include <string_view>

Server::Server (std::string_view host, std::size_t port) : Server ()
{
  Logger{} << "Starting server" << "at host:" << host << "port:" << port;
}

Server::~Server () { Logger{} << "Stopping server"; }