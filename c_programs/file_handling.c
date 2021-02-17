#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){

    char str[100];
    printf("Enter a string : ");
    gets(str);
    


    FILE* file_ptr = fopen("New_file.txt" , "w");

    if(file_ptr == NULL ){
        printf("File not found !\n");
    }else{

        printf("FILE OPEN\n");

        if(strlen(str)!=0){
            fputs(str,file_ptr);
        }
    
    }

    fclose(file_ptr);
    printf("File closed \n");

    file_ptr = fopen("New_file.txt" , "r");

    char temp[100];
    
    if(file_ptr!=NULL){

        printf("File opened to be read.\n");
     
        fgets(temp,100,file_ptr);
    
        printf("%s\n" , temp);

    }

    fclose(file_ptr);


    return 0;

}


