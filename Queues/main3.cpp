#include<iostream>
using namespace std;
#include "Queue_LL.h"

int main(){

    Queue <int> Q1;
    cout<<"First in queueu "<<Q1.front();
    cout<<"\ninitial size of Q1 :"<<Q1.get_size()<<endl;
    cout<<"Q1 is empty - "<<Q1.is_empty();

    for(int i =0 ; i<10; i++){
        Q1.enqueue(10*i);
    }

    cout<<"\nfirst in queue "<<Q1.front();
    cout<<"\nfinal size of Q1 :"<<Q1.get_size()<<endl;
    cout<<"Q1 is empty - "<<Q1.is_empty();


    cout<<"\norder of elememnts going out of the queue"<<endl;
    while (!Q1.is_empty()){
        cout<<Q1.dequeue()<<" ";
    }
    cout<<'\n';



return 0;
}