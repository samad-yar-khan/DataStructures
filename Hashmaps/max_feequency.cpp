/*
Code : Maximum Frequency Number
Send Feedback
You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.
If two or more elements contend for the maximum frequency, return the element which occurs in the array first.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Output Format :
Most frequent element
Constraints :
0 <= N <= 10^8
Sample Input 1 :
13
2 12 2 11 12 2 1 2 2 11 12 2 6 
Sample Output 1 :
2
Sample Input 2 :
3
1 4 5
Sample Output 2 :
1
*/
#include<iostream>
#include<unordered_map>

using  namespace std;

class triplet {

	public:
	int index;
	int num;
	int freq;

	triplet(int index , int num , int freq){

		this->num = num;
		this ->freq = freq;
		this->index = index;
	}


};


int highestFrequency(int *input, int n){	 


	if(n==0){
		return 0;;
	}

    unordered_map <int , pair<int,int> > map ;
	map[input[0]].first = 0;
	map[input[0]].second = 1;
	triplet ans(0,input[0],1);



	
	for(int i{1} ; i<n ; i++){

		if(map.count(input[i]) < 1){ //areay not prenet in map;
			map[input[i]].first=i;
			map[input[i]].second = 1;

		}else{
			map[input[i]].second++;
			if(map[input[i]].second > ans.freq ){
				triplet new_ans(map[input[i]].first , input[i] , map[input[i]].second);
				ans = new_ans;
			}else if( map[input[i]].second == ans.freq  && map[input[i]].first < ans.index){
				triplet new_ans(map[input[i]].first , input[i] , map[input[i]].second);
				ans = new_ans;
			}

			
		}

	}
     	
     return ans.num;	
     	
 	}


int main(){

	cout<<"Enter size of array  - ";
	int n{0};
	cin>>n;

	int * arr = new int [n];

	cout<<"Enter elements \n";

	for(int i{0} ; i<n ; i++){
		cin>>arr[i];
	}

	cout<<"Most occuciing numbr is - "<<highestFrequency(arr,n)<<endl;

}
