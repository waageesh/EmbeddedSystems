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

/* function prototypes for insert after/before given node, insert at nth pos, delete given element*/
status insert_after(sll** head, int data, int after_before_data);
status insert_before(sll** head, int data, int after_before_data);
status insert_nth(sll** head, int data, int pos);
status insert_node_last(sll** head, int data);
status delete_element(sll** head, int data);
status print_list(sll** head);

