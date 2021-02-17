//dynamic queues
#include<iostream>
using namespace std;
//#include "Queue_Arr.h"
#include "Queue_ArrD.h"

int main(){
    cout<<boolalpha;
    Queue <int> Q1;

Q1.enqueue (1);
Q1.enqueue(2);
Q1.enqueue(3);
Q1.enqueue(4);
Q1.enqueue(5);
//at this pt queue shoul be full
Q1.enqueue(6);
Q1.enqueue(7);


cout<<"The Queue is empty : "<<Q1.is_empty()<<"\n";
cout<<"First element of the queue "<<Q1.front()<<"\n";
cout<<"Size of the Queue "<<Q1.get_size()<<'\n';

cout<<"Elements leaving the queue one by one :\n";
cout<<Q1.deque()<<endl;
cout<<Q1.deque()<<endl;
cout<<Q1.deque()<<endl;
cout<<Q1.deque()<<endl;
cout<<Q1.deque()<<endl;
cout<<Q1.deque()<<endl;
cout<<Q1.deque()<<endl;
cout<<"All elements dequeued !"<<endl;

cout<<"The Queue is empty : "<<Q1.is_empty()<<"\n";
cout<<"First element of the queue "<<Q1.front()<<"\n";
cout<<"Size of the Queue "<<Q1.get_size()<<'\n';


}
