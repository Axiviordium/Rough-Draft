// QuickSort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;

// partition using Lomuto partition scheme
int Partition(int a[], int start, int end) {

	
	int pivot = a[end];		//Pick rightmost element as pivot from the array

	// elements less than pivot will be pushed to the left of pIndex
	// elements more than pivot will be pushed to the right of pIndex
	// equal elements can go either way
	int pIndex = start;

	// each time we finds an element less than or equal to pivot, pIndex
	// is incremented and that element would be placed before the pivot.
	for (int i = start; i < end; i++)
	{
		if (a[i]<=pivot)
		{
			swap(a[i], a[pIndex]);
			pIndex++;
		}
	}

	
	swap(a[pIndex], a[end]);		// Swap pIndex with Pivot
	return pIndex;					//return index of pivot element
}


void quicksort(int a[], int start, int end) {
	
	if (start >= end) return;					//base condition
	int pivot = Partition(a, start, end);		//rearrange the elments across pivot
	quicksort(a, start, pivot - 1);				//recur on sub-array containing elements that are less then pivot
	quicksort(a, pivot+1, end);					//recur on sub-array containing elements that are more then pivot
}


// C++ implementation of quicksort algorithm
int main()
{
    cout << "Hello World!\n"; 

	int a[] = { 9, -3, 5, 2, 6, 8, -6, 1, 3 };
	int n = sizeof(a) / sizeof(a[0]);

	quicksort(a, 0, n - 1);

	// print the sorted array
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	return 0;
}

