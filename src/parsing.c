/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstawski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:06:23 by mstawski          #+#    #+#             */
/*   Updated: 2025/09/01 12:13:12 by mstawski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	create_stack_arg(char **input, t_node **stack_a)
{
	t_node	*current;
	int		trim;

	*stack_a = create_tnode(ft_atoi(input[1]));
	(*stack_a)->prev = NULL;
	current = *stack_a;
	trim = trym(input[1]);
	while (input[1][trim])
	{
		current->next = (create_tnode(ft_atoi(input[1] + trim)));
		current->next->prev = current;
		trim += trym(input[1] + trim);
		current = current->next;
	}
}

void	create_stack_args(char **input, t_node **stack_a)
{
	t_node	*current;
	int		i;

	i = 1;
	*stack_a = create_tnode(ft_atoi(input[i++]));
	(*stack_a)->prev = NULL;
	current = *stack_a;
	while (input[i])
	{
		current->next = (create_tnode(ft_atoi(input[i])));
		current->next->prev = current;
		current = current->next;
		i++;
	}
}

void	pars_args(char **input)
{
	int	i;
	int	j;

	i = 0;
	while (input[++i])
	{
		j = -1;
		while (input[i][++j])
		{
			if (!(input[i][j] > 47 && input[i][j] < 58) && input[i][j] != 45)
				exit_with_error();
			if (input[i][j] == 45)
			{
				if (!input[i][j + 1])
					exit_with_error();
				if (input[i][j + 1] && !(is_digit(input[i][j + 1])))
					exit_with_error();
			}
		}
	}
}

void	pars_arg(char **input)
{
	char	*str;
	int		i;

	str = input[1];
	i = -1;
	while (str[++i])
	{
		if (!is_digit(str[i]) && !(is_white(str[i])) && str[i] != 45)
			exit_with_error();
		if (is_white(str[i]))
		{
			if (str[i + 1] && !(is_digit(str[i + 1])) && str[i + 1] != 45)
				exit_with_error();
		}
		if (str[i] == 45)
		{
			if (str[i + 1] && !(is_digit(str[i + 1])))
				exit_with_error();
		}
	}
}

void	check_dup(t_node **stack)
{
	t_node	*current;
	t_node	*cur2;

	current = *stack;
	while (current->next)
	{
		cur2 = current->next;
		while (cur2)
		{
			if (cur2->data == current->data)
			{
				free_stack(stack);
				exit_with_error();
			}
			cur2 = cur2->next;
		}
		current = current->next;
	}
}
