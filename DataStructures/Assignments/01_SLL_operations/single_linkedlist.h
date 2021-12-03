/* struct for linkedlist nodes  */
typedef struct
{
	int data;
	struct sll* link;
} sll;

/* struct for return status of each function  */
typedef enum
{
    e_success,
    e_failure,
    EMPTY_LIST,
    DATA_FOUND,
    DATA_NOT_FOUND
} status ;

/* function prototypes for inserting at first,last and deleting first,last and deleting entire list  */
status insert_node_first(sll** head, int data);
status insert_node_last(sll** head, int data);

status delete_node_first(sll** head);
status delete_node_last(sll** head);
status delete_list(sll** head);

status find_node(sll** head, int data);
status print_list(sll** head);

