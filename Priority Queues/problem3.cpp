/*
Merge K sorted arrays
Send Feedback
Given k different arrays, which are sorted individually (in ascending order). You need to merge all the given arrays such that output array should be sorted (in ascending order).
Hint : Use Heaps.
Input Format :
Line 1 : Integer K
Line 2 : Arrays 1 size (n1)
Line 3 : Array 1 elements (separated by space)
Line 4 : Array 2 size (n2)
and so on for next arrays
Sample Input 1 :
4
3
1 5 9
2
45 90
5
2 6 78 100 234
1
0
Sample Output 1 :
0 1 2 5 6 9 45 78 90 100 234
*/

//first approach was to use a a min priority queue and store all elements of
//all vectros in it the, just store min eeleemnts each time in another vecroe and delete that 

//aproach 2 we just work with one vector , turn it into a max_heap
//delete elements such that each time a elment is at the end

#include<iostream>
using namespace std;
#include<vector>

vector<int> mergeKSortedArrays(vector<vector<int>*> input){

    vector<int> ans;
    int my_size; 

    for(int i{0} ; i<input.size() ; i++){

        for(int j{0} ; j<input[i]->size()  ; j++){

            ans.push_back(input[i]->at(j));

            //up heapify according to max_heap

            int my_index = ans.size() - 1;

            while (my_index > 0){
                int parent_index = (my_index-1)/2;
                
                if(ans.at(parent_index) > ans.at(my_index) ){
                    break; //correct posn
                }else{
                    int temp = ans.at(parent_index);
                    ans.at(parent_index)=ans.at(my_index);
                    ans.at(my_index)=temp;
                    
                    my_index=parent_index;
                }

            }
        }
    }

    my_size = ans.size();

    while(my_size > 1){

        //swap  first and last
        int temp =   ans.at(my_size-1);
        ans.at(my_size-1) = ans.at(0);
        ans.at(0) = temp;
        my_size--;

        int my_index = 0;
        int lci = 2*my_index+1;
        int rci = 2*my_index+2;

        //down heapify
        while (lci < my_size){
            
            int max_index = my_index;
            if(ans.at(lci) > ans.at(max_index)){
                max_index = lci;
            }

            if(rci < my_size && ans.at(rci) > ans.at(max_index)){
                max_index = rci;
            }

            if(max_index == my_index){
                break;
            }else{
                int temp_2 = ans.at(my_index);
                ans.at(my_index) = ans.at(max_index);
                ans.at(max_index)= temp_2;

                my_index=max_index;
                lci = 2*my_index+1;
                rci = 2*my_index+2;
             }

        }
    }

    return ans;



}