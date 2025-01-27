#ifndef QUIT_HPP
# define QUIT_HPP

# include <iostream>
# include "ICommand.hpp"

class Quit : public ICommand
{
	public:
		~Quit( void );

		void execute( std::string );
};

#endif

