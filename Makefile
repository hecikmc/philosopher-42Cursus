NAME		= philo

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

SRC			=   src/philosophers.c \
				src/utils.c \
				src/error.c \
				src/to_eat.c \
				src/to_death.c
				
OBJ_SRC		= $(SRC:.c=.o)

%.o: %.c
	@$(CC)$(FLAGS) -c $< -o $@

all:	$(NAME)

$(NAME)		: $(OBJ_SRC) 
	@$(CC) $(CFLAGS) $(OBJ_SRC) -o $(NAME)
	@echo "$(GREEN)$(NAME) -> program created! $(DEFAULT)"

clean		:
	@rm -f $(OBJ_SRC)
	@echo "$(YELLOW)$(NAME) -> Object files deleted. "

fclean		: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) program -> Program and objects files deleted. "

re			: fclean all

.PHONY		:
	all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m