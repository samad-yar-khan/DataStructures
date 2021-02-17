#include<iostream>
using namespace std;

int fib1(int n){

    //base
    if(n<=1){
        return n;
    }

    //ih
    int a = fib1(n-1); //these are blind recursive calls
    int b = fib1(n-2);    

    //is
    return a+b;

}

//memotzation top down approach
//in this aappproach we save our ans as we get them and work from top to down ,
// we call for toop values first ans the bottom gets caclulated and rtuen us the desired values
//this usaally involves recusrion
int fib_helper (int *arr , int n){
    if(n<=1){
        return n;
    }

    //we check if our answer exists
    //if ans exists we return it
    if(arr[n] != -1) {
        return arr[n];
    }

    //if ans doesnt exits we calculate the ans then we , store it and then we return 

    int a = fib_helper(arr , n-1);
    int b = fib_helper(arr , n-2);

    arr [n] = a+b;
    return arr[n];

}
int fib2(int n){
    int *arr = new int [n+1];
    
    for(int i{0} ; i < n+1 ; i++){
        arr[i]=-1;
    }

    int ans = fib_helper (arr , n);
    delete [] arr;
    return ans;
}

//dynamic programming approach

int fib_d (int n){
    int *ans = new int [n+1];
    ans[0] = 0; //fib 0 
    ans[1] = 1; //fib 1

    for(int i=2 ; i <= n ; i++ ){

        ans[i] = ans[i-1] + ans[i-2]; 

    }

    int a = ans[n];
    delete ans;
    return a;
}

int main(){

    int  n{0};
    cout <<"Enter n ";
    cin>>n;

    cout<<fib_d(n)<<endl;
    cout<<fib1(n)<<endl;
    cout<<fib2(n)<<endl;

}






