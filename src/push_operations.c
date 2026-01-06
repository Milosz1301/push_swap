/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstawski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:09:56 by mstawski          #+#    #+#             */
/*   Updated: 2025/08/31 16:14:38 by mstawski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	select_vec(t_node **node_a, t_node **node_b)
{
	t_node	*current;

	current = *node_b;
	while (current->cost > 0)
		current = current->next;
	if (current->vec == 1)
		ab_up_push(node_a, node_b);
	else if (current->vec == 2)
		ab_down_push(node_a, node_b);
	else if (current->vec == 3)
		a_up_push(node_a, node_b);
	else
		b_up_push(node_a, node_b);
}

void	ab_up_push(t_node **node_a, t_node **node_b)
{
	t_node	*cur;

	cur = *node_b;
	while (cur->cost > 0)
		cur = cur->next;
	while (*node_a != cur->target_address && (*node_b)->cost != cur->cost)
		rr(node_a, node_b);
	while (*node_a != cur->target_address)
		ra(node_a, true);
	while ((*node_b)->cost != cur->cost)
		rb(node_b, true);
	if ((*node_b)->cost == cur->cost)
		pa(node_a, node_b);
}

void	ab_down_push(t_node **node_a, t_node **node_b)
{
	t_node	*cur;

	cur = *node_b;
	while (cur->cost > 0)
		cur = cur->next;
	while (*node_a != cur->target_address && (*node_b)->cost != cur->cost)
		rrr(node_a, node_b);
	while (*node_a != cur->target_address)
		rra(node_a, true);
	while ((*node_b)->cost != cur->cost)
		rrb(node_b, true);
	if ((*node_b)->cost == cur->cost)
		pa(node_a, node_b);
}

void	a_up_push(t_node **node_a, t_node **node_b)
{
	t_node	*current;

	current = *node_b;
	while (current->cost > 0)
		current = current->next;
	while (*node_a != current->target_address)
		ra(node_a, true);
	while ((*node_b)->cost != current->cost)
		rrb(node_b, true);
	if ((*node_b)->cost == current->cost)
		pa(node_a, node_b);
}

void	b_up_push(t_node **node_a, t_node **node_b)
{
	t_node	*current;

	current = *node_b;
	while (current->cost > 0)
		current = current->next;
	while (*node_a != current->target_address)
		rra(node_a, true);
	while ((*node_b)->cost != current->cost)
		rb(node_b, true);
	if ((*node_b)->cost == current->cost)
		pa(node_a, node_b);
}
