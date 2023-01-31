//#include <iostream>
//using namespace std;
//
//void Swap(double* xp, double* yp)
//{
//	double temp = *xp;
//	*xp = *yp;
//	*yp = temp;
//}
//
//void heapify(double* arr, int n, int i)
//{
//	int largest = i;
//	int l = 2 * i + 1;
//	int r = 2 * i + 2;
//	if (l < n && arr[l] > arr[largest])
//		largest = l;
//
//	if (r < n && arr[r] > arr[largest])
//		largest = r;
//
//	if (largest != i)
//	{
//		Swap(&arr[i], &arr[largest]);
//		heapify(arr, n, largest);
//	}
//}
//
//void build_heap(double* arr, int n)
//{
//	for (int i = n / 2 - 1; i >= 0; i--)
//	{
//		heapify(arr, n, i);
//	}
//}
//
//void heap_sort(double* arr, int n)
//{
//	build_heap(arr, n);
//	for (int i = n - 1; i >= 0; i--)
//	{
//		Swap(&arr[0], &arr[i]);
//		heapify(arr, i, 0);
//	}
//}
//
//void get_frequencies(double arr[], int n)
//{
//	heap_sort(arr, n);
//	int countr = 1;
//	double element = -1;
//	
//	for (int i = 0; i < n; i++)
//	{
//		element = arr[i];
//		if (arr[i] == arr[i+1])
//		{
//			countr++; 
//		}
//		else
//		{
//			cout << "   " << element << "               " << countr << endl;
//			element = -1;
//			countr = 1;
//		}
//	}
//}
//
//int main()
//{
//	int n = 10;
//	double arr[10] = { 4,2,2,1,7,7,4,2,3,1 };
//	cout << "Not sorted array" << endl;
//	for (int i = 0; i < n; i++)
//	{
//		cout << arr[i] << "   ";
//	}
//
//	heap_sort(arr, n);
//
//	cout << "\nSorted array" << endl;
//	for (int i = 0; i < n; i++)
//	{
//		cout << arr[i] << "   ";
//	}
//	cout << endl << endl;
//	cout << "Element" << "        " << "Frequency" << endl;
//	cout << "------------------------" << endl;
//	get_frequencies(arr, n);
//
//
//	system("pause");
//	return 0;
//}