# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 02:42:31 by pirulenc          #+#    #+#              #
#    Updated: 2024/02/15 03:10:30 by pirulenc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall \
		-Werror \
		-Wextra
		
NAME = client
NAME_BONUS = client_bonus

NAME_SERVER = server
NAME_SERVER_BONUS = server_bonus

SOURCES_CLIENT = ./Client/client.c
SOURCES_CLIENT_BONUS = ./Bonus/Client/client_bonus.c \
		./Bonus/Client/ft_treat_bonus.c
		

SOURCES_SERVER = ./Server/server.c
SOURCES_SERVER_BONUS = ./Bonus/Server/server_bonus.c \
		./Bonus/Server/pid_client_bonus.c


OBJECTS_CLIENT = $(SOURCES_CLIENT:.c=.o)
OBJECTS_CLIENT_BONUS = $(SOURCES_CLIENT_BONUS:.c=.o)

OBJECTS_SERVER = $(SOURCES_SERVER:.c=.o)
OBJECTS_SERVER_BONUS = $(SOURCES_SERVER_BONUS:.c=.o)

all: $(NAME)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJECTS_CLIENT_BONUS) $(OBJECTS_SERVER_BONUS)
	@${MAKE} -j -C ./Bonus/libft -s
	@echo LIBFT_BONUS COMPILED : ✓
	@$(CC) $(CFLAGS) $(OBJECTS_CLIENT_BONUS) ./Bonus/libft/libft.a -o $(NAME_BONUS)
	@echo CLIENT_BONUS COMPILED : ✓
	@$(CC) $(CFLAGS) $(OBJECTS_SERVER_BONUS) ./Bonus/libft/libft.a -o $(NAME_SERVER_BONUS)
	@echo SERVER_BONUS COMPILED : ✓
	
$(NAME): $(OBJECTS_CLIENT) $(OBJECTS_SERVER)
	@${MAKE}  -j -C ./libft -s
	@echo LIBFT COMPILED : ✓
	@$(CC) $(CFLAGS) $(OBJECTS_CLIENT) ./libft/libft.a -o $(NAME)
	@echo CLIENT COMPILED : ✓
	@$(CC) $(CFLAGS) $(OBJECTS_SERVER) ./libft/libft.a -o $(NAME_SERVER)
	@echo SERVER COMPILED : ✓
	
clean:
	@${MAKE} -C ./libft clean -s
	@${MAKE} -C ./Bonus/libft clean -s
	@echo LIBFT CLEAN : ✓
	@rm -f $(OBJECTS_CLIENT)
	@rm -f $(OBJECTS_CLIENT_BONUS)
	@echo CLIENT CLEAN : ✓
	@rm -f $(OBJECTS_SERVER)
	@rm -f $(OBJECTS_SERVER_BONUS)
	@echo SERVER CLEAN : ✓
	
	
fclean: clean
	@${MAKE} -C ./libft fclean -s
	@${MAKE} -C ./Bonus/libft fclean -s
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@rm -f $(NAME_SERVER)
	@rm -f $(NAME_SERVER_BONUS)
	
re: fclean all

PHONY: all clean fclean re
