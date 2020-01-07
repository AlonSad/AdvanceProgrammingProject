#include <stdio.h>
#include <stdlib.h>
#include "inT.h"
#include "limits.h"

int* InitialInT(int size)
{
	int* array = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
	{
		array[i] = FALSE;
	}
	return array;
}

BOOL GetInT(int* arr, int v)
{
	return arr[v];
}

void SetInT(int* arr, int v)
{
	arr[v] = TRUE;
}

void FreeInT(int* arr)
{
	free(arr);
}