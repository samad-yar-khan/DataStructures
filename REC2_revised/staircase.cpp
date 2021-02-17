int staircase(int n){
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    //base case
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    
    int case_1 = staircase(n-1);
    int case_2 = staircase(n-2);
    int case_3 = staircase(n-3);
    
    return case_1+case_2+case_3 ;
}