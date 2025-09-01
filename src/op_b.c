/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstawski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:06:09 by mstawski          #+#    #+#             */
/*   Updated: 2025/08/31 16:17:27 by mstawski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sb(t_node **node_b)
{
	t_node	*temp;

	if (!node_b || !*node_b)
		return ;
	temp = (*node_b)->next;
	(*node_b)->next = temp->next;
	if (temp->next)
		temp->next->prev = *node_b;
	temp->next = *node_b;
	temp->prev = NULL;
	(*node_b)->prev = temp;
	*node_b = temp;
	write(1, "sb\n", 3);
}

void	pb(t_node **node_a, t_node **node_b)
{
	t_node	*temp;

	if (!node_a || !*node_a)
		return ;
	temp = (*node_a)->next;
	(*node_a)->next = *node_b;
	if (*node_b)
		(*node_b)->prev = *node_a;
	*node_b = *node_a;
	*node_a = temp;
	(*node_b)->prev = NULL;
	if (*node_a)
		(*node_a)->prev = NULL;
	write(1, "pb\n", 3);
}

void	rb(t_node **node_b, bool print)
{
	t_node	*temp;
	t_node	*current;

	if (!node_b || !*node_b)
		return ;
	temp = *node_b;
	*node_b = (*node_b)->next;
	(*node_b)->prev = NULL;
	current = *node_b;
	while (current->next)
		current = current->next;
	current->next = temp;
	temp->prev = current;
	temp->next = NULL;
	if (print)
		write(1, "rb\n", 3);
}

void	rrb(t_node **node_b, bool print)
{
	t_node	*temp;
	t_node	*current;

	if (!node_b || !*node_b || !(*node_b)->next)
		return ;
	current = *node_b;
	while (current->next->next)
		current = current->next;
	temp = current->next;
	current->next = NULL;
	temp->next = *node_b;
	temp->prev = NULL;
	(*node_b)->prev = temp;
	*node_b = temp;
	if (print)
		write(1, "rrb\n", 4);
}
