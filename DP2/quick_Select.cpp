
#include <bits/stdc++.h> 
using namespace std; 


int partition(int arr[], int l, int r) 
{ 
	int x = arr[r], i = l; 
	for (int j = l; j <= r - 1; j++) { 
		if (arr[j] <= x) { 
			swap(arr[i], arr[j]); 
			i++; 
		} 
	} 
	swap(arr[i], arr[r]); 
	return i; 
} 


int kthSmallest(int arr[], int l, int r, int k) 
{ 
	// If k is smaller than number of 
	// elements in array 
	if (k > 0 && k <= r - l + 1) { 

		// Partition the array around last 
		// element and get position of pivot 
		// element in sorted array 
		int index = partition(arr, l, r); 

		// If position is same as k 
		if (index - l == k - 1) 
			return arr[index]; 

		// If position is more, recur 
		// for left subarray 
		if (index - l > k - 1) 
			return kthSmallest(arr, l, index - 1, k); 

		// Else recur for right subarray 
		return kthSmallest(arr, index + 1, r, 
							k - index + l - 1); 
	} 

	// If k is more than number of 
	// elements in array 
	return INT_MAX; 
} 

// Driver program to test above methods 
int main() 
{ 
	int n{0};
    cout<<"Enter size of array :";
    cin>>n;

    cout<<"Enter elements : \n";
    int*arr = new int[n];
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }

    cout<<"Enter value of K : ";
    int k{0};
    cin>>k;
	cout << "K-th smallest element is "
		<< kthSmallest(arr, 0, n - 1, k); 
	return 0; 
} 