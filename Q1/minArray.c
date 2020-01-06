#include <stdio.h>
#include <stdlib.h>
#include "min.h"
#include "limits.h"


int* InitialMinArray(int size)
{
	int* array = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
	{
		SetMin(array, i, INT_MAX);
	}
	return array;
}

void SetMin(int* min, int v, int cost) // parent == u
{
	min[v] = cost;
}

int GetMin(int* min, int v)
{
	return min[v];
}

void PrintTotalCost(int* min, int size)
{
	int c = 0;
	for(int i = 1; i < size; i++)
	{
		c += min[i];
	}
	printf("The cost of the minimal tree is: %d", c);
}

void FreeMin(int* min)
{
	free(min);
}