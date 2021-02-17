//better method 
//earlier soulutions used nlogn time
//now in thus method we try to solve this in nlogk time

#include <iostream>
using namespace std;
#include <queue>
#include <vector>
//obect
class triplet {

    public :
    int array_num ;
    int my_index ;
    int val;

    triplet (int arr_num , int val , int index){
        this->array_num = arr_num;
        this->val = val;
        this->my_index = index;

    }
};

//comparator class
class Comp {
    public :

    bool operator()(triplet *a,triplet* b) {
        return a->val > b->val;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>*> input){
    priority_queue<triplet* , vector<triplet*> , Comp> pq;

    //k size pq of triplets which prioritises them based on value
    for(int i{0} ; i<input.size() ; i++ ){
        triplet* tripx  = new triplet(i , input[i]->at(0) , 0);
        pq.push(tripx);
    }

    vector<int> ans; 

    while (pq.size() != 0){

        triplet *temp = pq.top();
        pq.pop();

        int arr_num = temp->array_num ;
        int my_index = temp->my_index;
        int val = temp->val;

        my_index++; //index of next element to be added

        ans.push_back(val);

        if(my_index < input[arr_num]->size()){
            
            triplet* next_triplet = new triplet(arr_num , input[arr_num]->at(my_index) , my_index );
            pq.push(next_triplet);
        }
        delete temp;
    }
    return ans;

}

int main() {

triplet *a = new triplet(0 , 1 , 0);
triplet *b = new triplet (1 ,5 , 0);
triplet *c=  new triplet (2 , 3 ,0);

priority_queue<triplet* , vector <triplet*> , Comp> pq;

pq.push(a);
pq.push(b);
pq.push(c);

cout<<pq.top()->val<<endl;
pq.pop();
cout<<pq.top()->val<<endl;
pq.pop();
cout<<pq.top()->val<<endl;
pq.pop();

delete a;
delete b;
delete c;
}