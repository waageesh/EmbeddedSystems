/* struct for node in linkedlist  */
typedef struct node
{
	int data;
	struct node* link;
} sll;

/* struct for return status of linkedlist operations*/
typedef enum
{
    e_success,
    e_failure,
    EMPTY_LIST,
    DATA_FOUND,
    DATA_NOT_FOUND
} status ;

/* function prototypes for insert after given node, remove duplicates for linkedlist*/
status insert_node_last(sll** head, int data);
status reverse_list_iterative(sll** head);
sll* reverse_list_recursive(sll** head);
status print_list(sll** head);

