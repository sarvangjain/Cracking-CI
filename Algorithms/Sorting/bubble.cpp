#include<iostream>
using namespace std;

int *bubbleSort(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{	
		int flag = 0;
		
		for (int j = 0; j < n-i-1; j++)
		{	
			if(a[j+1] < a[j])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
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
	arr = bubbleSort(arr,n);
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';
	return 0;
}