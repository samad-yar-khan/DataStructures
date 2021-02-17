#include<iostream>
using namespace std;
#include<string>
#include<vector>

//functions rtakes a string , the char to be found , the index form which we gotta search 
//if char is found we add it to our string and return the index at which its found
int index_finder (string s , int index , char a , string &ans){
    
    int temp = index;

    
    while(s[temp]!='\0'){
        if(a==s[temp]){
            ans = ans +a;
            return temp+1;

        }
        temp++;
    }

    return index;
}

void max_substr(string s1 , string s2 ,vector <string> &vec){

    string ans;

    int outer_index=0;
    int index=0;

    while (s1[outer_index]!='\0'){
        index = index_finder(s2,index,s1[outer_index],ans);
        outer_index++;
    }

   vec.push_back(ans);
}
void helper (string s1 , string s2 , vector<string> &vec){
    if(s1.length() == 0){
        return;
    }

    max_substr(s1,s2,vec);
    max_substr(s1.substr(1),s2,vec);
}
int main(){

    string s1 = "geeksforgeeks";
    string s2 = "geesk";
    vector<string> vec;
    helper(s1,s2,vec);

    int i=0;
    int len =0;

    for(int j{0} ; j<vec.size() ;j++){
        int len_j = vec[j].length();
        if(len_j>len){
            len = len_j;
            i=j;
        }
    }

    cout<<vec[i]<<endl;
}