
#ifndef CLIENT_HPP
# define CLIENT_HPP

# include <iostream>

class Client
{
	private:
		int			_fdClient;//init ok
		std::string	_ipClient;//init ok

		std::string	_nick;
		std::string _userName;
		std::string _realName;

		std::string	_bufferInMessage;
		std::string	_bufferOutResponse;

		bool		_hasPass;
		bool		_hasNick;
		bool		_hasUser;
		bool		_hasAuth;	  // Athenticated user with  password, nick, USER
							   
//	tipo lista  _channelsOperator;
//	tipo lista  _channelsList;

	public:
		Client( void );
		Client( int fd, std::string ipClient );
		Client( Client const &src );
		Client &operator=( Client const &src );
		~Client( void );

		int			getFdClient( void ) const;
		void		setFdClient( int fd );
		std::string	getIpClient( void ) const;
		void		setIpClient( std::string ip );

		std::string	getNick( void ) const;
		void		setNick( std::string nick );
		std::string getUserName( void ) const;
		void		setUserName( std::string user );
		std::string getRealName( void ) const;
		void		setRealName( std::string real ) ;

		std::string	getBufferInMessage( void ) const;
		void		setBufferInMessage( std::string inMessage ) ;
		std::string	getBufferOutResponse( void ) const;
		void 		setBufferOutResponse( std::string outResponse ) ;

		bool		getHasPass( void ) const;
		bool		getHasNick( void ) const;
		bool		getHasUser( void ) const;
		bool		getHasAuth( void ) const;	
		void		setHasPass( void );
		void		setHasNick( void );
		void		setHasUser( void );
		void		setHasAuth( void );	

// For debugging
		void		printClientVars( void ); 
};

#endif
