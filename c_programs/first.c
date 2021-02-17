#include<stdio.h>
#include<string.h>

struct node
{
    struct node* next;
    int data;
};

int main(){

    FILE* file_ptr ;
    // file_ptr  = fopen("example.txt" , "w");
    // char dataToBeWritten[50] = "GeeksforGeeks-A Computer Science Portal for Geeks";

    // fputs(dataToBeWritten , file_ptr);
    // fputs("\n",file_ptr);
    // fputs("SUCK MY DIck" , file_ptr);
    // fclose(file_ptr);
   // File* new_file ;
    file_ptr = fopen("example.txt" , "r");
    char data_read[100];
    fgets(data_read , 100 , file_ptr);
    int i = 0 ;
    
    while (data_read[i]!='\0')
    {
        int check1 = 'a';
        int check2 = 'z';
        int diff = 'a'-'A';
        int a = (int)(data_read[i]);
        if(a>=check1 && a<=check2){
            data_read[i]=data_read[i]-diff;
        }
        i++;
        
    }
   data_read[0]='s';

    printf("%s" , data_read);
    fclose(file_ptr);  
    // file_ptr = fopen("example.txt","w");
    // fputs(data_read , file_ptr);
    // fclose(file_ptr);
}


