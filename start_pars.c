#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

typedef struct node
{
	int		data;
	struct node	*link;
} node;

typedef struct linkedlist
{
	node	*head;
} stack;

void    printlist(stack *list);

node	*create_node(int value)
{
	node	*newnode;

	newnode = (node *)malloc(sizeof(node));
	if (!newnode)
		return (NULL);
	newnode->data = value;
	newnode->link = NULL;
	return (newnode);
}

stack	*create_stack_a(char **input, stack *stack_a)
{
	node	*current;
	int	i;

	stack_a->head = create_node(ft_atoi(input[0]));
	current = stack_a->head;
	i = 0;
	while (input[++i])
	{
		current->link = (create_node(ft_atoi(input[i])));
		current = current->link;
	}
	return (stack_a);
}

void	check_input(char **input) //if input is not one string
{
	int	i;
	int	j;

	i = -1;
	while (input[++i])
	{
		j = -1;
		while (input[i][++j])
		{
			
			if (!(input[i][j] > 47 && input[i][j] < 58) && input[i][j] != 45) 
			{
				printf("!!!!!!!!!!!!!!");
				exit(2);
			}
			if (input[i][j] == 45)
			{
				if (!input[i][j + 1])
					exit(4);
				if (input[i][j + 1] && !(ft_isdigit(input[i][j + 1])))
					exit(3);
			}
		}
	}
}

void	printlist(stack *list)
{
	node	*current;

	current = list->head;
	while (current)
	{
		printf("%d\n", current->data);
		current = current->link;
	}
}

int	main(int argc, char *argv[])
{
	stack	stack_a;
	stack	stack_b;

	if (argc < 2)
		exit(1);
	check_input(++argv);
	create_stack_a(argv, &stack_a);
	printlist(&stack_a);
	return (0);
}
