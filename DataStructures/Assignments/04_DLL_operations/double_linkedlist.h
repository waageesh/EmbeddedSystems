/* struct for node in linkedlist  */
typedef struct
{
	int data;
	struct dll* link;
	struct dll* prev;
} dll;

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
status insert_after(dll** head, int data, int after_before_data);
status insert_before(dll** head, int data, int after_before_data);
status insert_node_last(dll** head, int data);
status delete_element(dll** head, int data);
status print_list(dll** head);

