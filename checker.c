/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:32:44 by smeixoei          #+#    #+#             */
/*   Updated: 2023/11/20 11:00:40 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	ft_isnum(char *str)
{
	long	aux;
	char	*num;

	num = str;
	if (!str)
		ft_error("ERROR: Empty argument");
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		ft_error("ERROR: No number after sign");
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			ft_error("ERROR: Not a number");
		str++;
	}
	aux = ft_atoi(num);
	if (aux > INT_MAX || aux < INT_MIN)
		ft_error("ERROR: Number out of range");
}

void    ft_duplicate(t_stack **stack)
{
    t_stack *current;
    t_stack *next;
    t_stack *head;

    head = *stack;
    current = *stack;
    while (current)
    {
        printf("Current: %p, Content: %d\n", current, current->content);
        next = current->next;
        printf("Next: %p, Content: %d\n", next, next->content);
        while (next != current && next != head)
        {
            printf("Next: %p, Content: %d\n", next, next->content);
            if (current->content == next->content)
                ft_error("ERROR: Duplicate number");
            next = next->next;
        }
        current = current->next;
    }
}

t_stack	*ft_create_stack(char *str, t_stack **stack, int i)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		ft_error("ERROR: Malloc failed");
	new->content = ft_atoi(str);
	new->index = i;
	new->next = new;
	new->past = new;
	if (*stack == NULL)
		*stack = new;
	else
	{
		new->next = *stack;
		new->past = (*stack)->past;
		(*stack)->past->next = new;
		(*stack)->past = new;
	}
	return (new);
}

t_stack	*ft_check(int argc, char **argv)
{
	int		i;
	t_stack	*stack;

	i = 1;
	stack = NULL;
	while (i < argc)
	{
		ft_isnum(argv[i]);
		stack = ft_create_stack(argv[i], &stack, i);
		ft_push(&stack, &stack, 'a');
		i++;
	}
	ft_duplicate(&stack);
	return (stack);
}