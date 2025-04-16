## Algoritmo de [iLinea 274 -> `void Server::parse_exec_cmd(std::string &cmd, int fd)`](https://github.com/AhmedFatir/ft_irc/blob/master/SRC/Server.cpp#L254)

1. Tener el *comando/mensaje* que empiece por cualquier CHAR que no sea: espacio, tabulador  `\t` ó '\v`.  Variable `cmd`.
2. Hacer un split para tener la primera string . La denomina `splited_cmd[0]` y es para comporbar el tipo de comando.
3. Si `splited_cmd[0]` es uno de los siguientes : `PASS, NICK, USER, QUIT`. Lo ejecuta.
4. Si `notregistered(fd)` [ver linea 267 en `bool Server::notregistered(int fd)`](https://github.com/AhmedFatir/ft_irc/blob/master/SRC/Server.cpp#L267)  es uno de los posibles comandos que ha implentado lo ejecuta pasando `cmd` o lanza un error
5. Si `!notregistered(fd)` envia error que no está registrado


Hace el parseo en cada COMANDO.
