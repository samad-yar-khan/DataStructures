 
 void help(int input[], int size, int k ,int *output,int size_2){
 	
     if(size==0){
         if(k==0){
             for(int i=0;i<size_2;i++){
                 cout<<output[i]<<" ";
             }
             cout<<endl;
             return;
         }
         else{
             return;
         }
     }
     int *output_1 = new int [1000];
     int *output_2 = new int [1000];
     for(int i =0 ; i<size_2;i++){
        output_1[i]=output[i];
        output_2[i]=output[i];
        }
    help(input+1,size-1,k,output_1,size_2);
    output_2[size_2]=input[0];
    help(input+1,size-1,k-input[0],output_2,size_2+1);
     
    delete [] output_1;
    delete [] output_2;
}


void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    int *arr = new int [size]; 
    help(input,size,k,arr,0);
    delete []arr;
}
