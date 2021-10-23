NAME =

CC = gcc

CFLAGS = -Werror -Wall -Wextra

SERVER = server
SERVER_SRCS = srcs/main_server.c \
			  srcs/utils3.c

CLIENT = client
CLIENT_SRCS = srcs/main_client.c \
			  srcs/utils.c \
			  srcs/utils2.c 

all : $(SERVER) $(CLIENT)

$(CLIENT) : $(CLIENT_SRCS)
	@$(CC) $(CLIENT_SRCS) -o $(CLIENT)
	@printf "\e[32m$@ built\e[0m\n"

$(SERVER) : $(SERVER_SRCS)
	@$(CC) $(SERVER_SRCS) -o $(SERVER)
	@printf "\e[32m$@ built\e[0m\n"

%.o : %.c
	@$(CC) $(FLAGS) $< -c

clean :
	@rm -f server client 
	@printf "\e[31mAll clean\e[0m\n"

fclean : clean
	@rm -f $(SERVER) $(CLIENT)
	@printf "\e[31mAll clean\e[0m\n"

re : fclean all

.PHONY: all clean fclean re