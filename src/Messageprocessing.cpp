/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Messageprocessing.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:34:11 by apardo-m          #+#    #+#             */
/*   Updated: 2025/01/21 17:12:36 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Messageprocessing.hpp"

// Public

Messageprocessing::Messageprocessing( void )
{
	std::cout << "Messageprocessing => Creating _command Map" << std::endl;
	this->_commands["PING"] = new Ping();
}

Messageprocessing::~Messageprocessing( void )
{
	std::cout << "~Messageprocessing => Delete _commands" << std::endl;
	for (std::map<std::string, ICommand*>::iterator it = _commands.begin(); it != _commands.end(); ++it)
    {
        delete it->second;
    } 
}

/* ------------------- PUBLIC MEMBER FUNCTIONS ------------------*/

void	Messageprocessing::processMessage(std::string message)
{
	// TODO
	//
	// 1 - Parssing message
	// 2 - Detect COMMAND
	// 3 - Execute COMMAND
	
	std::cout << "processMessage(std:string message) with message = " << message << std::endl;
	std::cout << "----- PING test -----" << std::endl;
	this->_commands["PING"]->execute();
	this->_commands["PING"]->execute(message);
	std::cout << "----- end PING test -----" << std::endl;   
}
