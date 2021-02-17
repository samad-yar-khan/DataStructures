#include<iostream>
using namespace std;
#include <vector>

class MinPriorityQueue {

    private:
    vector<int> pq; //my pqs heap will be base on this vector

    public:   

    //default constructor    
    MinPriorityQueue (){

    }

    int get_size(){
        return pq.size();
    }

    bool is_empty (){
        return pq.size()==0;
    }

    void insert (int x){
        pq.push_back(x); //put my last eleent at the end - CBT property

        //now we have to satisfy the min heaporder property
        int my_index = pq.size()-1; //last index

        int parent = ( my_index -1 )/2;

        //up heapify process
        //aded to the rght most empty slot of my tree in complete bnaty tree fashion
        //
        while (my_index > 0 && pq[parent]>pq[my_index]){
           //swapping 
            int temp = pq[parent];
            pq[parent]= pq[my_index];
            pq[my_index]=temp;

            //change my index 
            my_index=parent;
            parent = ( my_index -1 )/2;
        
        }
    }

    int get_min (){
        if(pq.size()==0){
            return 0;
        }
        return pq.at(0);
    }

    void print_heap(){
        for (int i=0 ; i<pq.size() ;i++){
            cout<<pq.at(i)<<":";
            int child_1 = 2*i +1;
            int child_2 = 2*i +2;

            if(child_1<pq.size()){
                cout<<pq.at(child_1)<<",";
            }
            if(child_2<pq.size()){
                cout<<pq.at(child_2);
            }

            cout<<endl;

        }
    }

    // int removeMin() {
    //     // Complete this function\
        
    // 	//edge case
    //     if(pq.size()==0){
    //         return 0;
    //     }
        
    //     //swap
    //     int limit = pq.size()-1;
        
    //     int temp1 = pq.at(0);
    //     pq.at(0)=pq.at(limit);
    //     pq.at(limit)=temp1;
    //     pq.pop_back();//deleted last element
    //     --limit;
        
    //     //down heapiify
        
    //     int my_index = 0;
    //     int lci = 2*my_index +1;
    //     int rci= 2*my_index +2;
        
    //     while(my_index < limit){ //till ii become thelast element
            
	// 		if(lci<=limit && rci<=limit){ //both child  exist
                
    //             if(pq.at(lci)>pq.at(my_index) && pq.at(rci)>pq.at(my_index)){ //perfecr heap
    //                 break;
    //             }else if(pq.at(lci)<pq.at(my_index) && pq.at(rci)<pq.at(my_index)){
    //                 int mi= (pq.at(lci)<pq.at(rci))?lci:rci;
                    
    //                 int temp = pq.at(my_index);
    //                 pq.at(my_index) = pq.at(mi);
    //                 pq.at(mi)=temp;
                    
    //                 my_index = mi;
                    
    //                 lci=2*my_index+1;
    //                 rci = 2*my_index+2;
    //             }else if(pq.at(lci)<pq.at(my_index) &&  pq.at(rci)>pq.at(my_index)){
                    
    //                 int temp = pq.at(my_index);
    //                 pq.at(my_index) = pq.at(lci);
    //                 pq.at(lci)=temp;
                    
    //                 my_index = lci;
                    
                             
    //                 lci=2*my_index+1;
    //                 rci =2*my_index+2;
    //             }else if(pq.at(rci)<pq.at(my_index)){
                  
    //                 int temp = pq.at(my_index);
    //                 pq.at(my_index) = pq.at(rci);
    //                 pq.at(rci)=temp;
                    
    //                 my_index = rci;
                    
                             
    //                 lci=2*my_index +1;
    //                 rci=2*my_index +2;
    //             }   
    //         }else if(lci<=limit && rci>limit){
    //             //last node if there is not child
    //             //no further checks needed;
    //     	    if(pq.at(lci)<pq.at(my_index)){
                  
    //                 int temp = pq.at(my_index);
    //                 pq.at(my_index) = pq.at(lci);
    //                 pq.at(lci)=temp;
    //                 my_index = lci;
                    
                             
    //                 lci=2*my_index+1;
    //                 rci = 2*my_index+2;
    //             }else{
    //                  break;
    //             }

                
    //         }else{
    //             break;
    //         }
    //     }
    //         return temp1;
    //     }
    
    int removeMin(){
        
        if(pq.empty()){
            return 0;
        }

        int ans = pq.at(0); //we need to return this so we juts store this in ans
        //swap

        int limit = pq.size()-1;
        pq.at(0)=pq.at(limit);
        pq.at(limit)=ans; //although this doenst make much sense t just signfies the swapping 

        //delete last element
        pq.pop_back();
        limit--;

        int my_index = 0;
        int left_child_index = 2*my_index + 1;
        int right_child_index = 2*my_index + 2;


        while(!(left_child_index>limit)){ //iterate till our left child goes out of bounds which mean that .which means that we have reached a leaf node
        int min_index = my_index;
        //finding the min

        if(pq.at(min_index)>pq.at(left_child_index)){
            min_index=left_child_index;
        }
        //before comparing right and  min we must see if right even exists or not
        if( right_child_index<pq.size() && pq.at(min_index)>pq.at(right_child_index)){
            min_index=right_child_index;
        }

        //if my eleemnt is min index break out else we just swap and find new chilren indices

        if(my_index==min_index){
            break;
        }else{
            int temp = pq.at(my_index);
            pq.at(my_index)= pq.at(min_index);
            pq.at(min_index)=temp;

            my_index=min_index;
            left_child_index = 2*my_index + 1;
            right_child_index = 2*my_index + 2;
        }


        }
        return ans;

        
    }
    



};

class MaxPriorityQueue{
    private:

    vector <int> pq;  //same as minpq we need to create a heap

    public :
    
    //constructor
    MaxPriorityQueue () {

    }

    int getSize (){
        return pq.size();
    }

    bool isEmpty (){
        return pq.size() == 0;
    }

    void insert (int x){

        pq.push_back(x); //pushed it to the end of the vec or last element in cbt

        int my_index = pq.size()-1;
        int parent_index = ( my_index -1 )/2;

        //either my parents becoes larger than me or i reach the top most node in the cbt
        while (my_index > 0 && pq.at(my_index) > pq.at(parent_index)){

            int temp = pq.at(my_index);
            pq.at(my_index) = pq.at(parent_index);
            pq.at(parent_index)= temp;

            my_index = parent_index;
            parent_index = (my_index-1)/2;
        }
    }

    int getMax (){

        if(pq.empty()){
            return 0;
        }

        return pq.at(0);

    }

    int removeMax(){

        if(pq.empty()){
            return 0; 
        }
    
        //swap
        int ans = pq.at(0);
        pq.at(0)=pq.at(pq.size() - 1);
        pq.pop_back();

        //seting child induces
        int my_index =0;
        int left_child_index = 2*my_index + 1;
        int right_child_index = 2*my_index + 2;

        //iteralte till you have no children left or you dont neeed to donw heapifyy anymore    
        while(left_child_index < pq.size()){
            int max_index = my_index;

            if(pq.at(left_child_index) > pq.at(max_index) ){
            max_index = left_child_index;
            }

            if(right_child_index <pq.size()  && pq.at(right_child_index) > pq.at(max_index)){
                max_index = right_child_index;
            }

            if(my_index==max_index){
                break;
            }else{
                int temp = pq.at(my_index);
                pq.at(my_index)=pq.at(max_index);
                pq.at(max_index)=temp;

                my_index=max_index;

                left_child_index = 2*my_index + 1;
                right_child_index = 2*my_index + 2;

            }

        }
        return ans;
    }

    
};
