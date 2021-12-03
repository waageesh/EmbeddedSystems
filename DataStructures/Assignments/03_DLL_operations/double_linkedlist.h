/* struct for linkedlist nodes  */
typedef struct
{
	int data;
	struct dll* link;
	struct dll* prev;
} dll;

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
status insert_node_first(dll** head, dll** tail, int data);
status insert_node_last(dll** head, dll** tail, int data);

status delete_node_first(dll** head, dll** tail);
status delete_node_last(dll** head, dll** tail);
status delete_list(dll** head, dll** tail);

status print_list(dll** head);

