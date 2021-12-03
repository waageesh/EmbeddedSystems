/*  struct for nodes in stack */
typedef struct
{
    int data; 
    struct stack_t* link;
} stack_t;

/* struct for return status of stack operations */
typedef enum
{
    STACK_FULL, 
    STACK_EMPTY,
    e_true,
    e_false
} status ;

/* function prototypes for stack operations  */
status push(stack_t** top, int data, int *cnt, int size);
status peep(stack_t** top);
status pop(stack_t** top, int* element);
status peek(stack_t** top, int* element);

