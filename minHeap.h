
#include <iostream>
#include <vector>
using namespace std;

template<class THING>
class minHeap
{
private:
	vector<THING> items;

	//bubble item at position i up
	//until no more violation
	//void bubbleUp(int i)
	//{
	//	if (i == 0)
	//	{
	//		//no parent, so no violation
	//	}
	//	else
	//	{	
	//		if (items[i] >= items[parent(i)])
	//		{
	//				//no violation
	//		}
	//		else
	//		{
	//			if (items[i] <= items[parent(i)])
	//			{
	//				//swap items
	//				swap(items[i], items[parent(i)]);

	//				//bubble up on parent
	//				bubbleUp(parent(i));
	//			}
	//		}
	//	}
	//}


	void bubbleUp(int i)
	{
		if (i == 0 || (items[i] >= items[parent(i)]))
		{
			//no parent, so no violation
		}
		else
		{		
			while (items[i] < items[parent(i)])
			{
				//swap items
				swap(items[i], items[parent(i)]);

				//bubble up on parent
				bubbleUp(parent(i));
			}
		}
	}

	//Index of Parent
	int parent(int i)
	{
		if (i%2 == 0)//Even number
		{
			int parentIndex = (i / 2) - 1;
			return parentIndex;
		}
		else//Odd Number
		{
			int parentIndex = (i - 1) / 2;
			return parentIndex;
		}
		
	}

	void bubbleDown(int i)
	{
		int length = items.size();
		int lChild = leftChild(i);
		int rChild = rightChild(i);

		if (lChild >= length)//Check if only 1 element
			return;

		int minIndex = i;

		if (items[i] > items[lChild])//Compare Left Child
		{
			minIndex = lChild;
		}

		if ((rChild < length) && (items[minIndex] > items[rChild]))//Compare Right Child
		{
			minIndex = rChild;
		}

		if (minIndex != i)
		{
			//Swap
			swap(items[i], items[minIndex]);
			bubbleDown(minIndex);
		}
	}

	//Index of Left Child
	int leftChild(int i)
	{
		int lChild = (2 * i) + 1;
		return lChild;
	}

	//Index of Right Child
	int rightChild(int i)
	{
		int rChild = (2 * (i + 1));
		return rChild;
	}

public:
	minHeap()
	{
	}

	//add new item to heap
	void insert(THING x)
	{
		//put item at back of array/vector
		items.push_back(x);

		//bubble item up until no more violation exists
		bubbleUp(items.size() - 1);
	}

	bool empty()
	{
		if (items.size() == 0)
			return true;
		else
			return false;
	}

	void display()
	{
		for (int i = 0; i < items.size(); ++i)
			cout << items[i] << endl;

		cout << "Size of Vector is: "<< items.size() << endl<<endl;
	}

	THING getMin()
	{
		return items[0];
	}

	//remove and return smallest item
	THING extractMin()
	{
		THING temp = items[0];

		items[0] = items[items.size() - 1];
		items.pop_back();
		bubbleDown(0);

		return temp;
	}


	void changeValueAT(THING i, THING newValue)//Change element value in index i
	{

	}


};