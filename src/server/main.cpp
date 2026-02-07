#include "server/server.hpp"

using namespace std;

int
main (int argc, char *argv[])
{
  Server srv("0.0.0.0", 8080);
  return 0;
}
