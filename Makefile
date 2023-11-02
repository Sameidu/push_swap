NAME		=	push_swap
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g3 -fsanitize=address
LFT			=	libft/libft.a
OBJ			=	$(SRC:.c=.o)
SRC			=	push_swap.c\
				swap.c\
				push.c\
				rotate.c\
				utils.c\

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

all:		$(LFT) $(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(CFLAGS) -o $@ $^ $(LFT)
			@echo "$(COLOUR_GREEN) [ OK ] | Push Swap ready! $(COLOUR_END)"

$(LFT):		
			@echo "$(COLOUR_BLUE) [ ... ] | Compiling libft.. $(COLOUR_END)"
			@make -s -C libft
			@echo "$(COLOUR_GREEN) [ OK ] | Libft ready! $(COLOUR_END)"

$(OBJ): %.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ)
			@echo "$(COLOUR_RED)Object files removed. $(COLOUR_END)"

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)
			@echo "$(COLOUR_RED)Binary file removed. $(COLOUR_END)"

re:			fclean all

.PHONY:		all clean fclean re