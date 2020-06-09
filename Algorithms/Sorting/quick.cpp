#include<iostream>

using namespace std;


int partition(int *arr, int start, int end)
{
	int pivot, pIndex;
	pivot = arr[end];
	pIndex = start;
	for(int i = start; i < end - 1; i++)
	{
		if(arr[i] <= pivot)
		{
			int temp = arr[i];
			arr[i] = arr[pIndex];
			arr[pIndex] = temp;
			pIndex++;
		}
	}
	if(arr[pIndex]>pivot)
	{
		int tmp = arr[end];
		arr[end] = arr[pIndex];
		arr[pIndex] = tmp;
	}
	return pIndex;	

}

void quickSort(int *arr, int start, int end)
{
	if(start < end)
	{
		int pIndex;
		pIndex = partition(arr,start,end);
		quickSort(arr,start,pIndex-1);
		quickSort(arr,pIndex+1,end);
	}
}


int main(){

	int *arr;
	int n;
	cout << "Enter number of elements\n";
	cin >> n;
	
	arr = (int*)malloc(sizeof(int)*n);
	cout << "Enter the elements\n";

	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << "The intial array is: ";
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';


	cout << "The sorted array is: ";
	quickSort(arr,0,n-1);
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';
	return 0;
}