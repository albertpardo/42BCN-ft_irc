
#include "Mode.hpp"

Mode::~Mode( void ) {};

/* ------------------- PUBLIC MEMBER FUNCTIONS ------------------*/

std::string Mode::modeOption_push(std::string optionChain, char sign, char option)
{
	std::stringstream ss;
	ss.clear();
	char last = '\0';
	for (size_t i = 0; i < optionChain.size(); i++)
	{
		if (optionChain[i] == '+' || optionChain[i] == '-')
			last = optionChain[i];
	}
	if (last != sign)
		ss << sign << option;
	else
		ss << option;
	return ss.str();
}

std::string Mode::inviteOnly_mode(Channel *ch, char sign, std::string optionChain)
{
	std::string strOption;
	strOption.clear();
	if (sign == '+' && !ch->isInviteChannel() && !ch->getModeOption(0))
	{
		ch->setInviteChannel();
		ch->setModeOption(0, true);
		strOption = modeOption_push(optionChain, sign, 'i');
	}
	else if (sign == '-' && ch->isInviteChannel() && ch->getModeOption(0))
	{
		ch->unsetInviteChannel();
		ch->setModeOption(0, false);
		strOption = modeOption_push(optionChain, sign, 'i');
	}	
	return strOption;
}

std::string changeOperatorPrivilege(Server *server, Channel *ch, char sign, std::string nick)
{
	// (void)optionChain;

	std::string strOption;
	strOption.clear();
	nick = uppercase(nick);//debug
	std::cout << "--- changeOperatorPrivilege() - nick=" << nick << std::endl;
	ch->printChannelVars();//debug:w
	
	if (sign == '+')
	{
		//chek if nick is in memClients
		if (!ch->isMem(nick))
		{
			std::cout << "Error: Client with nick " << nick << " not found in channel!" << std::endl;
			return "";
		}
		else
		{
			std::cout << "Is in channel!" << std::endl;
		}
		//
		Client *client = server->getClientByNick(nick);//************************************************************segv */TO DEBUG
		if (!client)
		{
    		std::cout << "Error: Client with nick " << nick << " not found!" << std::endl;
    		return "";
		}
		ch->addOpe(client);
		std::cout << "PRIVILEGE ADDED" << std::endl;//debug
		printChannelsInfo(server);//debug
		//quitar desdd memClients
		ch->deleteMem(nick);
		std::cout << "MEMBER DELETED FROM CHANNEL" << std::endl;//debug
		printChannelsInfo(server);//debug
	}
	else if (sign == '-')
	{
		ch->deleteOpe(nick);
		std::cout << "PRIVILEGE DELETED" << std::endl;
		printChannelsInfo(server);
	}
	else {
		std::cout << "invalid sign!" << std::endl;
	}
	return (strOption);
}


void Mode::getModeArgs(std::string msg, std::string &channelName, std::string &option, std::string &param)
{
	std::istringstream ss(msg);
	ss >> channelName;
	ss >> option;
	size_t pos = msg.find_first_not_of(channelName + option + " \t\v");
	if (pos != std::string::npos)
		param = msg.substr(pos);
}

/* // the following is the example of the format of channel mode command:
	MODE #mychannel +i
	MODE #mychannel(channelName) +o(option) Bob(param)
	MODE #mychannel +k secret123
	MODE #mychannel +l 25
	mode #mychannel +t
	MODE #mychannel -i
*/
void Mode::execute( Server* server, std::string &msg , int fd)
{
	std::string 		channelName;
	std::string 		option;
	std::string 		param;
	std::stringstream 	optionChain;
	char				sign = '\0';
	
	std::cout << "Mode command is called!" << std::endl;//debug
	msg = trimLeft(msg);
	msg = msg.substr(4);
	msg = trimLeft(msg);
	// #mychannel +i/+i/-i
	if (!msg.empty() && (msg.size() >= 2 && (msg.substr(0, 2) == "+i" || msg.substr(0, 2) == "-i")))
		return ;
	else if (msg.empty() || (!msg.empty() && (msg.size() < 2 || (msg.size() >= 2 && (msg[0] != '#' && msg[0] != '&')))))
	{
		server->sendResp(ERR_NEEDMOREPARAMS(std::string("*"), "MODE"), fd);
		std::cout << "input channelname and channel mode option are incorrect!" << std::endl;//debug
		return ;
	}
	else 
		msg = msg.substr(1); // mychannel +i remove the first # or &
	std::cout << "mode msg: " << msg << std::endl; //debug
	getModeArgs(msg, channelName, option, param); // mychannel +i
	Client *cl = server->getClient(fd);
	std::string nick = cl->getNick();
	// the channelName doesn't exist 403
	if (!server->getChannelByChannelName(channelName))
	{
		std::string chaErrMsg = formatIRCMessage(ERR_CHANNELNOTFOUND(nick, channelName));
		server->sendResp(chaErrMsg, fd);
		return ;
	}
	// if the inviting client doesn't in this channel 442
	if (!server->getChannelByChannelName(channelName)->getCliInChannel(nick))
	{
		std::string chaErrMsg = formatIRCMessage(ERR_NOTONCHANNEL(nick, channelName));
		server->sendResp(chaErrMsg, fd);
		return ;
	}
	//if the invitor isn't operator of this channel 482
	if (!server->getChannelByChannelName(channelName)->isOpe(nick))
    {
		std::string chaErrMsg = formatIRCMessage(ERR_CHANOPRIVSNEEDED(nick, channelName));
		server->sendResp(chaErrMsg, fd);
		return ;
	}
	Channel *channel = server->getChannelByChannelName(channelName);
	//if the option of MODE is empty
	if (option.empty())
	{
		//#define                                    RPL_CHANNELMODEIS(nickname, channelname, modes, arguments) (": 324 " + nickname + " #" + channelname + " " + modes + " " + arguments + CRLF)
		std::string chaErrMsg = formatIRCMessage(RPL_CHANNELMODEIS(nick, channelName, msg.substr(0, 2), ""));
		server->sendResp(chaErrMsg, fd);
        return ;
	}
	else
	{
		for (size_t i = 0; i < option.size(); i++)
		{
			if (option[i] == '+' || option[i] == '-')//*o
			{
				sign = option[i];
				// std::cout << "sign: " << sign << std::endl;//debug
			}
			else
			{
				if (option[i] == 'i')
					optionChain << inviteOnly_mode(channel, sign, optionChain.str());
				else if (option[i] == 't')
				{}
				else if (option[i] == 'k')
				{}
				else if (option[i] == 'o')//WIP by castaorga
				{
					std::cout << "chanName=" << channel->getChannelName() << std::endl;
					std::cout << "param=" << param << std::endl;
					std::cout << "sign=" << sign << std::endl;
					optionChain << changeOperatorPrivilege(server, channel, sign, param);
				}
				else if (option[i] == 'l')
				{}
				else
				{
					std::string chaErrMsg = formatIRCMessage(ERR_UNKNOWNMODE(nick, channelName, option[i]));
					server->sendResp(chaErrMsg, fd);
        			return ;
				}
			}
		}
		std::string chain = optionChain.str(); //+i
		if (chain.empty())
			return ;
		std::string chaMsg = formatIRCMessage(RPL_CHANGEMODE(server->getServerName(), channelName, chain, param));
		server->sendBroadAllInChannel(chaMsg, server->getChannelByChannelName(channelName));
	}
	
}
