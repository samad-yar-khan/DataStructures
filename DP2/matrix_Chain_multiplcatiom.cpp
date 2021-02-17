#include <iostream>
#include<climits>
using namespace std;

// class club{

//     public :
//     pair <int , int >  dimensions;
//     int operations ;

//     club(){
//         this->dimensions.first = 0;
//         this->dimensions.second = 0 ;
//         this->operations = 0;
//     }
// };

// club mcm(int *arr , int n ){

//     //only one array
//     if( n < 1){
//         club ans;
//         return ans;
//     }

//     if(n == 2){
//         club ans ;
//         ans.dimensions.first = arr[0];
//         ans.dimensions.second = arr[1];
//         ans.operations = 0;
//         return ans;
//     }

//     //i either muliply the first two , or i  let the rest multiple first and then multiply mine to it
//     club case1  = mcm(arr+1 , n-1);//if we leave the first 
//     club case2 ;
//     case2.operations = INT_MAX;
//     if(n>3){
//         case2 =  mcm(arr+2 , n-2); //if we multiply first two , we deal with their pruduct and the rest of the prodcuta t the end
//         int o1 = arr[0] *arr[1] *arr[2]; //multiplying first 2 matrces , will have these many opertains and new 
//         //matrix will have arr[0]*arr[2] demenstion
//         int o2 = arr[0]*case2.dimensions.first*case2.dimensions.second; 
//         case2.dimensions.first = arr[0];
//         case2.operations+=o1+o2; //add out first two ka multiplacation + final two matices ka multpaction
//     }

//     //we must do our work on the cases
//     case1.operations  +=  arr[0]*case1.dimensions.first*case1.dimensions.second;
//     case1.dimensions.first = arr[0];

//     //so case one comtains the case where our array is multiply at the end
//     if(case1.operations < case2.operations){
//         return case1;
//     }else{
//         return case2;
//     }
  

// }

int mcm( int* arr , int S , int E ){
    
    //base case
    if(S==E || E-S == 1){
        return 0 ;
    }

    //IND H
    int min_c = INT_MAX;
    for(int i = S+1 ; i < E ; i++ ){

        int case1 = mcm(arr , S , i);
        int case2 = mcm(arr , i , E);
        int my_multiplication = arr[S]*arr[i]*arr[E];
        int ans = case1 + case2 + my_multiplication;

        min_c = min( min_c , ans );

    }

    return min_c;

}

int mcm_memo( int* arr , int S , int E , int **output ){
    
    //base case
    if(S==E || E-S == 1){
        return 0 ;
    }

    if(output[S][E] != -1){
        return output[S][E];
    }

    //IND H
    int min_c = INT_MAX;
    for(int i = S+1 ; i < E ; i++ ){

        int case1 = mcm_memo(arr , S , i , output);
        int case2 = mcm_memo(arr , i , E , output);
        int my_multiplication = arr[S]*arr[i]*arr[E];
        int ans = case1 + case2 + my_multiplication;

        min_c = min( min_c , ans );

    }

    output[S][E] = min_c;
    return output[S][E];
    
}

int mcm_MEMO(int *arr , int n){
    
    int**output = new int*[n+1];
    for(int i = 0 ; i <= n ; i++){
        output[i] = new int[n+1];
    }

    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= n ; j++){
            output[i][j]=-1;
        }
    }

    int ans = mcm_memo(arr , 0 , n ,output);

    for(int i = 0 ; i <= n ; i++){
        delete output[i];
    }
    delete [] output;
    return ans;
}

int mcm_dp(int *arr , int n){

    int**output = new int* [n+1];
    
    for(int i = 0 ; i <= n ; i++){
        output[i] = new int[n+1];
    }

    //initialise the answers we know 
    for(int i = n ; i >= 0 ; i--){ //i represensts atrting index
        for(int j = 0 ; j<=n ; j++){ //j represensts end index

            if(i >= j || j-i ==1){
                output[i][j] = 0; //only one matrix or no matrix
            }else{

                int minC= INT_MAX ;
                for(int k = i+1 ; k < j ; k++){
                    int ans = output[i][k] + output[k][j] + arr[i]*arr[j]*arr[k];
                    minC= min(minC , ans);
                }

                output[i][j] = minC;
             }

        }
    }

    int t = output[0][n];

    for(int i = 0 ; i <= n ; i++){
        delete output[i];
    }
    delete [] output;

    return t;

}

int main(){
    int arr[6] = {2 , 4 , 6 , 12 , 11, 21};
    cout<<mcm_dp(arr, 5 );
}