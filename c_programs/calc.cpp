#include<iostream>
#include<cmath>
using namespace std;

double val(double n){
    return sin(n) - log(n) + exp(n);

}

int main(){
    double init;
    double sum1 = 0;
    double sum2=0 ;
    double sum3 = 0;
    int n = 0;
    double h = 0.0;
    cout<<"enter initital value , n , h";
    cin>>n>>h;
    double *array = new double[n+1];

    for(int i = 0 ; i <=n ; i++){
        
        array[i] = val(i*h + init);
        cout<<array[i]<<endl;
    
    }

    sum1 = array[0]+array[n];
    for(int i = 1 ; i < n ; i++){
        if(i%3==0){
            sum2+=array[i]; //multiples of 3
        }else{
            sum3 += array[i]; //n
        }
    }

    cout<<sum1<<" "<<sum2<<" "<<sum3<<endl;
    cout<<3*(h/8)*(sum1 + 2*sum2 + 3*sum3)<<endl;

    delete [ ] array;
}