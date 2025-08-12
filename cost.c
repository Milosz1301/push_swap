//funtion to calculate the cost and set the cost field in the node

void    cost(node target_node, node match_node, node stack_a, node_stack_b)
{
    int cost;
    int len_a;
    int len_b;
    int i;
    int j;
   
    cost = 0;
    len_a = list_len(stack_a);
    len_b = list_len(stack_b);
    i = 0;
    while(stack_a != target_node)
    {
        stack_a = stack_a->next;
        i++;
    }
    j = 0;
    while(stack_b != match_node)
    {
        stack_b = stack_b->next;
        j = 0;
    }
    if(i >= len_a/2 && j >= len_b/2)
    {
        while(i != len_a + 1 || j != len_b + 1)
        {
            rrr();
            cost++;
            i++;
            j++;
        }
        if(i == len_a + 1)
        {
            while(j != len_b + 1)
            {
                cost++;
                rrb();
                j++;
            }
        }
        else
        {
            while(i != len_a + 1)
            {
                cost++;
                rra();
                i++;
            }
        }
    match_node.cost = cost;
    return ;
    }
    if (i <= len_a/2 && j <= len_b/2)
    {
        while(i + 1 != 0 || j + 1 != 0)
        {
            cost++;
            rr();
            i--;
            j--;
        }
        if(i + 1 == 0)
        {
            while(j + 1 != 0)
            {
                cost++;
                rb();
                j--;
            }
        }
        else
        {
            while(i + 1 != 0)
            {
                cost++;
                ra();
                i--;
            }
        }
        match_node.cost = cost;
        return;
    }
    if(i >= len_a/2 && j <= len_b/2)
    {
        while(i != len_a + 1)
        {
            rra();
            cost++;
            i++;
        }
        while(j + 1 != 0)
        {
            j--;
            cost++;
            rb();
        }
        match_node.cost = cost;
        return ;
    }
    else
    {
        while(i + 1 != 0)
        {
            i--;
            cost++;
            ra();
        }
        while(j != len_b/2 + 1)
        {
            j++;
            cost++;
            rrb();
        }
    match_node.cost = cost;
    return ;
    } 
} 