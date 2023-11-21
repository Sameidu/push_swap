/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:32:44 by smeixoei          #+#    #+#             */
/*   Updated: 2023/11/21 10:39:06 by smeixoei         ###   ########.fr       */
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
	// printf("Current: %p, Content: %d\n", current, current->content);
	// next = current->next;
    // printf("Next: %p, Content: %d\n", next, next->content);
    while (current && current != head)
    {
        printf("Current: %p, Content: %d\n", current, current->content);
        next = current->next;
        printf("Next: %p, Content: %d\n", next, next->content);
        while (next != head)
        {
            printf("Next: %p, Content: %d\n", next, next->content);
            if (current->content == next->content)
                ft_error("ERROR: Duplicate number");
            next = next->next;
        }
        current = current->next;
    }
}

t_stack	*ft_create_node(char *str, int i)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		ft_error("ERROR: Malloc failed");
	new->content = ft_atoi(str);
	new->index = i;
	new->next = NULL;
	new->past = NULL;
	return new;
}

t_stack	*ft_check(int argc, char **argv)
{
	int		i;
	t_stack	*stack;
	t_stack *new_node;

	i = 1;
	stack = NULL;
	while (i < argc)
	{
		ft_isnum(argv[i]);
		new_node = ft_create_node(argv[i], i);
		if (stack == NULL)
		{
			stack = new_node;
			stack->next = stack;
			stack->past = stack;
		}
		else
		{
			new_node->next = stack;
			new_node->past = stack->past;
			stack->past->next = new_node;
			stack->past = new_node;
		}
		i++;
	}
	printf("Final Stack: %p\n", stack);
		printf("Node: %p, Content: %d\n", stack, stack->content);
		printf("Node Next: %p, Content: %d\n", stack->next, stack->next->content);
		printf("Node Past: %p, Content: %d\n", stack->past, stack->past->content);
	ft_duplicate(&stack);
	return (stack);
}
