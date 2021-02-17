#include<iostream>
#include"trienode.h"
using namespace std;

int main(){

    Trie dictionary ;
    string input {"name"};
    dictionary.insert(input);
    input = "nae";
    dictionary.insert(input);

    dictionary.remove(input);
    cout<<dictionary.search("name");
}