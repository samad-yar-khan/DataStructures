#include <iostream>
using namespace std;
#include "PriorityQueue.h"

int main (){
    PriorityQueue p1;
    p1.insert(2);
    p1.insert(10);
    p1.insert(1);
    p1.insert(25);
   // p1.print_heap();
    cout<<p1.get();
    
}
