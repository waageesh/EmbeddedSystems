/* struct for return status of stack operations */
typedef enum status 
{
  e_success,
  e_failure,
} status ;

/* struct for stack to store characters  */
typedef struct
{
  unsigned int capacity;
  int top;
  char* item;
} stack_t ;

/* struct for stack to stored numbers */
typedef struct 
{
	unsigned int capacity;
	int* item;
	int top;
} numbers_stack;

/* stack modifying functions */
status create(stack_t* stack, int size);
status push(stack_t* stack, char* data);
status pop(stack_t* stack, char* element);
status peek(stack_t* stack, int* element);
status peep(stack_t* stack);
status free_stack(stack_t* stack);


/* stack empty/full status functions */
status stack_isempty(stack_t* stack);
status stack_isfull(stack_t* stack);

/* comparing operators precedence */
int char_precedence(char *ch1, char *ch2);

status infix_postfix_convertion(char* expr, stack_t* stack, char postfix_array[]);
status postfix_evaluation(char* postfix_array, int* result);
