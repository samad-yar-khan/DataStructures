// input - input array
// size - length of input array
// element - value to be searched
int binary_search(int input[],int starting_i,int end_i,int element){
	if(starting_i>end_i){
        return -1;
    }
    int mid=(starting_i+end_i)/2;
    if(input[mid]==element){
        return mid;
    }
    if(input[mid]>element){
        return binary_search(input,starting_i,mid-1,element);
    }
    else{
        return binary_search(input,mid+1,end_i,element);
    }
}
int binarySearch(int input[], int size, int element) {
    // Write your code here
    int starting_i =0;
    int end_i= size-1;
	return binary_search(input,starting_i,end_i,element);

}
