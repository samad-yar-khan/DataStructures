/*
Minimum bracket Reversal
Send Feedback
Given a string expression which consists only ‘}’ and ‘{‘. The expression may not be balanced. You need to find the minimum number of bracket reversals which are required to make the expression balanced.
Return -1 if the given expression can't be balanced.
Input Format :
String S
Output Format :
Required count
Sample Input 1 :
{{{
Sample Output 1 :
-1
Sample Input 2 :
{{{{}}
Sample Output 2 :
1

 */
 
 #include <iostream>
 using namespace std;
 #include <stack>
 int countBracketReversals(char input[]);

 int main(){
     cout<<"Enter brackets to be knoww number of reversels needed - ";
     char arr[100]{};
     cin>>arr;
    cout<<"NUMBER OF REVERSELS NEEDED - "<<countBracketReversals(arr);

 }


int countBracketReversals(char input[]){
	// Write your code here
    
    if(input==NULL||input[0]=='\0'){
        return 0;
    }
    int count =0;
    stack <char> brackets;
    int i=0;
    while (input[i]!='\0'){
        if(input[i]=='{'){
            // if(!brackets.empty()&&brackets.top()=='}'){
            //     brackets.pop();
            //     i++;
            //     count+=2;
            // }
            // else{
            brackets.push(input[i]);
            i++;
            count++;
        }
        else{
            if(!brackets.empty()&&brackets.top()=='{'){
                brackets.pop();
                count--;
                i++;
            }else{
            brackets.push(input[i]);
            i++;
            count++;
            }
        }
	}
    int changes =0;
    while(!brackets.empty()){
        int top = brackets.top();
        brackets.pop();
        
        if(brackets.empty()){
            return- 1;
        }
        
        if(brackets.top()==top){
            brackets.pop();
            changes++;
        }
        else{
            brackets.pop();
            changes+=2;
        }
    }
    
    return changes;
    
}