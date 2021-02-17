#include <iostream>
using namespace std;
#include <queue>

int main(){
    priority_queue<int> pq;
    //ibuild priority queue is max_priorty queue by default
    //here functions are diff than the ones whichh we created

    //1 insert = push
    //2 get_max = top
    //3 delete max = pop
    //4 get_size = size
    //5 IsEmpty = empty

    cout<<"Enter elements - (-1 for no input)  " ;
    int a;
    cin>>a;

    while (a!=-1){
        pq.push(a);
        cin>>a;
    }
    cout<<"\n";
    cout<<"reverse sorted ";
    while (pq.size()!=0){
        cout<<pq.top()<<" ";
        pq.pop();    
    }
    
}