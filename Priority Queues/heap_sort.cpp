#include<iostream>
using namespace std;


//in heap sort instead of storing lemeets in an actual pq or a heap
//we assume that we are adding elements to a heap but , in reality  we ll be
//making changes to our array . adding elemments at the end like a cbt and then upheapify 
//basicallly istead of using an additiional ppriority que to sorrt oue element we 
//turn our array intoo a heap
//and delete eeements so it reverse soprtd

void inplaceHeapSort(int input[], int n){
    
    //we are adding elements to the heap 
    int arr_size = n;
    int heap_size=1;
    int my_index=1;
    int parent_index ;
    //at eaciteraton our heap sze is inxreased and from a heaps pov a new element is ppopped at its end
    //maintaining the CBT property
	for(int i=1  ; i<n ; i++){
        my_index=heap_size;
        heap_size++;
        parent_index = (my_index -1)/2;
        
        //after addint the elment to the heap (figuratively ) we now up heapify
        //in reality we should treat this as if at each iteratin of the outer loop
        //a new elmenet is addedd to the heap (heap size++) and then 
        //then we just upheapify this elmeent to maintain
        //heap order property .
        // we keep adding elements till all elments have been added 
        while(my_index >0 && input[my_index] < input[parent_index]){
            int temp =  input[my_index];
            input[my_index]=input[parent_index];
           input[parent_index]=temp;
            
            my_index = parent_index;
            parent_index = (my_index -1)/2;
            }
    }
    
    	//here we do a process much like the remove_min function on the heap
    int last_index= n-1;
    
    while(last_index>0){
        
        //swap first And last element
        
        int temp= input[last_index];
        input[last_index]=input[0];
        input[0]=temp;
        
        //this next line signifie sthat my heap size is decreases / last leent deleted 
        //but in reality we just blocked aa=ccess to it to it
        //this is exacty what hapepnd when we pop tthe last element of our vector 
        //in vector we are able to us  the size() func but here we must maintain 
        // variable to signify the size of our heap
        last_index--;
        
        //downheapify
        
        // getting child indixces and min indices 
        //we set min indices to our index
        
        int my_index =0;
        int left_child = 2*my_index+1;
        int right_child = 2*my_index +2;

        
		
        //works same way like delete func in pqs
        while(left_child <= last_index){ //we stop at last index
            
            //we asuume ours to bbe the min
            //we compare our lements , lft and right child and the inddex of the min is stored 
            //in min index
            //mow what happend is that at the end we replace our element wit the min elemet
            //if we are the the min elemet we break out
            int min_index=my_index;
            if(input[left_child] < input[min_index]){
                min_index=left_child;
            }
            
            
            //must check if right lemenet is even present or not
            if(right_child <= last_index && input[right_child] < input[min_index]){
                min_index=right_child;
            }
            
            if(my_index == min_index ){
                break;
            }else{
                int temp = input[my_index];
                input[my_index] = input[min_index];
                input[min_index] = temp;
                
                //find new chhildren
                my_index = min_index;
                left_child = 2*my_index+1;
        		right_child = 2*my_index +2;
                
            }
        }
    }
}
//time complexity = O(nlogn)
//space complexity = O(1)

void reverse (int arr[] , int n){

    int i = 0 , j = n-1;
    while(i < j){

        int temp = arr[i];
        arr[i]=arr[j];
        arr[j] = temp;
        i++;j--;
    }

}

int main(){
    cout<<"how many elements do you wantt to enter ? ";
    int n{0};
    cin>>n;

    int *arr = new int[n];

    for(int i{0} ; i<n ; i++){
        cin>>arr[i];
    }

    inplaceHeapSort(arr,n);
    reverse(arr,n);
    //Due too min heap , array is reverse sorted so we need to reverse it 
    cout<<" \nSorted elements - ";



    for(int i{0} ; i<n ; i++){
        cout<<*(arr+i)<<" ";
    }

    delete [] arr;
}