/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstawski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:42:39 by mstawski          #+#    #+#             */
/*   Updated: 2025/08/31 16:18:37 by mstawski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	turk_algorithm(t_node **stack_a, t_node **stack_b)
{
	t_node	*node_b;

	push_2b(stack_a, stack_b);
	while (sorted_list(stack_a, stack_b))
	{
		if (!*stack_b)
			break ;
		node_b = *stack_b;
		while (node_b)
		{
			target_node(stack_a, &node_b);
			node_b = node_b->next;
		}
		node_b = *stack_b;
		while (node_b)
		{
			cost_calc(&node_b->target_address, &node_b);
			node_b = node_b->next;
		}
		find_min_cost(stack_a, stack_b);
	}
}

void	parsing(int argc, char **argv, t_node **stack_a)
{
	if (argc == 2)
	{
		pars_arg(argv);
		create_stack_arg(argv, stack_a);
	}
	else if (argc > 2)
	{
		pars_args(argv);
		create_stack_args(argv, stack_a);
	}
	check_dup(stack_a);
	is_sorted(stack_a);
}

void	push_2b(t_node **stack_a, t_node **stack_b)
{
	int	i;

	i = listsize(*stack_a);
	if (i == 1)
		return ;
	if (i <= 3)
		sort_three(stack_a);
	else
	{
		while (i > 3)
		{
			pb(stack_a, stack_b);
			i--;
		}
		sort_three(stack_a);
	}
}

void	sort_three(t_node **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (!(*stack_a)->next->next)
		return ;
	a = (*stack_a)->data;
	b = (*stack_a)->next->data;
	c = (*stack_a)->next->next->data;
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a, true);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a, true);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a, true);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a, true);
}
