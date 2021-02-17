bool checkAB(char input[]) {
	// Write your code here
    //base
    if(input[0]=='\0'){
        return true;
    }
    if(input[0]=='a'){
        if(input[1]=='b'&&input[2]=='b'){
            checkAB(input+3);
        	}
        else
            checkAB(input+1);
        }
    else 
        return false;
}


