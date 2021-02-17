#include<cstring>
using namespace std;
#include<unordered_map>




char* uniqueChar(char *str){
    // Write your code 
    unordered_map<char , int> map;
    char* ans = new char[100];
    int j=0;
    
    for(int i =0 ; str[i] != '\0' ; i++)
    {
        if(map.count(str[i]) < 1){
            map[str[i]]=1;
            ans[j]=str[i];
            j++;
        }
        
    }
    
    return ans;
}