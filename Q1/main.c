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
PQ_l BuildPQ(Item_t** location, int* min, int size);
void DecreaseKey(Item_t** location, PQ_l PQ, int v); // Change global var PQ
Item_t* DeleteMin(PQ_l PQ);
void SortPQ(PQ_l PQ);
Item_t* GetMinInPQ(PQ_l PQ); // not in headers (should be private)
void FreePQ(PQ_l PQ);
Item_t** CreateLocationArray(int size);
void FreeLocation(Item_t** location);
int GetIndexOfPointer(Item_t** location, Item_t* node_pointer);



void FreeTree(Min_tree minimal_tree);
void Q1(Min_tree minimal_tree, Item_l* network, int size, int v0);
void Q2(int* prim, int size);

void main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("Please Run <ProgramFile> <InputFile>\n");
		exit(1);
	}
	int size, v0;
	Item_l* network = ParseFile(argv[1], &size);
	Min_tree minimal_tree = { size, InitialPrimArray(size),  InitialMinArray(size), InitialInT(size) };
	//int* prim = InitialPrimArray(size);
	//int* min = InitialMinArray(size);
	//int* InT = InitialInT(size);
	Q1(minimal_tree, network, size, v0);
	Q2(minimal_tree.prim, size);
	FreeTree(minimal_tree);

}

void Q1(Min_tree minimal_tree, Item_l* network, int size, int v0)
{
	Item_t** location = CreateLocationArray(size); // array of pointers PQ nodes
	PQ_l PQ = BuildPQ(location, minimal_tree.min, size);

	printf("%s:", "Please insert the first computer number");
	scanf("%d", &v0);

	SetMin(minimal_tree.min, v0, 0);
	SetPrim(minimal_tree.prim, v0, 0);
	DecreaseKey(location, PQ, v0);
	Item_t* node = PQ.head->next;
	while (node != NULL)
	{
		// node is min in PQ
		int u = GetIndexOfPointer(location, DeleteMin(PQ));
		if (minimal_tree.min[u] == INT_MAX)
		{
			printf("%s", "Cannot build Prim");
			exit(1);
		}
		SetInT(minimal_tree.InT, u);
		Item_l* u_neighbor = network[u].next;
		while (u_neighbor != NULL)
		{
			if (!GetInT(minimal_tree.InT, u) && u_neighbor->w < GetMin(minimal_tree.min, u))
			{
				SetMin(minimal_tree.min, u, u_neighbor->w);
				SetPrim(minimal_tree.prim, u, u_neighbor->neighbor);
				DecreaseKey(location, PQ, u_neighbor->neighbor);
			}
			u_neighbor = u_neighbor->next;
		}
		node = node->next;
	}
	PrintPrimTree(minimal_tree.prim, size);
	PrintTotalCost(minimal_tree.min, size);
	FreePQ(PQ);
	FreeNetwork(network, size);
	FreeLocation(location);
}

void Q2(int* prim, int size)
{
	// build the relevant list
	// 
}

void FreeTree(Min_tree minimal_tree)
{
	FreePrim(minimal_tree.prim);
	FreeMin(minimal_tree.min);
	FreeInT(minimal_tree.InT);
}
