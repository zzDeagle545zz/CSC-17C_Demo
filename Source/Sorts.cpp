/*
Description
*/

//User Libraries
#include "Sorts.h"

//******************************************************************************
//******************************************************************************
//							Selection Sort
//Function- A process of Sorting, in this case Numbers by comparing one element
//	to another and switching them 
//Inputs
//      -->>Array to be Sorted
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
void SelSort(tArray A) {
/*
	File:   main.cpp
	Author: Dr. Mark E. Lehr
	Created on February 2nd, 2016, 8:20 AM
	Purpose:  To develop a sorting routine called Selection Sort
*/
//Find smallest in each successive list
//From the beginning of the list to the end
//Outside Element of the list
	for (int i = 0;i<A.getSize() - 1;i++) {
		int val = A.getA()[i], pos = i;
		//Inside List above the Element
		for (int j = i + 1;j<A.getSize();j++) {
			//Swap
			if (val>A.getA()[j]) {
				val = A.getA()[j];pos = j;
			}
		}
		//Swap
		A.getA()[pos] = A.getA()[i];
		A.getA()[i] = val;
	}
}
//******************************************************************************
//******************************************************************************
//							Bubble Sort
//Function- 
//Inputs
//      -->>Array to be Sorted
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
void BubSort(tArray A) {
/*
	File:   main.cpp
	Author: Dr. Mark E. Lehr
	Created on February 2nd, 2016, 8:20 AM
	Purpose:  To develop a sorting routine called Bubble Sort
*/
//Outside loop to test if any swaps happen
	bool swap;
	do {
		swap = false;
		//Inside List above the Element
		for (int j = 0;j<A.getSize() - 1;j++) {
			//Swap
			if (A.getA()[j]>A.getA()[j + 1]) {
				int temp = A.getA()[j];
				A.getA()[j] = A.getA()[j + 1];
				A.getA()[j + 1] = temp;//Exclusive or XOR a=b
				swap = true;
			}
		}
	} while (swap);
}
//******************************************************************************
//******************************************************************************
//							Mark Sort
//Function- 
//Inputs
//      -->>Array to be Sorted
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
void MarkSort(tArray A){
/*
	File:   main.cpp
	Author: Dr. Mark E. Lehr
	Created on February 2nd, 2016, 8:20 AM
	Purpose:  To develop a sorting routine called Mark Sort
	*            Place in 1 function
*/
	//Find smallest in each successive list
	//From the beginning of the list to the end
	//Outside Element of the list
	for (int i = 0;i<A.getSize() - 1;i++) {
		//Inside List above the Element
		for (int j = i + 1;j<A.getSize();j++) {
			//Swap
			if (A.getA()[i]>A.getA()[j]) {
				int temp = A.getA()[j];
				A.getA()[j] = A.getA()[i];
				A.getA()[i] = temp;//Exclusive or XOR a=b
			}
		}
	}
}
//******************************************************************************
//******************************************************************************
//							Merge Sort
//Function- 
//Inputs
//      -->>Array to be Sorted
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
/*
* File:   main.cpp
* Author: Dr. Mark E. Lehr
* Created on April 2, 2017, 1:19 PM
* Purpose: Create a Recursive sort
*/
void MergeSort(tArray a, int beg, int end) {
	int center = (beg + end) / 2;//Split the task down the middle
	if ((center - beg)>1)MergeSort(a, beg, center);//Got to be an array to split
	if ((end - center)>1)MergeSort(a, center, end);//Got to be an array to split
	merge(a, beg, center, end);//Merge the sorted arrays into 1 larger sorted array
}
//******************************************************************************
//******************************************************************************
//							Merge
////////////////////////////////////////////////////////////////////////////////
void merge(tArray a, int beg, int nlow, int nhigh) {
	//Create a merged array
	int span = nhigh - beg;    //Span the range to merge
	int cntl = beg, cnth = nlow;//Independent counters to merge the split
								//Fill the array
	for (int i = 0;i<span;i++) {
		if (cntl == nlow) {//Low done fill with the higher end of array
			a.getB()[i] = a.getA()[cnth++];
		}
		else if (cnth == nhigh) {//High done fill with lower end of array
			a.getB()[i] = a.getA()[cntl++];
		}
		else if (a.getA()[cntl]<a.getA()[cnth]) {
			a.getB()[i] = a.getA()[cntl++];//Fill with lower end
		}
		else {
			a.getB()[i] = a.getA()[cnth++];//Fill with higher end
		}
	}
	//Copy back from the working array to the sorted array
	for (int i = 0;i<span;i++) {
		a.getA()[beg + i] = a.getB()[i];
	}
}
//******************************************************************************
//******************************************************************************
//							Quick Sort
//Function- 
//Inputs
//      -->>Array to be Sorted
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
//Author :Neeraj Mishra
//www.thecrazyprogrammer.com/2016/11/program-for-quick-sort-c.html
void QuickSort(int a[],int l, int u) {
	int j;
	if (l<u)
	{
		j = partition(a, l, u);
		QuickSort(a, l, j - 1);
		QuickSort(a, j + 1, u);
	}
}
//******************************************************************************
//******************************************************************************
//							partition
////////////////////////////////////////////////////////////////////////////////
//www.proprogramming.org/heap-sort-in-c/
int partition(int a[], int l, int u)
{
	int v, i, j, temp;
	v = a[l];
	i = l;
	j = u + 1;

	do
	{
		do
			i++;

		while (a[i]<v&&i <= u);

		do
			j--;
		while (v<a[j]);

		if (i<j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	} while (i<j);

	a[l] = a[j];
	a[j] = v;

	return(j);
}
//******************************************************************************
//******************************************************************************
//							Heap Sort
//Function- 
//Inputs
//      -->>Array to be Sorted
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
void HeapSort(int *a, int n)
{
	int i, temp;
	for (i = n; i >= 2; i--)
	{
		temp = a[i];
		a[i] = a[1];
		a[1] = temp;
		max_heapify(a, 1, i - 1);
	}
}
//******************************************************************************
//******************************************************************************
//							Max_heapify
////////////////////////////////////////////////////////////////////////////////
void max_heapify(int *a, int i, int n)
{
	int j, temp;
	temp = a[i];
	j = 2 * i;
	while (j <= n)
	{
		if (j < n && a[j + 1] > a[j])
			j = j + 1;
		if (temp > a[j])
			break;
		else if (temp <= a[j])
		{
			a[j / 2] = a[j];
			j = 2 * j;
		}
	}
	a[j / 2] = temp;
	return;
}
//******************************************************************************
//******************************************************************************
//							Build_Maxheap
////////////////////////////////////////////////////////////////////////////////
void build_maxheap(int *a, int n)
{
	int i;
	for (i = n / 2; i >= 1; i--)
	{
		max_heapify(a, i, n);
	}
}
//******************************************************************************
//******************************************************************************
//							Test Array
//  
////////////////////////////////////////////////////////////////////////////////
//******************************************************************************
//******************************************************************************
//							Test Array Constructor
//Function-
//Inputs
//      -->>
//      <<--
////////////////////////////////////////////////////////////////////////////////
tArray::tArray(int s) {
//Set random Seed
	std::srand(static_cast<unsigned int>(std::time(0)));
//Create the Array
	size = s;
	a = new int[size];
	b = new int[size];
//Fill the Array
	fillArray();
//
}
//******************************************************************************
//******************************************************************************
//							Test Array Destructor
//Function-
//Inputs
//      -->>
//      <<--
////////////////////////////////////////////////////////////////////////////////
tArray::~tArray() {
//Free up Memory
	//delete a;delete b;
}
//******************************************************************************
//******************************************************************************
//							Fill the Array 
//Function- Creates a Array and Intializes the Array
//Inputs
//      -->>
//      <<--
////////////////////////////////////////////////////////////////////////////////
void tArray::fillArray() {
//Delete old Array
	delete [] a; 
//Create new Array
	a = new int[size];
//Intialize
	for (int c = 0;c < size;c++) {
	//Set values randomly
		a[c] = rand()%90+10;
	}
}
//******************************************************************************
//******************************************************************************
//							Shuffle the Array 
//Function- Shuffles the array with Mixed Number in a pattern or Random
//Inputs
//      -->>
//      <<--
////////////////////////////////////////////////////////////////////////////////
void tArray::shuffle(int type=0) {
//Choose Shuffle Method
	switch(type){
	//Randomly
	case random:
		for (int c = 0;c < size * 10;c++) {
		//Swap Values
			int t1 = rand() % size;
			int t2 = rand() % size;
			a[t1] = a[t1] ^ a[t2];
			a[t1] = a[t1] ^ a[t2];
			a[t1] = a[t1] ^ a[t2];
		} break;
	//


	}
}