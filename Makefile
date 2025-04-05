#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

.PHONY: all clean fclean re

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
Thread = -fsanitize=thread
Memory = -fsanitize=memory
Address = -fsanitize=address
Thread_Flag = -pthread
RM = rm -rf

# Output file name
NAME = philo

# Directories
SRC_DIR = src
SRC_DIRS = $(SRC_DIR) \
			$(SRC_DIR)/parsing \
			$(SRC_DIR)/utils \
			# $(SRC_DIR)/testcases

OBJ_DIR = obj
INC_DIR = inc

SRC = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

# Generates output file
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
