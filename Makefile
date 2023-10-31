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

				

all:		$(MLX) $(LFT) $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(LFT):		
			@echo " [ .. ] | Compiling libft.."
			@make -s -C libft
			@echo " [ OK ] | Libft ready!"

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ)
			@echo "object files removed."

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)
			@echo "binary file removed."

re:			fclean all

.PHONY:		all clean fclean re