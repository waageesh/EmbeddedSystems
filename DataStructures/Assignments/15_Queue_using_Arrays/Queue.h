/* struct for return status of queue operations */
typedef enum
{
	e_true,
	e_false,
	QUEUE_FULL,
	QUEUE_EMPTY
} status;

/* struct for queue using static array  */
typedef struct
{
	unsigned int capacity;
	int front, rear;
	int* item;
} queue_t ;

/* queue modifying functions */
status create(queue_t* Q, int size);
status Enqueue(queue_t* Q, int data);
status Dequeue(queue_t* Q, int* element);
status front(queue_t* Q, int* element);
status print_queue(queue_t* Q);
status free_queue(queue_t* Q);


/* queue empty/full status functions */
status queue_isempty(queue_t* Q);
status queue_isfull(queue_t* Q);
