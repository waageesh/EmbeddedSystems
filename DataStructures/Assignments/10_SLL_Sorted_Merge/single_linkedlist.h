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
status insert_node_last(sll** head, int data);
status print_list(sll** head);
status sort_list_nodes(sll** head);
void swap_nodes(sll** head, int num1, int num2);

status merge_list_sorted(sll** head1, sll** head2);
