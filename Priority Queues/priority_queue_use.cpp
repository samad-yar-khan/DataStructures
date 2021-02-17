#include<iostream>
using namespace std;
#include "PriorityQueue.h"

void case1(){

    MinPriorityQueue p;

    int a;
    cin>>a;
    while(a!=-1){
        p.insert(a);
        cin>>a;
    }

    cout<<"\nSorted elements - ";
    while  (!p.is_empty()){
        cout<<p.removeMin()<<" ";
    }
    cout<<"\n";
}

void case2(){

    MaxPriorityQueue p;

    int a;
    cin>>a;
    while(a!=-1){
        p.insert(a);
        cin>>a;
    }

    cout<<"\nSorted elements - ";
    while  (!p.isEmpty()){
        cout<<p.removeMax()<<" ";
    }
    cout<<"\n";
}


//using pqs for heap sort
int main(){


    cout<<"Do you want you elemenst to be in increasing order or decreasing oerder ?"<<endl;
    cout<<"enter 1 for sort and 2 for revrse sort (any other num if you want to quit?";
    int a;
    cin>>a;
    cout<<"Enter elements(-1) to stop input ";
    switch (a){
        case 1:case1();
               break;
        case 2:case2();
               break;
        default:cout<<"INVALID";
        }




}