int partition(int * str,int size){
   
   int count=0;
   for(int i=1;i<size;i++){
       if(str[0] >= str[i]){
         count++;
        }
    }
        
    int temp=str[0];
    str[0]=str[count];
    str[count]=temp;
     
    int i=0,j=size-1;
    while( i<count && j>count){
        if( str[i]<=str[count]  &&  str[j]>str[count]){
            i++;
            j--;
            }
         else{
             if(str[i]>str[count]  &&  str[j]<=str[count]){
              int temp=str[i];
              str[i]=str[j];
              str[j]=temp;  
              i++;
              j--; 
                 }
              if(str[i]>str[count]  &&  str[j]>str[count]){
                  j--;
                  }
              if(str[i]<=str[count]  &&  str[j]<=str[count]){
                  i++;
                  }
             }
        }
     return count;
    }


void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    if(size<=0||size==1){
         return;          
         }
     
     int partition_index = partition(input,size);
     quickSort(input,partition_index); //partition index is size of eeft sie array
     quickSort(input+partition_index+1,size-partition_index-1);

}