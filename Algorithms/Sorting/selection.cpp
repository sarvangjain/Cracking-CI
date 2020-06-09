#include<iostream>
using namespace std;

int *selSort(int *a, int n)
{
	int i,j;
	for(i = 0; i < n-1; i++)
	{
		int imin = i;
		for(j = i; j < n; j++)
		{
			if(a[j] < a[imin])
			{
				imin = j;
			}
		}
		int temp = a[imin];
		a[imin] = a[i];
		a[i] = temp;
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
	arr = selSort(arr,n);
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';
	return 0;
}