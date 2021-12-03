/* 
Title  : Hash Table Insert (insert element into Hash Table using Direct Chaining)
Author : Vaageesh
Date   : Friday 11 December 2020 11:02:15 PM IST
*/

/* struct for linkedlist nodes  */
typedef struct array
{
	int index;
	int data;
	struct array* link;
} hash_t;

/* struct for return status of each function  */
typedef enum
{
    e_success,
    e_failure,
    EMPTY_LIST,
    DATA_FOUND,
    DATA_NOT_FOUND,
    NEGATIVE_INDEX
} status ;

/* function prototypes for inserting at first,last and deleting first,last and deleting entire list  */

status hash_search(hash_t* hash_table, int data, int size);
status hash_insert(hash_t* hash_table, int data, int size);
status hash_delete_element(hash_t* hash_table, int data, int size);
status hash_table_delete(hash_t* hash_table, int size);
status create_hash_table(hash_t* hash_table, int size);

status print_hash_table(hash_t* hash_table, int size);
