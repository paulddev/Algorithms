#include <iostream>
using namespace std;

/* ������ �����ϴ� ������ Array Ŭ���� */

class Array
{
	int* arr;
	int size;
	int capacity;

public:
	// ���� �Լ� ����(���� ������, ���� ���� ������)
	Array(int cap = 100) : arr(0), size(0), capacity(cap)
	{
		arr = new int[capacity];
	}

	~Array()
	{
		delete[] arr;
	}

	void Add(int data)
	{
		if (size < capacity)
			arr[size++] = data;
	}

	int Size() const
	{
		return size;
	}

	int operator[](int idx) const
	{
		return arr[idx];
	}

	int& operator[](int idx)
	{
		return arr[idx];
	}
};

int main()
{
	Array ar(10);
	ar.Add(10);
	ar.Add(20);
	ar.Add(30);

	cout << ar[0] << endl;
	cout << endl;

	const Array& ar2 = ar;
	cout << ar2[0] << endl; // ar.operator[](int) const �� ȣ��
	cout << endl;

	ar[0] = 100;
	// ar2[0] = 100; ����, ��� ��ü�� ��ȯ�ϹǷ� ���� x
	cout << ar[0] << endl;
	
	return 0;
}