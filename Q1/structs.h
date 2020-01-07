typedef struct item_l
{
	int neighbor;
	int w;
	struct item_l* next;
} Item_l;

typedef struct item_t
{
	int vertex;
	int min;
	struct item_t* next;
} Item_t;

typedef struct pq
{
	struct item_t* head;
	struct item_t* tail;
} PQ_l;