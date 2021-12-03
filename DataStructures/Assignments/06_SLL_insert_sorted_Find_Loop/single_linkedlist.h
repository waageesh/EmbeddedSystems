/* struct for linkedlist nodes  */
typedef struct node
{
	int data;
	struct node* link;
} sll;

/* struct for return status of each function  */
typedef enum
{
    e_success,
    e_failure,
    EMPTY_LIST,
    SINGLE_NODE_LIST,
    LOOP_FOUND,
    LOOP_NOT_FOUND
} status ;

/* function prototypes for inserting at first,last and deleting first,last and deleting entire list  */
status insert_sorted(sll** head, int data);
status find_loop(sll** head);
status print_list(sll** head);
status create_loop(sll** head, int k);

