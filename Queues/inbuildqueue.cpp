#include <iostream>
using namespace std;
#include <queue>
#include <stack>

 //INBUILD QUEUE
 //enque == push
 //deque == pop 
 //getsize == size
 //is_empty = empty
 //front == front

// void (){
//     cout<<"enter data - ";
//    int i=0;
//    cin>>i;

//    while (i!=-1)
//    {
      
//    }
   


int main(){
    queue <int > Q1;
    cout<<boolalpha;
    cout<<"Queue is empty :"<<Q1.empty();
    cout<<noboolalpha;

    cout<<"\nFirst element of queue :"<<Q1.front()<<endl;
    cout<<"Filling queue : ";
    Q1.push(1); // woerks like enque 
    Q1.push (2);
    Q1.push(3);
    Q1.push(4);
    Q1.push(5);
    cout<<boolalpha;
    cout<<"Queue is empty "<<Q1.empty();
    cout<<"\nSize of queue : "<<Q1.size();
    cout<<"\nFirst element of queue :"<<Q1.front()<<endl;
    cout<<noboolalpha;
    cout<<"**********************Stack vs queue***********************\n";
    cout<<"printing front element of QUEUE and dequeing till my queue is empty \n";
    while (!Q1.empty()){
        cout<<Q1.front()<<" ";
        Q1.pop();
    }

    cout<<"\nFilling stack in same order and popping of elements - \n";
    stack <int> S1;
    S1.push(1);
    S1.push(2);
    S1.push(3);
    S1.push(4);
    S1.push(5);

    while (!S1.empty()){
        cout<<S1.top()<<" ";
        S1.pop();
    }





 
}