/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ab.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstawski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:05:47 by mstawski          #+#    #+#             */
/*   Updated: 2025/08/31 16:16:59 by mstawski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ss(t_node **node_a, t_node **node_b)
{
	sa(node_a);
	sb(node_b);
	write(1, "ss\n", 3);
}

void	rr(t_node **node_a, t_node **node_b)
{
	ra(node_a, false);
	rb(node_b, false);
	write(1, "rr\n", 3);
}

void	rrr(t_node **node_a, t_node **node_b)
{
	rra(node_a, false);
	rrb(node_b, false);
	write(1, "rrr\n", 4);
}
