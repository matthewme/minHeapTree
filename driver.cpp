//Matthew Martinez
//CSCI 3333

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "minHeap.h"
using namespace std;

template <class T>
void heapSort(T * items, int start, int end)
{

	minHeap<double> heap;

	//Build Heap
	for (int i = start; i <= end; ++i)//O(n)
	{
		T tmp = items[i];
		heap.insert(tmp);
	}

	for (int i = start; i <= end; ++i)
	{
		T tmp = heap.extractMin();
		items[i] = tmp;
	}

}

template<class T>
void removeItemAt(T * items, int start, int end, int remove)//Delete Item from array
{
	int mid = (start - end) / 2;

	if (items[mid] == remove)
	{
		items[mid] = 0;

		for (int i = start; i < end; ++i)
		{
			items[i] = items[i + 1];
		}
	}

}




int main()
{
	////////////////////////////////////////////////
	//Step 1: Implement a basic min-heap priority queue
	////////////////////////////////////////////////
	minHeap<double> pq;

	//pq.insert(53);
	//pq.insert(17);
	//pq.insert(3);
	//pq.insert(178);
	//pq.insert(519);
	//pq.insert(15);
	//pq.insert(42);
	//pq.insert(5);

	//cout << "Extracting Minium: " << pq.extractMin() << endl; //3
	//cout << "Extracting Minium: " << pq.extractMin() << endl; //5
	//cout << "Extracting Minium: " << pq.extractMin() << endl; //15
	//cout << "Extracting Minium: " << pq.extractMin() << endl; //17

	//pq.insert(93);
	//pq.insert(2);
	//pq.insert(7);
	//pq.insert(83);


	////2, 7, 42, 53, 83, 93, 178, 519
	//while (!pq.empty())
	//{
	//	cout << "Extracting Minium: " << pq.extractMin() << endl;
	//}
	//cout << endl;

	//int size = 30;
	//for (int i = 0; i<size; i++)
	//{
	//	pq.insert(rand());
	//}

	////items should display in sorted order
	//while (!pq.empty())
	//{
	//	cout << "Extracting Minium: " << pq.extractMin() << endl;
	//}
	//cout << endl;

	//////////////////////////////////////////////////////////////////////
	//Step 2: Now use your min-heap priotiy queue to implement a sorting algorithm:
	//-What is the worst case run time of your sorting algorithm?
	//////////////////////////////////////////////////////////////////////

	double * numbers;
	int max = 10000;//100000
	numbers = new double[max];

	//randomly fill array
	for (int i = 0; i<max; i++)
		numbers[i] = rand();

	////write sorting routine using your min-heap priority queue data type
	heapSort(numbers, 0, max - 1);

	//display items (now in sorted order)
	for (int i = 0; i<max; i++)
		cout << numbers[i] << endl;

	/*removeItemAt(numbers, 0, max, 19169);*/

	return 0;
}