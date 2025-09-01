/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstawski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:02:08 by mstawski          #+#    #+#             */
/*   Updated: 2025/08/31 16:15:45 by mstawski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_node
{
	int					data;
	int					cost;
	int					vec;
	struct s_node		*target_address;
	struct s_node		*prev;
	struct s_node		*next;
}	t_node;

//	operations
void	sa(t_node **node_a);
void	sb(t_node **node_b);
void	ss(t_node **node_a, t_node **node_b);
void	pa(t_node **node_a, t_node **node_b);
void	pb(t_node **node_a, t_node **node_b);
void	ra(t_node **node_a, bool print);
void	rb(t_node **node_b, bool print);
void	rr(t_node **node_a, t_node **node_b);
void	rra(t_node **node_a, bool print);
void	rrb(t_node **node_b, bool print);
void	rrr(t_node **node_a, t_node **node_b);

//	utils
int		is_white(char c);
int		is_digit(char c);
int		listsize(t_node *list);
int		ft_atoi(const char *nptr);
int		trym(const char *nptr);
t_node	*create_tnode(int value);
void	exit_with_error(void);
void	free_stack(t_node **head);

//	print (check)
void	printlist(t_node **stack);
void	printlist_t_adr(t_node **stack);
void	printlist_adr(t_node **stack);
void	printlist_cost(t_node **stack);

//	parsing
void	parsing(int argc, char **argv, t_node **stack_a);
void	pars_arg(char **input);
void	pars_args(char **input);
void	create_stack_arg(char **input, t_node **stack_a);
void	create_stack_args(char **input, t_node **stack_a);
void	check_dup(t_node **stack);
void	is_sorted(t_node **stack_a);

//	sort algorithm
void	push_2b(t_node **stack_a, t_node **stack_b);
void	sort_three(t_node **stack_a);

//	turk algorithm
void	turk_algorithm(t_node **stack_a, t_node **stack_b);
bool	sorted_list(t_node **stack_a, t_node **stack_b);
void	target_node(t_node **node_a, t_node **node_b);
void	cost_calc(t_node **node_a, t_node **node_b);
int		cost_ab_up(t_node **node_a, t_node **node_b);
int		cost_ab_down(t_node **node_a, t_node **node_b);
int		cost_a_up(t_node **node_a, t_node **node_b);
int		cost_b_up(t_node **node_a, t_node **node_b);
int		*min_set_vec(int cost_a, int cost_b, int cost_ab_up, int cost_ab_down);
void	find_min_cost(t_node **node_a, t_node **node_b);
void	select_vec(t_node **node_a, t_node **node_b);
void	ab_up_push(t_node **node_a, t_node **node_b);
void	ab_down_push(t_node **node_a, t_node **node_b);
void	a_up_push(t_node **node_a, t_node **node_b);
void	b_up_push(t_node **node_a, t_node **node_b);

//	polish
void	check_stack_a(t_node **stack_a);
void	last_touch(t_node **stack_a, int min, int i, int len);

#endif
