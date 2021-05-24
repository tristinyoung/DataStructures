  
  
  void grow_stack(struct stack *s, int increase)
  int * temp = malloc (sizeof(int) * (s->capacity + increase));

  if(temp != NULL)
  {
    for(int i =0; i<s->top; i++)
    {
        temp[i] = s->array[i];
    }
    free(stack-array);
    s->array = temp;
  }

  s->capacity = s->capacity+increase; // forgot to increase capacity

/////////////////////////////////////////////////////////////////



struct node
{
    int num;
    struct node* next;
};
