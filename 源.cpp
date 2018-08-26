#include<iostream>

#include<math.h>

using namespace std;

class Max_Heap {
public:
	int Left_Child(int i)
	{
		return i * 2;
	}

	int Right_Child(int i)
	{
		return i * 2 + 1;
	}

	int Parent(int i)
	{
		return i / 2;
	}
	void Inserting(int key);
	int Get_Max();
	void Remove(int i);
	int Pop_Max();
	void Max_Heapfy(int i);
	Max_Heap() :size(0)
	{};
private:
	int array[128];
	int size;
};

void Max_Heap::Inserting(int key)
{
	if (size == 127)
	{
		cout << "Heap is Full";
		return;
	}
	if (size == 0)
	{
		size++;
		array[size] = key;
		return;
	}
	size++;
	array[size] = key;

	int i = size;
	while (i!=1&&key > array[Parent(i)])
	{
		swap(array[i], array[Parent(i)]);
		i = Parent(i);
	}
	return;
}

int Max_Heap::Get_Max()
{
	return array[1];
}

void Max_Heap::Max_Heapfy(int i)
{
	int right = Right_Child(i);
	int left = Left_Child(i);
	int Max=i;
	if (right <= size && array[right] > array[Max])
		Max = right;
	if (left <= size && array[left] > array[Max])
		Max = left;
	if (Max != i)
	{
		swap(array[i], array[Max]);
		Max_Heapfy(Max);
	}
	else
		return;
}

void Max_Heap::Remove(int i)
{
	array[i] = -100000;
	Max_Heapfy(i);
	if (array[size] == -100000)
		size--;
	else
	{
		swap(array[size], array[size - 1]);
		size--;
	}
}

int Max_Heap::Pop_Max()
{
	int temp = array[1];
	Remove(1);
	return temp;
}

int main()
{
	Max_Heap T;
	T.Inserting(5);
	T.Inserting(6);
	T.Inserting(15);
	T.Inserting(80);
	T.Inserting(95);
	T.Inserting(6);
	T.Inserting(255);
	cout << T.Pop_Max() << endl;
	cout << T.Get_Max();

	system("pause");
}
