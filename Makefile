# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zaiicko <meskrabe@student.s19.be>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 22:50:41 by zaiicko           #+#    #+#              #
#    Updated: 2024/07/14 23:26:02 by zaiicko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server
CLIENT_NAME = client
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INC_DIR = inc
INC = -I$(INC_DIR) -I$(LIBFT_DIR)
SRC_DIR = srcs
OBJ_DIR = obj
RM = rm -rf

SERVER_SRCS = \
	ft_server.c

CLIENT_SRCS = \
	ft_client.c

SERVER_SRC = $(addprefix $(SRC_DIR)/, $(SERVER_SRCS))
CLIENT_SRC = $(addprefix $(SRC_DIR)/, $(CLIENT_SRCS))

SERVER_OBJ = $(SERVER_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
CLIENT_OBJ = $(CLIENT_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: logo $(SERVER_NAME) $(CLIENT_NAME) 

$(LIBFT): | $(LIBFT_DIR)
		@$(MAKE) -C $(LIBFT_DIR)

$(SERVER_NAME):	$(SERVER_OBJ) $(LIBFT)
			@$(CC) $(CFLAGS) -o $@ $(SERVER_OBJ) $(LIBFT) $(INC)

$(CLIENT_NAME): $(CLIENT_OBJ) $(LIBFT)
			@$(CC) $(CFLAGS) -o $@ $(CLIENT_OBJ) $(LIBFT) $(INC)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
		@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) $(OBJ_DIR)
			@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
		@$(RM) $(SERVER_NAME) $(CLIENT_NAME)
		@$(MAKE) fclean -C $(LIBFT_DIR)

re:		fclean all

logo :
	@echo "\033[31m"
	@echo "                                                                 "
	@echo " _|      _|  _|            _|    _|                _|  _|        "
	@echo " _|_|  _|_|      _|_|_|        _|_|_|_|    _|_|_|  _|  _|  _|    "
	@echo " _|  _|  _|  _|  _|    _|  _|    _|      _|    _|  _|  _|_|      "
	@echo " _|      _|  _|  _|    _|  _|    _|      _|    _|  _|  _|  _|    "
	@echo " _|      _|  _|  _|    _|  _|      _|_|    _|_|_|  _|  _|    _|  "
	@echo "                                                                 "
	@echo "                                                                 "

.PHONY:	fclean re all clean logo
