/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstawski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:22:20 by mstawski          #+#    #+#             */
/*   Updated: 2025/08/31 16:18:00 by mstawski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	is_sorted(t_node **stack_a)
{
	t_node	*cur;

	cur = *stack_a;
	while (cur && cur->next)
	{
		if (cur->data > cur->next->data)
			return ;
		cur = cur->next;
	}
	exit(2);
}

void	check_stack_a(t_node **stack_a)
{
	t_node	*current;
	int		min;
	int		len;
	int		i;

	len = listsize(*stack_a);
	i = 0;
	current = *stack_a;
	min = current->data;
	while (current)
	{
		if (current->data < min)
			min = current->data;
		current = current->next;
	}
	current = *stack_a;
	while (current->data != min)
	{
		current = current->next;
		i++;
	}
	last_touch(stack_a, min, i, len);
}

void	last_touch(t_node **stack_a, int min, int i, int len)
{
	if (i <= len / 2)
	{
		while ((*stack_a)->data != min)
			ra(stack_a, true);
	}
	else
	{
		while ((*stack_a)->data != min)
			rra(stack_a, true);
	}
}

t_node	*create_tnode(int value)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
		return (NULL);
	newnode->prev = NULL;
	newnode->data = value;
	newnode->cost = 0;
	newnode->vec = 0;
	newnode->next = NULL;
	return (newnode);
}

void	create_stack(char **input, t_node **stack_a)
{
	t_node	*current;
	int		i;

	i = 1;
	current = *stack_a;
	*stack_a = create_tnode(ft_atoi(input[i]));
	(*stack_a)->prev = NULL;
	while (input[++i])
	{
		current->next = (create_tnode(ft_atoi(input[i])));
		current->next->prev = current;
		current = current->next;
	}
}
