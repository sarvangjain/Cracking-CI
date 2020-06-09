#include<iostream>
using namespace std;

int *insertionSort(int *a, int n){
	for(int i = 1; i<n; i++)
	{
		int val = a[i];
		int hole = i;
		while(hole > 0 && a[hole-1] > val)
		{
			a[hole] = a[hole-1];
			hole--;
		}
		a[hole] = val;
	}
	return a;
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

	cout << "The sorted array is: ";
	arr = insertionSort(arr,n);
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';
	return 0;
}