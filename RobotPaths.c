/**
 * @input A : Integer
 * @input B : Integer
 * 
 * @Output Integer
 */
 /* Recursive solution
 int isSafe(int i,int j,int A,int B)    {
     return (i>=0 && i<A && j>=0 && j<B);
 }
 int countPaths(int A,int B,int grid[][B],int i, int j,int *count)    {
     if(i==A-1 && j==B-1)
        *count=*count+1;
     else   {
         int xmoves[2]={0,1},ymoves[2]={1,0};
         int k;
         for(k=0; k<2; k++) {
             if(isSafe(i+xmoves[k],j+ymoves[k],A,B))    {
                countPaths(A,B,grid,i+xmoves[k],j+ymoves[k],count);
             }
         }
     }
 }
 */
 //Dynamic programming solution
int uniquePaths(int A, int B) {
    int i,j;
    int **grid=(int **)malloc(A*sizeof(int *));
    for(i=0; i<A; i++)  
        grid[i]=(int *)malloc(B*sizeof(int));
        
    for(i=0; i<A; i++)
        grid[i][B-1]=1;
    for(i=0; i<B; i++)
        grid[A-1][i]=1;
    
    
    for(i=A-2; i>=0; i--)   {
        for(j=B-2; j>=0; j--)   {
            grid[i][j]=grid[i+1][j]+grid[i][j+1];
        }
    }
    /*
    for(i=0; i<A; i++)   {
        for(j=0; j<B; j++)    {
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
    */
    return grid[0][0];
}

