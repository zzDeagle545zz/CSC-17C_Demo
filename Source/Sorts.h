/*
* File:   Sorts.h
* Author: zzDeagle545zz(Christopher Garcia)
* Version V1 Created on May 24, 2017.
*
* Function: Create Class for a test Array of Integers.
*	Define all the sorts to be compatible with Test
*	Array.
*/

//Guard Block
#ifndef SORTS_H
#define SORTS_H

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>

//User Libraries


//******************************************************************************
//******************************************************************************
//                             Sort Enumeration
////////////////////////////////////////////////////////////////////////////////
enum sorts{SELSORT,BUBSORT,MRKSORT,MRGSORT,QUKSORT,HEPSORT};
//******************************************************************************
//******************************************************************************
//                             Test Array
//  
////////////////////////////////////////////////////////////////////////////////
class tArray {
private:
//Data Members
	int* a;						//Working Array
	int* b;						//Second Array if need
	int size;					//Size of Array
//Enumeration
	enum sType { random };
protected:

public:
	tArray(int);			//Constructor
	~tArray();				//Destructor
//Acessor Functions
	int getSize() { return size; }
	int* getA() { return a; }
	int* getB() { return b; }
//Manipulators
	void setSize(int s) { size = s; fillArray(); }
//Member Functions
	void fillArray();						//Intializes Array randomly
	void shuffle(int);						//Changes array to mixed numbers
};
//******************************************************************************
//******************************************************************************
//                            Analysis Data
//  
////////////////////////////////////////////////////////////////////////////////
struct SortData {
//Total Time in Milliseconds
	float tTime;
};
//******************************************************************************
//******************************************************************************
//						Algorithm Prototypes
//  
////////////////////////////////////////////////////////////////////////////////
//Selection Sort
void SelSort(tArray);
//Bubble Sort
void BubSort(tArray);
//Mark Sort
void MarkSort(tArray);
//Merge Sort
void MergeSort(tArray,int,int);
void merge(tArray, int, int, int);
//Quick Sort
void QuickSort(int[],int,int);
int partition(int a[], int, int);
//Heap Sort
void HeapSort(int*,int);
void max_heapify(int*, int, int);
void build_maxheap(int*, int);

#endif //SORTS_H