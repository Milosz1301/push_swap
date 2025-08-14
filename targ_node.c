//push all nodes except three to stack b
void	push_b(t_size *stack_a, t_size *stack_b)
{
	if (lst_size(stack_a) <= 3)
		sort_three(stack_a);
	else 
	{
		while (lst_size(stack) > 3)
			pb(stack_a, stack_b);
	}
}

node	*target_node(int value_a, stack stack_b)
{
	node	*current;
	int	min;
	int	temp;

	current = stack->head;
	min = current->value;
	current = current->next;
	while (current->next)
	{
		temp = current->value - value;
		if (tmp < min)
		{
			min = tmp;
			min_index = i;
		}
		current->index = i;
		i++;
	}
	while (stack->next)
	{
		if (stack->index == min_index)
			return (stack);
		stack = stack_b->next;
	}
	return (stack);
}

//sort three is done
void    sort_three(stack stack_a)
{
        if (stack_a->head->data < stack_a->head->link->data)
        {
                if (stack_a->head->data < stack_a->head->link->link->data)
                {
                        sa();
                        ra();
                }
                else
                        rra()
        }
        else
        {
                if (stack_a->head->data < stack_a->head->link->link->data)
                        sa();
                if (stack_a->head->link->data < stack_a->head->link->link->head)
                        ra();
                else
                {
                        sa();
                        rra();
                }
        }
}
