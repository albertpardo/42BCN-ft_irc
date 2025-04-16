# Comandos IRC a Implementar

## Subject mandatory

Según mandatory ¿9 comandos?:

> **20250110** Los apartados **Reply** y **Error** se han de ver si se implementan todos o no.

> Los datos para **Reply** y **Error** he mirado [Assignment 2: Supporting Multiple Clients](https://chi.cs.uchicago.edu/chirc/assignment2.html). No se si haran falta más.

### how execute IRC server
Your executable will be run as follows: `./ircserv <port> <password>`

Where:
- **port**: The port number on which your IRC server will be listening to for incoming IRC connections.
- **password**: The connection password. It will be needed by any IRC client that tries to connect to your server.

### commands

You must be able to authenticate, set a nickname, a username, join a channel, send and receive private messages using your reference client.
	
#### [Connection Messages](https://modern.ircdocs.horse/#connection-messages) is associated to **password**.

##### [PASS message](https://modern.ircdocs.horse/#pass-message)

- **Format** : 

Format | Client Example
 ----  | -------  
PASS \<password\> | PASS hola 

- Reply
	- **A DEFINIR**
- Error:
	- [ERR_NEEDMOREPARAMS (461)](https://modern.ircdocs.horse/#errneedmoreparams-461)
	- [ERR_ALREADYREGISTERED (462)](https://modern.ircdocs.horse/#erralreadyregistered-462)
	- [ERR_PASSWDMISMATCH (464)](https://modern.ircdocs.horse/#errpasswdmismatch-464). In this case. server MAY then close the connection with [ERROR](https://modern.ircdocs.horse/#error-message)


##### [NICK message](https://modern.ircdocs.horse/#nick-message). See example in [Logging into an IRC server](https://chi.cs.uchicago.edu/chirc/irc_examples.html#logging-into-an-irc-server)

**[Restrictions](https://modern.ircdocs.horse/#clients)**
- They MUST NOT contain any of the following characters: space (' ', 0x20), comma (',', 0x2C), asterisk ('\*', 0x2A), question mark ('?', 0x3F), exclamation mark ('!', 0x21), at sign ('@', 0x40).
- They MUST NOT start with any of the following characters: dollar ('$', 0x24), colon (':', 0x3A).
- They MUST NOT start with a character listed as a :
- [channel type](https://modern.ircdocs.horse/#channel-types) : ('#', 0x23) , ('&', 0x26)
- [channel membership prefix](https://modern.ircdocs.horse/#channel-membership-prefixes) 
-  prefix listed in the IRCv3 [multi-prefix Extension](https://ircv3.net/specs/extensions/multi-prefix).
- They SHOULD NOT contain any dot character ('.', 0x2E).
- Servers MAY have additional implementation-specific nickname restrictions and SHOULD avoid the use of nicknames which are ambiguous with commands or command parameters where this could lead to confusion or error.

**Format** :

Format | Client Example
 ----  | -------  
NICK \<nickname\> | NICK Wiz

- Reply
	- **A DEFINIR**
- Error:
	- [ERR_NONICKNAMEGIVEN (431)](https://modern.ircdocs.horse/#errnonicknamegiven-431)
	- [ERR_ERRONEUSNICKNAME (432)](https://modern.ircdocs.horse/#errerroneusnickname-432)
	- [ERR_NICKNAMEINUSE (433)](https://modern.ircdocs.horse/#errnicknameinuse-433)
	- [ERR_NOTREGISTERED (451)](https://modern.ircdocs.horse/#errnotregistered-451)


##### [USER message](https://modern.ircdocs.horse/#user-message). See example in [Logging into an IRC server](https://chi.cs.uchicago.edu/chirc/irc_examples.html#logging-into-an-irc-server)

- **Format**: 

Format | Client Example
 ----  | -------  
USER \<username\> 0 * \<realname\> | USER guest 0 * :Ronnie Reagan

- Reply
	- **A DEFINIR**
- Error:
	- [ERR_NOTREGISTERED (451)](https://modern.ircdocs.horse/#errnotregistered-451)
	- [ERR_NEEDMOREPARAMS (461)](https://modern.ircdocs.horse/#errneedmoreparams-461) 
	- [ERR_ALREADYREGISTERED (462)](https://modern.ircdocs.horse/#erralreadyregistered-462)

#### [Channel Operations](https://modern.ircdocs.horse/#channel-operations)

##### [JOIN message](https://modern.ircdocs.horse/#join-message). See [Joining, talking in, and leaving a channel](https://chi.cs.uchicago.edu/chirc/irc_examples.html#joining-talking-in-and-leaving-a-channel)

- **Format**: 

Format | Client Example
 ----  | -------  
JOIN \<channel\>{,\<channel\>} [\<key\>{,\<key\>}] | JOIN #foo,#bar fubar,foobar 
*AltParam* 0 | What means 0 as *AltParam*?

Where : [key](https://modern.ircdocs.horse/#key-channel-mode) password for a channel

- Reply
	- **A DEFINIR**
- Error:
	- **A DEFINIR**

#### [Sending Messages](https://modern.ircdocs.horse/#sending-messages)

##### [PRIVMSG message](https://modern.ircdocs.horse/#privmsg-message). 
- Talk when users are not in any channel . See [Messaging between users](https://chi.cs.uchicago.edu/chirc/irc_examples.html#messaging-between-users).
- Talk whe user are in same channel [Joining, talking in, and leaving a channel](https://chi.cs.uchicago.edu/chirc/irc_examples.html#joining-talking-in-and-leaving-a-channel)

- **Format**: 

Format | Client Example
 ----  | -------  
PRIVMSG \<target\>{,\<target\>} \<text to be sent\> | PRIVMSG Angel :yes I'm receiving it !

Where : \<text to be sent\> for a string message this \<text to be sent\> must be start with `:`

- Reply
	- **A DEFINIR**
- Error:
	- **A DEFINIR**

#### specific to channel operators: [Channel Operations](https://modern.ircdocs.horse/#channel-operations)
	
##### [KICK](https://modern.ircdocs.horse/#kick-message): Eject a client from the channel

- **Format**: 

Format | Client Example
 ----  | -------  
KICK \<channel\> \<user\> \*( "," \<user\> ) [\<comment\>] | KICK #Finnish John :Speaking English

Where : \<comment\> for a string message this \<comment\> must be start with `:`

- Reply
	- [RPL_WHOISREGNICK (307)](https://modern.ircdocs.horse/#rplwhoisregnick-307)
- Errors
	- [ERR_NOSUCHNICK (401)](https://modern.ircdocs.horse/#errnosuchnick-401)
	- [ERR_WASNOSUCHNICK (406)](https://modern.ircdocs.horse/#errwasnosuchnick-406)
	- [ERR_NONICKNAMEGIVEN (431)](https://modern.ircdocs.horse/#errnonicknamegiven-431)
	- [ERR_ERRONEUSNICKNAME (432)](https://modern.ircdocs.horse/#errerroneusnickname-432)
	- [ERR_NICKNAMEINUSE (433)](https://modern.ircdocs.horse/#errnicknameinuse-433)
	- [ERR_NICKCOLLISION (436)](https://modern.ircdocs.horse/#errnickcollision-436)

##### [INVITE](https://modern.ircdocs.horse/#invite-message): Invite a client to an invite-only channel (mode +i)

- **Format**: 

Format | Client Example
 ----  | -------  
INVITE \<nickname\> \<channel\> | INVITE Wiz #foo_bar 

- Reply
	- **A DEFINIR**
- Error:
	- **A DEFINIR**
##### [TOPIC](https://modern.ircdocs.horse/#topic-message): Change the channel topic in a mode +t channel

- **Format**: 

Format | Client Example | Description
 ----  | -------------- | -----------  
TOPIC \<channel\> [\<topic\>] | TOPIC #test :New topic | Setting the topic on "#test" to  "New topic".
. | TOPIC #test : | Clearing the topic on "#test"
. | TOPIC #test   | Checking the topic for "#test"

- Reply
	- **A DEFINIR**
- Error:
	- **A DEFINIR**

#### specific to channel operators: [Server Queries and Commands](https://modern.ircdocs.horse/#server-queries-and-commands)

##### [MODE](https://modern.ircdocs.horse/#mode-message): Change the channel’s modes

- **Format**: 

Format | Client Example
 ----  | -------  
MODE \<target\> [\<modestring\> [\<mode arguments\>...]] | MODE dan +i | Setting the "invisible" user mode on dan

- Options :
	- **i**: Set/remove Invite-only channel
	- **t**: Set/remove the restrictions of the TOPIC command to channel operators
    - **k**: Set/remove the channel key (password)
    - **o**: Give/take channel operator privilege
	- **l**: Set/remove the user limit to channel
- Reply
	- **A DEFINIR**
- Error:
	- **A DEFINIR**

## Otros errores que se pueden usar
- [ERR_NEEDMOREPARAMS (461)](https://modern.ircdocs.horse/#errneedmoreparams-461)

## Comandos adicionales no indicados en el mandatory

### [Connection Messages](https://modern.ircdocs.horse/#connection-messages) 

#### [CAP message](https://modern.ircdocs.horse/#cap-message) enviado por un programa cliente tipo *irssi* al iniciar la comunicación. Posibilidades:
- Si es el primer comando enviado por el cliente:
	- Se puede Ignorar Por que no se hace NEGOCIACION.
- Si aparece en cualquier otro momento tras la autentificación se puede optar por una de estas dos opciones:
	1. Enviar un error de que no está soportado
	2. Ignorarlo

- **Format**: 

Format | Client Example
 ----  | -------  
CAP \<subcommand\> [:\<capabilities\>] | CAP LS 302

#### [QUIT message](https://modern.ircdocs.horse/#quit-message) para cerrar una sesión como alternativa a **Ctrl+C**.

- **Format**: 

Format | Client Example
 ----  | -------  
QUIT [\<reason\>] |  QUIT :Gone to have lunch

Where \<reason\> can be empty.

- Reply
	-  The server acknowledges this by replying with an [ERROR](https://modern.ircdocs.horse/#error-message) message and closing the connection to the client. 
	- This message may also be sent from the server to a client to show that a client has exited from the network. This is typically only dispatched to clients that share a channel with the exiting user. When the QUIT message is sent to clients, <source> represents the client that has exited the network.

Reply Format to QUIT's client | Example
 ---------------------------  | -------  
ERROR \<reason\>              |

Reply Format to clients in the same Channel as  QUIT's client  | Example | Description
 -----------------------------------------------------------  | ------- | ----------
. | :dan-!d@localhost QUIT :Quit: Bye for now! | dan- is exiting the network with the message: "Quit: Bye for now!"

## Para que IRSSI no se desconecte en 301 seconds

### [PING](https://modern.ircdocs.horse/#pong-message)

- **Format**: 

Format | Client Example
 ----  | -------  
PING \<token\> | PING myIRC |

- Reply
	- [PONG](https://modern.ircdocs.horse/#pong-message) with **Format**: 

Format | Client Example
 ----  | -------  
PONG [\<server\>] \<token\> | PONG 127.0.0.1 myIRC

- Error:
	- **A DEFINIR**

## ¿Se Necesitan?

### [Channel Operations](https://modern.ircdocs.horse/#channel-operations)

#### [PART message](https://modern.ircdocs.horse/#part-message). For leaving a channel. See [Joining, talking in, and leaving a channel](https://chi.cs.uchicago.edu/chirc/irc_examples.html#joining-talking-in-and-leaving-a-channel)

- **Format**: 

Format | Client Example
 ----  | -------  
PART \<channe\l>{,\<channel\>} [\<reason\>] | PART #twilight_zone 
