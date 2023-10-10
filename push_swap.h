#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				index;
	int				content;
	struct s_stak	*next;
	struct s_stack	*past;
}	t_stack;

void	ft_error(char *str);
void	ft_isnum(char *str);

#endif