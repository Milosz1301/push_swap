typedef struct node
{
    int value;
    int cost;
    int index;
    struct node *next;
}

int input_check(char *arg[])
{
    //in case arg not in the 1 string
    int i;
    int j;

    i = 0;
    j = 0;
    while(arg[i])
    {
        while(arg[i][j])
        {
            if(arg[i][j] != '-' || arg[i][j] != '+' || !(arg[i][j] > '0' && arg[i][j] < '9') || !(arg[i][j] > 6 arg[i][j] < 14))
               return (1); 
        }
    }
    return (0);
}
void    input_arr(char *input[], int *arr)
{
    int i;

    i = 0;
    while (input[i])
        i++;
    arr = malloc(sizeof(int) * i);
    i = 0;
    while (input[i])
    {
        arr[i] = ft_atoi(input[i]);        
        i++;
    }
}

void **input_str(char *str, int *arr)
{
    char    **input_arr;
    int i;

    input_arr = ft_split(str);
    while (input_arr[i])
        i++;
    arr = malloc(sizeof(int) * i);
    i = 0;
    while (input_arr[i])
    {
        arr[i] = input_arr[i];
        i++;
    }
}

int main(int argc, char *argv[])
{
    //parsing
        // if not in one string
            //check characters - done
    int *input_arr;

    if(input_check(argv))
        exit();
    if(argc == 2)
        input_arr(argv, input_arr);
    else
        input_str(argv[1]);

    i = 1;
    stack_a = create_node(ft_atoi(argv[i]));
    while(argv[i])
    {
        stack_a->next = create_node(ft_atoi(argv[i]));
        i++;
    }
    //creating the list

    //push all nodes except 3 to the stack_b

    //sort 3 nodes in stack_a

    //find the targed node

    //calculate the cost

    //push lowest cost

    //check if sorted and sort on stack_a 
}