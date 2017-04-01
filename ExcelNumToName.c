//Function to convert Excel column number to corresponding Column name

char* convertToTitle(int A) {
     int i,k=0,rem;
     char ch;
	 char *result = (char *)malloc(100 * sizeof(char));
	 char *result1 = (char *)malloc(100 * sizeof(char));
	 while(A > 0)   {
	     if(A%26==0)    {
	         ch='Z';
	         A=A/26-1;
	     }
	     else   {
            rem = A%26;
            ch=(char)('A'+rem-1);
            A=A/26;
	     }
	     //printf("%c\n",ch);
	     result1[k++]=ch;
	     
	 }
	 result1[k]='\0';
	 for(i=0; i<k; i++) 
	    result[i]=result1[k-i-1];
	 result[k]='\0';   
	 return result;
}
