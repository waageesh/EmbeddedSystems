/* struct for nodes in linkedlist  */
typedef struct
{
	int data;
	struct sll* link;
} sll;

/* struct for return status of linkedlist operations  */
typedef enum
{
    e_success,
    e_failure,
    EMPTY_LIST,
    DATA_FOUND,
    DATA_NOT_FOUND
} status ;

/* function prototypes for finding mid element, getting nth last node
 * and inserting node at last in single linkedlist  */
status find_mid(sll** head, int *element);
status get_nth_last_node(sll** head, int* element, int pos);
status insert_node_last(sll** head, int data);
status print_list(sll** head);

