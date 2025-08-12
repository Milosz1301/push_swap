void    push_l_cost(node *stack_b)
{
    node    *current;
    int cost;
    int len;
    int i;
 
    cost = current.cost;
    current = stack_b;
    current = current-> next;
    while(current)
    {
        if(current.cost <= cost)
            cost = current.cost;
        current = current->next;
    }
    len = 0;
    current = stack_b;
    while(current)
    {
        len++;
        current = current->next;
    }
    current = stack_b;
    i = 0;
    while(current.cost != cost)
    {
        i++;
        current = current->next;
    }
    if(i > len/2)
    {
        while(i != len/2 + 1)
        {
            rrb();
            i++;
        }
    }
    else
    {
        while(i + 1 != 0)
        {
            rb();
            i--;
        }
    }
}
