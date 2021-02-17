//concept
//a k sorted array is one in which each elment is k postions away forom it actual poistion
//har element apni correct posistion se bas k-1 eleemnt dur hai
//ex if element is at i =5 and k=3
//correct posn of i or eemenst whch can be put at i are - indces - 3,4,] 5 [,6,7

#include<iostream>
using namespace std;
#include"PriorityQueue.h" 
#include<queue>

//acrtually reverse sort
void sort_ksorted (int *arr , int size , int k){

    priority_queue <int> pq; //using inbuild pq

    //we push firts k element to the pq as nothng is on let sie of index 0
    //if k = 3
    //elment which is to be placed at index 0 cane be from index 0 , 1 ,2 
    //so  we just put them in max_pq and place the max at our index
    for(int i=0 ; i<k ;i++){
        pq.push(arr[i]);
    }

    int j=0; //j will be iindex where we have to insert our lement
    
    //my i tell me the next index whihc is to be aadded in the queue once i remove an element
    //we have already added k-1 elements to the q so we start adding form k till we have added all
    
    for (int i=k ; i<size ;i++){ 

        arr[j]=pq.top(); //puts the max element at jth index , we need not worry about the lement at j 
                         //becaise its already stored in the pq
        pq.pop(); //popped off after saving it o the array
        
        j++; //next index whee we add

        pq.push(arr[i]); //pusheed the next unadded element to our pq
    }
    //one thing to keep in mind is that we have already put the elments to the left of j
    //at a ccorrect posn to so we need not worry about them while deciding the poaaition of element at j
    //if the were to be placed at i they will be alewady present in the priority queue
    //and added automatcally
    

    //the above for loop will be work till all elemnts are added to the loop 
    //at this point (size - k )elmeents would have been soted and our pq will have k elemetsb left
    //we ll put the next k elements in our arr in proper order till out pq is empty

    while (!pq.empty()){
        arr[j++]=pq.top();
        pq.pop();
    }
}
//think of it as an almost sorted arr

int main(){
    int size;
    int k;
    
    cout<<"Enter size of k soted array - ";
    cin>>size;

    cout<<"Enter value of k - ";
    cin>>k;

    int *arr = new int [size];

    for(int i{0} ; i<size ; i++){
        cin>>arr[i];
    }

    sort_ksorted(arr,size,k);

    for(int i{0} ; i<size ; i++){
        cout<<arr[i]<<" ";
    }



    delete [] arr;

}