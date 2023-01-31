#include <iostream>
#include <fstream>
using namespace std;

void Swap(double* xp, double* yp)
{
	double temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void heapify(double* arr, int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i)
	{
		Swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

void build_heap(double* arr, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(arr, n, i);
	}
}

void heap_sort(double* arr, int n)
{
	build_heap(arr, n);
	for (int i = n - 1; i >= 0; i--)
	{
		Swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

void get_frequencies(double arr[], int n)
{
	heap_sort(arr, n);
	int countr = 1;
	double element = -1;

	for (int i = 0; i < n; i++)
	{
		element = arr[i];
		if (arr[i] == arr[i + 1])
		{
			countr++;
		}
		else
		{
			cout << "   " << element << "               " << countr << endl;
			element = -1;
			countr = 1;
		}
	}
}

double most_frequent(double arr[], int n)
{
	heap_sort(arr, n);
	int temp = 1;
	int countr = 0;
	double Melement = -1;
	double element = -1;
	for (int i = 1; i < n; i++)
	{
		element = arr[i];
		if (arr[i] == arr[i - 1])
		{
			temp++;
		}
		if (temp > countr)
		{
			countr = temp;
			Melement = element;
		}
		if (arr[i] != arr[i - 1])
		{
			temp = 1;
			element = -1;
		}
	}
	return Melement;
}




int main()
{
	double temp;
	ifstream Numbers1("Numbers.txt");
	int size = 0;
	while (Numbers1 >> temp)
	{
		size++;
	}
	Numbers1.close();

	ifstream Numbers2("Numbers.txt");
	double* a;
	a = new double[size];
	int i = 0;
	while (Numbers2 >> temp)
	{
		a[i] = temp;
		i++;
	}
	Numbers2.close();

	cout << "Most frequent number is " << most_frequent(a, size) << endl << endl;
	cout << "Element" << "        " << "Frequency" << endl;
	get_frequencies(a, size);

	delete[] a;
	system("pause");
	return 0;
}