#include <iostream>
using namespace std;
#include<vector>
#include<queue>




class triplet {
    public :

    int age;
    int ht;

    triplet(int age , int ht){
        this->age = age;
        this->ht = ht;
    }
    


};

class Comp{
	public:          //new element        parent
	bool operator ()(triplet *a       ,	  triplet *b)	{
	return a->age > b->age;
    }

};


int main()	{
	priority_queue<triplet* ,vector<triplet*>,Comp>	pq;
	// pq.push(40);
	// pq.push(320);
	// pq.push(42);
	// pq.push(42);
	// pq.push(65);
	// pq.push(12);
    // pq.push(245);
	// cout<<pq.top()<<endl;
     
    triplet* a = new triplet(1 , 2);
    triplet* b= new triplet(3, 4);
    triplet* c = new triplet(4, 5);


    pq.push(a);
    pq.push(b); 
    pq.push(c);

    triplet *temp = pq.top();

    cout<<temp->age<<" "<<temp->ht<<endl;

    


    
	return 0;

}
