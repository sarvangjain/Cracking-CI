#include<iostream>

using namespace std;


void arrToHeap(int *arr,int n)
{
	int i =0;
	for(i;i<n;i++)
	{
		int par = (i+1)/2;
		int ele = i;
		while(par > 0)
		{
			if(arr[par-1]< arr[ele]){
				int tmp = arr[ele];
				arr[ele] = arr[par-1];
				arr[par-1]=tmp;
				ele = par - 1;
				par = par/2;
			}else
			{
				break;
			}
		}

	}
}


int heapifyDown(int *arr, int size){
	int val = arr[0];
	arr[0] = arr[size-1];
	arr[size-1] = val;
	size--;

	int i = 0;
	while(i < size)
	{
		int lc = (i+1)*2;
		int rc = (i+1)*2 +1;
		int max;
		if(lc-1>=size){
			break;
		}else{
			max = lc-1;
			if(rc-1<size && arr[rc-1] > arr[lc-1]){
				max = rc-1;
			} 
			if(arr[max] <= arr[i]){
				break;
			}else{
				int tmp = arr[max];
				arr[max] = arr[i];
				arr[i] = tmp;
				i = max;
 			}
		}
	}

	return val;
}



void heapSort(int *arr, int n)
{
	int i = n-1;
	int size = n;
	for(i;i>0;i--)
	{
		int r = heapifyDown(arr,size);
		arr[i] = r;
		size--;
	}
}


int binarySearchRecur(int *arr,int x, int left, int right)
{
	if (left < right){
		int mid = (left+right)/2;
		if (arr[mid] == x)
			return mid;
		else if (arr[mid] > x)
			return binarySearchRecur(arr,x,left,mid-1);
		else
			return binarySearchRecur(arr,x,mid+1,right);
	} else{
		return -1;
	}

	
}


int main(){

	int *arr;
	int n;
	int x;
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

	cout << "The heap is: ";
	arrToHeap(arr,n);
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';

	cout << "The sorted array is: ";
	
	heapSort(arr,n);
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';
	
	cout << "Enter number to search\n";
	cin >> x;

	int ind = binarySearchRecur(arr,x,0,n);
	cout << "The element " << x << " is at: " << ind <<"\n";
	
	return 0;
}