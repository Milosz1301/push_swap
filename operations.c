#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int		data;
	struct node	*link;
} node;

typedef struct	linkedlist 
{
	node	*head;
} stack;

void	sa(stack *stack_a)
{
	node	*temp;

	if (!stack_a->head)
		return ;
	if (!stack_a->head->link)
		return ;
	temp = stack_a->head->link;
	stack_a->head->link = stack_a->head->link->link;
	temp->link = stack_a->head;
	stack_a->head = temp;
}

void	sb(stack *stack_b)
{
	node	*temp;

	if (!stack_b->head)
		return ;
	if (!stack_b->head->link)
		return ;
	temp = stack_b->head->link;
	stack_b->head->link = stack_b->head->link->link;
	temp->link = stack_b->head;
	stack_b->head = temp;
}

void	ss(stack *stack_a, stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pa(stack *stack_a, stack *stack_b)
{
	node	*temp;

	if (!stack_b->head)
		return ;
	temp = stack_b->head->link; 
	stack_b->head->link = stack_a->head;
	stack_a->head = stack_b->head;
	stack_b->head = temp;
}

void	pb(stack *stack_a, stack *stack_b)
{
	node	*temp;

	if (!stack_a->head)
		return ;
	temp = stack_a->head->link; 
	stack_a->head->link = stack_b->head;
	stack_b->head = stack_a->head;
	stack_a->head = temp;
}

void	ra(stack *stack_a)
{
	node	*temp;
	node	*current;

	if (!stack_a->head)
		return ;
	if (!stack_a->head->link)
		return ;
	temp = stack_a->head;
	current = temp;
	stack_a->head = stack_a->head->link;
	while (current->link)
		current = current->link;
	current->link = temp;
	temp->link = NULL;
}

void	rb(stack *stack_b)
{
	nod	*temp;
	node	*current;

	if (!stack_b->head)
		return ;
	if (!stack_b->head->link)
		return ;
	temp = stack_b->head;
	current = temp;
	stack_b->head = stack_b->head->link;
	while (current->link)
		current = current->link;
	current->link = temp;
	temp->link = NULL;
}

void	rr(stack *stack_a, stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rra(stack *stack_a)
{
	node	*temp;
	node	*current;

	if (!stack_a->head)
		return ;
	if (!stack_a->head->link)
		return ;
	current = stack_a->head;
	while (current->link->link)
		current = current->link;
	temp = current->link;
	current->link = NULL;
	temp->link = stack_a->head;
	stack_a->head = temp;
}

void	rrb(stack *stack_b)
{
	node	*temp;
	node	*current;

	if (!stack_b->head)
		return ;
	if (!stack_b->head->link)
		return ;
	current = stack_b->head;
	while (current->link->link)
		current = current->link;
	temp = current->link;
	current->link = NULL;
	temp->link = stack_b->head;
	stack_b->head = temp;
}

void	rrr(stack *stack_a, stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

node	*create_node(int value)
{
	node	*newnode;

	newnode = (node *)malloc(sizeof(node));
	newnode->data = value;
	newnode->link = NULL;
	return (newnode);
}

void	printlist(stack *list)
{
	node	*current;

	current = list->head;
	while (current)
	{
		printf("%d	",current->data);
		current = current->link;
	}
	printf("\n");
}

int	main(void)
{
	stack	stack_a;
	stack	stack_b;

	stack_a.head = create_node(1);
	stack_a.head->link = create_node(2);
	stack_a.head->link->link = create_node(3);
	stack_a.head->link->link->link = create_node(4);
	stack_a.head->link->link->link->link = create_node(5);

	stack_b.head = create_node(10);
	stack_b.head->link = create_node(20);
	stack_b.head->link->link = create_node(30);
	stack_b.head->link->link->link = create_node(40);
	stack_b.head->link->link->link->link = create_node(50);

	printf("Stack_a:\n");
	printlist(&stack_a);
	printf("Stack_b:\n");
	printlist(&stack_b);	
	sa(&stack_a);
	printf("SA:\n");
	printlist(&stack_a);
	printlist(&stack_b);
	printf("SB:\n");
	sb(&stack_b);
	printlist(&stack_a);
	printlist(&stack_b);
	printf("SS:\n");
	ss(&stack_a, &stack_b);
	printlist(&stack_a);
	printlist(&stack_b);
	printf("PA:\n");
	pa(&stack_a, &stack_b);
	printlist(&stack_a);
	printlist(&stack_b);
	printf("PB:\n");
	pb(&stack_a, &stack_b);
	printlist(&stack_a);
	printlist(&stack_b);
	printf("RA:\n");
	ra(&stack_a);
	printlist(&stack_a);
	printlist(&stack_b);
	printf("RB:\n");
	rb(&stack_b);
	printlist(&stack_a);
	printlist(&stack_b);
	printf("RR:\n");
	rr(&stack_a, &stack_b);
	printlist(&stack_a);
	printlist(&stack_b);
	printf("RRA:\n");
	rra(&stack_a);
	printlist(&stack_a);
	printlist(&stack_b);
	printf("RRB:\n");
	rrb(&stack_b);
	printlist(&stack_a);
	printlist(&stack_b);
	printf("RRR:\n");
	rrr(&stack_a, &stack_b);
	printlist(&stack_a);
	printlist(&stack_b);
}
