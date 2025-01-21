/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:02:50 by apardo-m          #+#    #+#             */
/*   Updated: 2025/01/21 11:22:55 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

Client::Client( int fd, std::string ipClient ) :_fdClient(fd), _ipClient(ipClient)
{
	this->_nick = "";
	this->_userName = "";
	this->_realName = "";

	this->_bufferInMessage = "";
	this->_bufferOutResponse = "";

	this->_hasPass = false;
	this->_hasNick = false;
	this->_hasUser = false;
	this->_hasAuth = false;
}

Client::~Client( void ) {}

int		Client::getFdClient( void ) const { return (this->_fdClient	); }

void	Client::setFdClient( int fd ) { this->_fdClient = fd; }

std::string	Client::getIpClient( void ) const { return ( this->_ipClient ); }

void	Client::setIpClient( std::string ip ) { this->_ipClient = ip; }

std::string	Client::getNick( void ) const { return ( this->_nick ); }

void	Client::setNick( std::string nick ) { this->_nick = nick;}
		
std::string Client::getUserName( void ) const { return ( this->_userName ); }

void	Client::setUserName( std::string user ) { this->_userName = user;}
	
std::string Client::getRealName( void ) const { return ( this->_realName ); }

void	Client::setRealName( std::string real ) { this->_realName = real ;}

std::string	Client::getBufferInMessage( void ) const { return ( this->_bufferInMessage ); }

void	Client::setBufferInMessage( std::string inMessage ) { this->_bufferInMessage = inMessage; }
	
std::string	Client::getBufferOutResponse( void ) const { return ( this->_bufferOutResponse ); }

void	Client::setBufferOutResponse( std::string outResponse ) { this->_bufferOutResponse = outResponse; }

bool	Client::getHasPass( void ) const { return ( this->_hasPass ); }
		
bool	Client::getHasNick( void ) const { return ( this->_hasNick ); }
	
bool	Client::gethasUser( void ) const { return ( this->_hasUser ); }
	
bool	Client::gethasAuth( void ) const { return ( this->_hasAuth ); }
	
void	Client::setHasPass( void ) { this->_hasPass = true; }

void	Client::setHasNick( void ) { this->_hasNick = true; }
		
void	Client::sethasUser( void ) { this->_hasUser = true; }
	
void	Client::sethasAuth( void ) { this->_hasAuth = true; }	
