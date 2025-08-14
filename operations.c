#include <stdio.h>
#include <stdlib.h>


typedef struct s_t_node
{
	int		data;
	int		cost;
	int		index;
	t_node	*prev;
	t_node	*next;
} t_node;

void	sa(t_node **node_a)
{
	t_node	*temp;

	if (!node_a)
		return ;	
	if (!*node_a)
		return ;
	if (!(*node_a)->next)
		return ;
	temp = (*node_a)->next;
	(*node_a)->next = (*node_a)->next->next;
	temp->next = *node_a;
	(*node_a) = temp;
	(*node_a)->prev = NULL;
	(*node_a)->next->prev = *node_a;
	if(! (*node_a)->next->next)
		(*node_a)->next->next->prev = (*node_a)->next;
}

void	sb(t_node **node_b)
{
	t_node	*temp;

	if (!node_b)
		return ;
	if (!*node_b)
		return ;
	if (!(*node_b)->next)
		return ;
	temp = (*node_b)->next;
	(*node_b)->next = (*node_b)->next->next;
	temp->next = *node_b;
	*node_b = temp;
	(*node_b)->prev = NULL;
	(*node_b)->next->prev = node_b
	if (!(*node_b)->next->next)
		(*node_b)->next->next->prev = (*node_b)->next;
}

void	ss(t_node **node_a, t_node **node_b)
{
	sa(node_a);
	sb(node_b);
}

void	pa(t_node **node_a, t_node **node_b)
{
	t_node	*temp;

	if (!node_b)
		return ;
	if (!*node_b)
		return ;
	temp = (*node_b)->next; 
	(*node_b)->next = *node_a;
	*node_a = *node_b;
	*node_b = temp;
	if(!(*node_a)->next)
		(*node_a)->next->prev = *node_a;
	if (!(*node_b)->next)
		(*node_b)->next->prev = *node_b;
}

void	pb(t_node **node_a, t_node **node_b)
{
	t_node	*temp;

	if (!node_a)
		return ;
	if (!*node_a)
		return ;
	temp = (*node_a)->next; 
	(*node_a)->next = *node_b;
	*node_b = *node_a;
	*node_a = temp;
	if(!(*node_a)->next)
		(*node_a)->next->prev = *node_a;
	if (!(*node_b)->next)
		(*node_b)->next->prev = *node_b;
}

void	ra(t_node **node_a)
{
	t_node	*temp;
	t_node	*current;

	if (!node_a)
		return ;
	if (!*node_a)
		return ;
	if (!(*node_a)->next)
		return ;
	temp = *node_a;
	current = temp;
	*node_a = (*node_a)->next;
	while (current->next->next)
		current = current->next;
	current->next->next = temp;
	temp->next = NULL;
	temp->prev = current->next;
	(*node_a)->prev = NULL;
}

void	rb(t_node **node_b)
{
	t_node	*temp;
	t_node	*current;

	if (!node_b)
		return ;
	if (!*node_b)
		return ;
	if (!(*node_b)->next)
		return ;
	temp = node_b;
	current = temp;
	*node_b = (*node_b)->next;
	while (current->next->next)
		current = current->next;
	current->next->next = temp;
	temp->next = NULL;
	temp->prev = current->next;
	(*node_b)->prev = NULL;
}

void	rr(t_node **node_a, t_node **node_b)
{
	ra(node_a);
	rb(node_b);
}

void	rra(t_node **node_a)
{
	t_node	*temp;
	t_node	*current;

	if (!node_a)
		return ;
	if (!*node_a)
		return ;
	if (!(*node_a)->next)
		return ;
	current = *node_a;
	while (current->next->next)
		current = current->next;
	temp = current->next;
	current->next = NULL;
	temp->next = *node_a;
	*node_a = temp;
	(*node_a)->next->prev = *node_a;
	(*node_a)->prev = NULL;
}

void	rrb(t_node **node_b)
{
	t_node	*temp;
	t_node	*current;

	if (!node_b)
		return ;
	if (!*node_b)
		return ;
	if (!(*node_b)->next)
		return ;
	current = *node_b;
	while (current->next->next)
		current = current->next;
	temp = current->next;
	current->next = NULL;
	temp->next = *node_b;
	*node_b = temp;
	(*node_b)->next->prev = *node_b;
	(*node_b)->prev = NULL;
}

void	rrr(t_node **node_a, t_node **node_b)
{
	rra(node_a);
	rrb(node_b);
}

t_node	*create_t_node(int value)
{
	t_node	*newt_node;

	newt_node = (t_node *)malloc(sizeof(t_node));
	newt_node->data = value;
	newt_node->next = NULL;
	return (newt_node);
}

void	printlist(t_node *list)
{
	t_node	*current;

	current = list;
	while (current)
	{
		printf("%d	",current->data);
		current = current->next;
	}
	printf("\n");
}

int	main(void)
{
	t_node	node_a;
	t_node	node_b;

	node_a.head = create_t_node(1);
	node_a.head->next = create_t_node(2);
	node_a.head->next->next = create_t_node(3);
	node_a.head->next->next->next = create_t_node(4);
	node_a.head->next->next->next->next = create_t_node(5);

	node_b.head = create_t_node(10);
	node_b.head->next = create_t_node(20);
	node_b.head->next->next = create_t_node(30);
	node_b.head->next->next->next = create_t_node(40);
	node_b.head->next->next->next->next = create_t_node(50);

	printf("node_a:\n");
	printlist(&node_a);
	printf("node_b:\n");
	printlist(&node_b);	
	sa(&node_a);
	printf("SA:\n");
	printlist(&node_a);
	printlist(&node_b);
	printf("SB:\n");
	sb(&node_b);
	printlist(&node_a);
	printlist(&node_b);
	printf("SS:\n");
	ss(&node_a, &node_b);
	printlist(&node_a);
	printlist(&node_b);
	printf("PA:\n");
	pa(&node_a, &node_b);
	printlist(&node_a);
	printlist(&node_b);
	printf("PB:\n");
	pb(&node_a, &node_b);
	printlist(&node_a);
	printlist(&node_b);
	printf("RA:\n");
	ra(&node_a);
	printlist(&node_a);
	printlist(&node_b);
	printf("RB:\n");
	rb(&node_b);
	printlist(&node_a);
	printlist(&node_b);
	printf("RR:\n");
	rr(&node_a, &node_b);
	printlist(&node_a);
	printlist(&node_b);
	printf("RRA:\n");
	rra(&node_a);
	printlist(&node_a);
	printlist(&node_b);
	printf("RRB:\n");
	rrb(&node_b);
	printlist(&node_a);
	printlist(&node_b);
	printf("RRR:\n");
	rrr(&node_a, &node_b);
	printlist(&node_a);
	printlist(&node_b);
}
