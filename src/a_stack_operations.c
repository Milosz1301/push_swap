/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstawski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:05:58 by mstawski          #+#    #+#             */
/*   Updated: 2025/08/31 16:16:36 by mstawski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa(t_node **node_a)
{
	t_node	*temp;

	if (!node_a || !*node_a)
		return ;
	temp = (*node_a)->next;
	(*node_a)->next = temp->next;
	if (temp->next)
		temp->next->prev = *node_a;
	temp->next = *node_a;
	temp->prev = NULL;
	(*node_a)->prev = temp;
	*node_a = temp;
	write (1, "sa\n", 3);
}

void	pa(t_node **node_a, t_node **node_b)
{
	t_node	*temp;

	if (!node_b || !*node_b)
		return ;
	temp = (*node_b)->next;
	(*node_b)->next = *node_a;
	*node_a = *node_b;
	*node_b = temp;
	if ((*node_a)->next)
		(*node_a)->next->prev = *node_a;
	if (*node_b)
		(*node_b)->prev = NULL;
	write (1, "pa\n", 3);
}

void	ra(t_node **node_a, bool print)
{
	t_node	*temp;
	t_node	*current;

	if (!node_a || !*node_a)
		return ;
	temp = *node_a;
	*node_a = (*node_a)->next;
	(*node_a)->prev = NULL;
	current = *node_a;
	while (current->next)
		current = current->next;
	current->next = temp;
	temp->prev = current;
	temp->next = NULL;
	if (print)
		write (1, "ra\n", 3);
}

void	rra(t_node **node_a, bool print)
{
	t_node	*temp;
	t_node	*current;

	if (!node_a || !*node_a || !(*node_a)->next)
		return ;
	current = *node_a;
	while (current->next->next)
		current = current->next;
	temp = current->next;
	current->next = NULL;
	temp->next = *node_a;
	temp->prev = NULL;
	(*node_a)->prev = temp;
	*node_a = temp;
	if (print)
		write (1, "rra\n", 4);
}
