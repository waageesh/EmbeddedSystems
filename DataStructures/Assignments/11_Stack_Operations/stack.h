/* struct for return status of stack operations */
typedef enum status 
{
  e_true,
  e_false
} status ;

/* struct for stack using static array  */
typedef struct
{
  unsigned int capacity;
  int top;
  int* item;
} stack_t ;

/* stack modifying functions */
status create(stack_t* stack, int size);
status push(stack_t* stack, int data);
status pop(stack_t* stack, int* element);
status peek(stack_t* stack, int* element);
status peep(stack_t* stack);
status free_stack(stack_t* stack);


/* stack empty/full status functions */
status stack_isempty(stack_t* stack);
status stack_isfull(stack_t* stack);
