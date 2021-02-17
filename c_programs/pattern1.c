#include<stdio.h>
#include<stdbool.h> 

int main(){

    char arr[INT_MAX];
    printf("Enter string - ");
    gets(arr);

    bool first1 = false;
    bool middle0 = false;
    int total=0;

    int i = 0 ;
    while (arr[i]!='\0'){

        if(arr[i] == 1){
            if(middle0==true){
                middle0 = false;
                total=total+1;
            }else{
                first1 = true;
            }
        }else{
            if(first1 == true){
                middle0 = true;
            }
        }

        i++;
    }
    printf("%d",total);
return 0;

}