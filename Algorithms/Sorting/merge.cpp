#include<iostream>
using namespace std;

int length(int *arr)
{
	int l = sizeof(arr)/sizeof(arr[0]);
	
	return l;
}

void merge(int *ar, int *left, int *right)
{
	int nl = length(left);
	int nr = length(right);
	int i = 0, j = 0, k = 0;

	while(i<nl && j<nr)
	{
		if(left[i] <= right[j])
		{
			ar[k] = left[i];
			i++;
			k++;
		}else
		{
			ar[k] = right[j];
			j++;
			k++;
		}
	}
					// if left is not empty
	while(i<nl)
	{
		ar[k] = left[i];
		i++;
		k++;
	}
					// if right is not empty
	while(j<nr)
	{
		ar[k] = right[j];
		j++;
		k++;
	}
}


void mergeSort(int *ar)
{	
	int n = length(ar);
	if(n < 2)
	{
		return;
	}
	else
	{
	
		int mid = n/2;
		int *l, *r;
		
		l = (int*) malloc(sizeof(int)*(mid));
		r = (int*) malloc(sizeof(int)*(n-mid));

		for(int i = 0; i < mid ; i++){
			l[i] = ar[i];
		}		

		int k = 0;
		for(int j = mid; j < n; j++)
			{
				r[k] = ar[j];
				k++;
			}

		cout<< "Left and right created.\n";	

		mergeSort(l);
		mergeSort(r);
		merge(ar,l,r);
	}
}


// ----------------------------------------------------------------------------- Main Function ----------------------------------------------------------------------------------

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

	cout << "The sorted using Merge Sort array is: ";
	mergeSort(arr);
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';
	return 0;
}