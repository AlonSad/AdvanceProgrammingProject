typedef struct item_l
{
	int neighbor;
	int w;
	struct item_l* next;
} Item_l;

typedef struct item_t
{
	int vertex;
	int* min;
	struct item_t* next;
} Item_t;

typedef struct pq
{
	struct item_t* head;
	struct item_t* tail;
} PQ_l;

typedef struct min_tree
{
	int size;
	int* prim;
	int* min;
	int* InT;
} Min_tree;


typedef enum
{
	FALSE,
	TRUE,
}BOOL;

typedef enum
{
	WHITE,
	GREY,
	BLACK,
}State_COLOR;