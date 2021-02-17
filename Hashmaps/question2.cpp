/*

Longest consecutive Sequence
Send Feedback
You are given with an array of integers that contain numbers in random order. Write a program to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains consecutive elements. Order of elements in the output is not important.
Best solution takes O(n) time.
If two sequences are of equal length then return the sequence starting with the number whose occurrence is earlier in the array.
Input Format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Constraints :
0 <= n <= 10^8
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
Sample Output 1 :
8 
9 
10 
11 
12
Sample Input 2 :
7
3 7 2 1 9 8 1
Sample Output 2 :
7
8
9
Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but output should be [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array.
Sample Input 3 :
7
15 24 23 12 19 11 16
Sample Output 3 :
15 
16

*/

#include<iostream>
#include <vector>
#include<unordered_map>
using namespace std;

class node{

    public :
    int data;
    node *next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~node(){
        delete this->next;
    }

};

class linked_list{   
    public:

    node* head;
    node* tail;
    int size;   

    linked_list( ){
        this->head = NULL;
        this->tail = NULL;
        size=0;
    }

    void append(int data){
        if(head == NULL){
            head = new node(data);
            tail = head;
            size++;
        }else{
            tail->next = new node(data);
            tail = tail->next;
            size++;
        }
    }

    //mere eement iske end mai ayega
    void post_connect (linked_list L){
        this->tail->next = L.head;
        this->tail=L.tail;
        this->size = this->size + L.size;
    }

    

};

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){

    pair<int , int > ans;

    ans.first =0; //key
    ans.second =0 ; //len

    unordered_map<int , linked_list>  map;

    for(int i{0} ; i<n ; i++){

        if(map.count(arr[i]) < 1){

            map[arr[i]].append(arr[i]);

            bool check1 = false;
            //iske peeche koi seq hai
            if(map.count(arr[i]-1) > 0){
                int pre = arr[i]-1;
                map[pre].append(arr[i]);
                map[arr[i]]=map[pre]; //shallow
                check1=true;
            }

            //iske bad koi  seq hai
            if(map.count(arr[i]+1) > 0){
            
            map[arr[i]].post_connect(map[arr[i]+1]); 
            map[arr[i]+1].head = map[arr[i]].head;
            map[arr[i]+1].size = map[arr[i]].size;
            // if(map.count(arr[i-1]) > 0){
            //     map[arr[i]-1].size = map[arr[i]].size;
            // }
            }

            if(map[arr[i]].size > ans.second){
                ans.first = arr[i];
                ans.second = map[arr[i]].size;
                
            }


            node * temp = map[arr[i]].head ;
            cout<<map[arr[i]].size<<"||";
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<"\n";
        }
    }

    vector<int> answer;

    node*head = map[ans.first].head;


    while (head!=NULL){

        answer.push_back(head->data);
        head=head->next;

    }
    cout<<ans.first<<" "<<ans.second<<endl;
    return answer;
}


//error in code is the faillure to upadate to chnage size data member for each entry
//to do that we need to use pttr to linked list class
//for one seqence only one ll will bbe preesnt and it adress will be with all iits members

//the second approach is way better
//for this qn
int main(){
    
    int arr[13]{2 ,12, 9 ,16 ,10 ,5 ,3 ,20 ,25 ,11 ,1 ,8 ,6};
    vector<int> ans = longestConsecutiveIncreasingSequence(arr,13);

    for(auto s:ans){
        cout<<s<<" ";
    }
}