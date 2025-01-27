
#include "Messageprocessing.hpp"

#include "Server.hpp"

int parseInput(std::string password, int port)
{
    if (port < 1024 || port > 65535)
    {
        std::cerr << "Invalid port number. Must be beetwen 1024 and 65535" << std::endl;
        return (1);
    }
    if (std::strlen(password.c_str()) < 4)
    {
        std::cerr << "Password must be at least 4 characters long" << std::endl;
        return (1);
    }
    return (0);
}
