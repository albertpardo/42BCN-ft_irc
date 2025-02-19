
#include "Pass.hpp"
#include "Client.hpp"

void Pass::execute(Server* server, std::string &msg, int fd)
{
    Client* client = server->getClient(fd);

    msg = trimLeft(msg);
    msg = msg.substr(4);
    msg = trimLeft(msg);
    
    if (!msg.empty() && msg[0] == ':')
        msg = msg.substr(1);
    if (msg.empty())
    {
        server->sendResp(ERR_NEEDMOREPARAMS(std::string("*"), "PASS"), fd);  // 461
        return;
    }
    if (client->getHasPass()) {
        server->sendResp(ERR_ALREADYREGISTERED(std::string("*")), fd);  // 462
        return; 
    }
    msg = trimRight(msg);
    if (msg == server->getPassword()) {
        std::cout << YEL << "Correct password!" << RES << std::endl;
        client->setHasPass();
    } 
    else
        server->sendResp(ERR_PASSWDMISMATCH(std::string("*")), fd);  // 464
}

Pass::~Pass( void ) {};
