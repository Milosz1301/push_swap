/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstawski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:57:44 by mstawski          #+#    #+#             */
/*   Updated: 2025/08/31 14:01:27 by mstawski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	find_min_cost(t_node **node_a, t_node **node_b)
{
	t_node	*current;
	int		min;

	current = *node_b;
	if (*node_b)
		min = current->cost;
	while (current)
	{
		if (min > current->cost)
			min = current->cost;
		current = current->next;
	}
	current = *node_b;
	while (current->cost != min)
		current = current->next;
	current->cost *= -1;
	select_vec(node_a, node_b);
}

void	cost_calc(t_node **node_a, t_node **node_b)
{
	int	*lowest_cost;
	int	a_cost;
	int	b_cost;
	int	ab_up_cost;
	int	ab_down_cost;

	a_cost = cost_a_up(node_a, node_b);
	b_cost = cost_b_up(node_a, node_b);
	ab_up_cost = cost_ab_up(node_a, node_b);
	ab_down_cost = cost_ab_down(node_a, node_b);
	lowest_cost = min_set_vec(a_cost, b_cost, ab_up_cost, ab_down_cost);
	(*node_b)->cost = lowest_cost[0];
	(*node_b)->vec = lowest_cost[1];
	free(lowest_cost);
}

void	target_node(t_node **node_a, t_node **node_b)
{
	t_node	*current;
	t_node	*closest;
	t_node	*min_node;

	current = *node_a;
	closest = NULL;
	min_node = NULL;
	while (current)
	{
		if (!min_node || current->data < min_node->data)
			min_node = current;
		if (current->data > (*node_b)->data)
		{
			if (!closest || current->data < closest->data)
				closest = current;
		}
		current = current->next;
	}
	if (closest)
		(*node_b)->target_address = closest;
	else
		(*node_b)->target_address = min_node;
}
