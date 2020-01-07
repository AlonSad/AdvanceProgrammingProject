#include <stdio.h>
#include <stdlib.h>
#include "limits.h"
#include "prim.h"


int* InitialPrimArray(int size)
{
	int* array = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
	{
		SetPrim(array, i, INITIAL_PRIM);
	}
	return array;
}

void SetPrim(int* prim, int v, int parent)
{
	prim[v] = parent;
}

void PrintPrimTree(int* prim, int size)
{
	printf("%s", "The connections are: ");
	for(int i = 1; i< size; i++)
	{
		printf("(%d,%d) ", prim[i], i);
	}
}


void FreePrim(int* prim)
{
	free(prim);
}