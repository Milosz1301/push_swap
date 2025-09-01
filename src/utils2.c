/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstawski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:55:16 by mstawski          #+#    #+#             */
/*   Updated: 2025/08/31 14:02:34 by mstawski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

bool	sorted_list(t_node **stack_a, t_node **stack_b)
{
	t_node	*current;

	current = *stack_a;
	if (*stack_b)
		return (true);
	while (current->next)
	{
		if (current->data > current->next->data)
			return (true);
		current = current->next;
	}
	return (false);
}

void	exit_with_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_node **head)
{
	t_node	*tmp;

	if (!head || !(*head))
		return ;
	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
	*head = NULL;
}
