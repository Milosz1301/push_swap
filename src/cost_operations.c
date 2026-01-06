/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstawski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:50:40 by mstawski          #+#    #+#             */
/*   Updated: 2025/08/31 14:01:19 by mstawski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	cost_ab_up(t_node **node_a, t_node **node_b)
{
	t_node	*cur_a;
	t_node	*cur_b;
	int		cost;

	cur_a = *node_a;
	cur_b = *node_b;
	cost = 0;
	while (cur_a->prev && cur_b->prev)
	{
		cost++;
		cur_a = cur_a->prev;
		cur_b = cur_b->prev;
	}
	while (cur_a->prev)
	{
		cost++;
		cur_a = cur_a->prev;
	}
	while (cur_b->prev)
	{
		cost++;
		cur_b = cur_b->prev;
	}
	return (cost);
}

int	cost_ab_down(t_node **node_a, t_node **node_b)
{
	t_node	*cur_a;
	t_node	*cur_b;
	int		cost;

	cur_a = *node_a;
	cur_b = *node_b;
	cost = 0;
	while (cur_a->next && cur_b->next)
	{
		cost++;
		cur_a = cur_a->next;
		cur_b = cur_b->next;
	}
	while (cur_a->next)
	{
		cost++;
		cur_a = cur_a->next;
	}
	while (cur_b->next)
	{
		cost++;
		cur_b = cur_b->next;
	}
	return (++cost);
}

int	cost_b_up(t_node **node_a, t_node **node_b)
{
	t_node	*cur_a;
	t_node	*cur_b;
	int		cost;

	cur_a = *node_a;
	cur_b = *node_b;
	cost = 0;
	while (cur_a->next)
	{
		cost++;
		cur_a = cur_a->next;
	}
	cost++;
	while (cur_b->prev)
	{
		cost++;
		cur_b = cur_b->prev;
	}
	return (cost);
}

int	cost_a_up(t_node **node_a, t_node **node_b)
{
	t_node	*cur_a;
	t_node	*cur_b;
	int		cost;

	cur_a = *node_a;
	cur_b = *node_b;
	cost = 0;
	while (cur_a->prev)
	{
		cost++;
		cur_a = cur_a->prev;
	}
	while (cur_b->next)
	{
		cost++;
		cur_b = cur_b->next;
	}
	cost++;
	return (cost);
}

int	*min_set_vec(int cost_a, int cost_b, int cost_ab_up, int cost_ab_down)
{
	int	*lowest_cost;

	lowest_cost = malloc(sizeof(int) * 2);
	lowest_cost[0] = cost_a;
	lowest_cost[1] = 3;
	if (cost_b < lowest_cost[0])
	{
		lowest_cost[0] = cost_b;
		lowest_cost[1] = 4;
	}
	if (cost_ab_up < lowest_cost[0])
	{
		lowest_cost[0] = cost_ab_up;
		lowest_cost[1] = 1;
	}
	if (cost_ab_down < lowest_cost[0])
	{
		lowest_cost[0] = cost_ab_down;
		lowest_cost[1] = 2;
	}
	return (lowest_cost);
}
