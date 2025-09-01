/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstawski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:10:30 by mstawski          #+#    #+#             */
/*   Updated: 2025/08/31 14:53:00 by mstawski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_white(char c)
{
	return ((c > 6 && c < 14) || c == 32);
}

int	is_digit(char c)
{
	return (c > 47 && c < 58);
}

int	ft_atoi(const char *nptr)
{
	long long	numb;
	int			sign;

	numb = 0;
	sign = 0;
	while ((*nptr > 6 && *nptr < 14) || *nptr == 32)
		nptr++;
	if (*nptr == 43 || *nptr == 45)
		sign += *(nptr++);
	while (*nptr > 47 && *nptr < 58)
		numb = numb * 10 + (*(nptr++) - 48);
	if (sign == 45)
		numb *= (-1);
	if (numb > 2147483647 || numb < -2147483648)
		exit_with_error();
	return ((int)numb);
}

int	trym(const char *nptr)
{
	int	i;

	i = 0;
	while ((nptr[i] > 6 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
		i++;
	while (nptr[i] > 47 && nptr[i] < 58)
		i++;
	return (i);
}

int	listsize(t_node *list)
{
	int	size;

	size = 0;
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}
