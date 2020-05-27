#include <iostream>
#include <cmath>
using namespace std;

int main() {
	// your code goes here
	int i, t;
	std::cin >>t;
	int arr[t];
	for(i=0;i<t;i++){
	    std::cin>>arr[i];
	}
	for(i=0;i<t;i++){
	    int val = arr[i];
	    int temp,j;
	    temp = val;
	    int n = 0;
	    while(temp>0){
	        n++;
	        temp = temp/10;
	    }
	    int rev = 0;
	    for(j=n;j>0;j--){
	        rev += pow(10,j)*(val%10);
	        val = val/10;
	    }
	    while(rev%10 == 0){
	        rev = rev/10;
	    }
	    std::cout << rev << std::endl;
	}
	return 0;
}
