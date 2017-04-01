//Function to convert Excel column name to number

int titleToNumber(char* A) {
    
    int result=0,i,len=strlen(A);
    
    for(i=len-1; i>=0; i--) {
        result+=pow(26,len-i-1)*(A[i]-'A'+1);
    }
    
    return result;
}
