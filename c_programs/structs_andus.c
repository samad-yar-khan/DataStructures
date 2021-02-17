#include<stdio.h>
#include<string.h>

struct student {
    char name[100];
    int age ;
    int marks;
};

int main(){

    struct student S1 = {"SAmad YAR KHAN" , 10 , 20};
    
    printf("%s",S1.name);
    return 0;
}
