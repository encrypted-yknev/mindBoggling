/**
 * @input A : Read only ( DON'T MODIFY ) 2D integer array ' * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 * 
 * @Output Integer array. You need to malloc memory for result array, and fill result's length in length_of_array
 */
int* spiralOrder(const int** A, int n11, int n12, int *length_of_array) {
	 *length_of_array = n11 * n12; // length of result array
	 int *result = (int *) malloc(*length_of_array * sizeof(int));
	 
	 int xs=0,ys=0,xe=n11,ye=n12,i,k=0;
	 
	 while(xs < xe && ys < ye)    {
	     
	     for(i=ys; i<ye; i++)
	        result[k++]=A[xs][i];
	     xs++;

	     for(i=xs; i<xe; i++)  
	        result[k++]=A[i][ye-1];
	     ye--;
	     
	     if(xs < xe)    {
    	     for(i=ye-1; i>=ys; i--)
    	        result[k++]=A[xe-1][i];
    	     xe--;
	     }
        
         if(ys < ye)    {
    	     for(i=xe-1; i>=xs; i--)
    	        result[k++]=A[i][ys];
    	     ys++;
         }
	 }
	 return result;
}
