#include <stdio.h>
#include <stdlib.h>

#include "min.h"
#include "structs.h"
#include "prim.h"
#include "inT.h"


// Network section
Item_l* ParseFile(char* file, int* size);
void FreeNetwork(Item_l* network, int size);

// PQ section
PQ_l BuildPQ(Item_t** location, int size);
void DecreaseKey(Item_t** location, PQ_l PQ, int* min, int v); // Change global var PQ
Item_t* DeleteMin(PQ_l PQ);
void SortPQ(PQ_l PQ);
Item_t* GetMinInPQ(PQ_l PQ); // not in headers (should be private)
void FreePQ(PQ_l PQ);
Item_t** CreateLocationArray(int size);
void FreeLocation(Item_t** location);
int GetIndexOfPointer(Item_t** location, Item_t* node_pointer);



void FreeAll(int* prim, int* min, int* InT, Item_l* network, Item_t** location, PQ_l PQ, int size);

void main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("Please Run <ProgramFile> <InputFile>\n");
		exit(1);
	}
	int size, v0;
	Item_l* network = ParseFile(argv[1], &size);
	int* prim = InitialPrimArray(size);
	int* min = InitialMinArray(size);
	int* InT = InitialInT(size);

	Item_t** location = CreateLocationArray(size); // array of pointers PQ nodes
	PQ_l PQ = BuildPQ(location, size);

	printf("%s:", "Please insert the first computer number");
	scanf("%d", &v0);

	SetMin(min, v0, 0);
	SetPrim(prim, v0, 0);
	DecreaseKey(location, PQ, min, v0);
	Item_t* node = PQ.head->next;
	while (node != NULL)
	{
		int u = GetIndexOfPointer(location, DeleteMin(PQ));
		if (min[u] == INT_MAX)
		{
			printf("%s", "Cannot build Prim");
			exit(1);
		}
		SetInT(InT, u);
		Item_l* u_neighbor = network[u].next;
		while (u_neighbor != NULL)
		{
			if (!GetInT(InT, u) && u_neighbor->w < GetMin(min, u))
			{
				SetMin(min, u, u_neighbor->w);
				SetPrim(prim, u, u_neighbor->neighbor);
				DecreaseKey(location, PQ, min, u_neighbor->neighbor);
			}
		}
		node = node->next;
	}
	PrintPrimTree(prim, size);
	PrintTotalCost(min, size);
	FreeAll(prim, min, InT, network, location, PQ, size);
}

void FreeAll(int* prim, int* min, int* InT, Item_l* network, Item_t** location, PQ_l PQ, int size)
{
	FreePrim(prim);
	FreeMin(min);
	FreeInT(InT);
	FreeNetwork(network, size);
	FreeLocation(location);
	FreePQ(PQ);
}
