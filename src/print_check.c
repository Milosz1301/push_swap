/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstawski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:56:42 by mstawski          #+#    #+#             */
/*   Updated: 2025/08/31 14:02:06 by mstawski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	printlist_cost(t_node **stack)
{
	t_node	*current;

	current = *stack;
	while (current)
	{
		printf("%d\n", current->cost);
		current = current->next;
	}
}

void	printlist_adr(t_node **stack)
{
	t_node	*current;

	current = *stack;
	while (current)
	{
		printf("%p\n", current);
		current = current->next;
	}
}

void	printlist_t_adr(t_node **stack)
{
	t_node	*current;

	current = *stack;
	while (current)
	{
		printf("%p\n", current->target_address);
		current = current->next;
	}
}

void	printlist(t_node **stack)
{
	t_node	*current;

	current = *stack;
	while (current)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
}
