# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joyim <joyim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/31 22:50:22 by joyim             #+#    #+#              #
#    Updated: 2025/04/04 20:28:02 by joyim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC_DIR = src
SRC_DIRS = $(SRC_DIR) \
			$(SRC_DIR)/parsing \
			$(SRC_DIR)/utils \
			# $(SRC_DIR)/testcases

OBJ_DIR = obj
INC_DIR = inc

SRC = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

CC = cc -pthread
CFLAGS = -g3 $(test)
test = -Wall -Werror -Wextra -fsanitize=address
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Create .o from .c file, store all object files in obj directory
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Create object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re