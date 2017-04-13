/*
Chandan has drawn a square of size N 2x N 2 on a piece of cross-section
 paper and divided it into N 2 smaller squares of size N x N. 
 Ram wants to write numbers from 1 to N 2 in the squares of the paper,
 (let's call them cells) in order to obtain a magic square. 
A magic square is a square in which:
1.  There is one in the left upper cell.
2.  There are no repeating numbers in any column.
3.  There are no repeating numbers in any row.
4.  There are no repeating numbers in any of the smaller squares.
5.  If we swap two smaller squares having a common side, then we obtain square satisfying properties 2 to 4.
Ram has already written several numbers. Determine if it is possible to fill the remaining cells and obtain a magic square.
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define rows 9
#define cols 9

bool isRowSafe(int mat[][cols],int i,int k)    {
    int x;
    for(x=0; x<cols; x++)   {
        if(mat[i][x]==k)
            return false;
    }
    return true;
}
int isColSafe(int mat[][cols],int i,int k) {
    int x;
    for(x=0; x<rows; x++)   {
        if(mat[x][i]==k)
            return false;
    }
    return true;
}
int isMatSafe(int mat[][cols],int i,int j,int k)  {
    int a,b;
    for(a=i; a<i+sqrt(rows); a++) {
        for(b=j; b<j+sqrt(cols); b++) {
            if(mat[a][b]==k)
                return false;
        }
    }
    return true;
}

bool isSafe(int mat[][cols],int i,int j,int k)  {
    return (isRowSafe(mat,i,k) && isColSafe(mat,j,k) && isMatSafe(mat,i-(i%(int)sqrt(rows)),j-(j%(int)sqrt(cols)),k));
}

bool findUnassignedCell(int mat[][cols],int *i,int *j)    {
    for(*i=0; *i<rows; (*i)++)   {
        for(*j=0; *j<cols; (*j)++)   {
            if(mat[*i][*j]==0)
                return false;
        }
    }
    return true;
}
bool solveSudoku(int mat[][cols])    {
    
    int i,j,k;
    if(findUnassignedCell(mat,&i,&j))
        return true;
    for(k=1; k<=rows; k++)  {
        if(isSafe(mat,i,j,k))   {
            mat[i][j]=k;
            if(solveSudoku(mat))
                return true;
            else
                mat[i][j]=0;
        }
    }
    return false;
    
}

void printSudoku(int mat[][cols])   {
    int i,j;
    for(i=0; i<rows; i++)   {
        for(j=0; j<cols; j++)
            printf("%d ",mat[i][j]);
        printf("\n");
    }
}
bool isDistinctValues(int mat[][cols])   {
    int i,j,sum;
    int reqSum=rows*(rows+1)/2;
    for(i=0; i<rows; i++)   {
        sum=0;
        for(j=0; j<cols; j++)   {
            sum+=mat[i][j];
        }
        if(sum!=reqSum)
            return false;
    }
    return true;
}
void swapSquaresAside(int mat[][cols])   {
    int i,j,temp;
    for(i=0; i*i<rows; i++) {
        for(j=0; j*j<cols; j++) {
            temp=mat[i][j];
            mat[i][j]=mat[i][j+(int)sqrt(cols)];
            mat[i][j+(int)sqrt(cols)]=temp;
        }
    }
}
void swapSquaresBelow(int mat[][cols])   {
    int i,j,temp;
    for(i=0; i*i<rows; i++) {
        for(j=0; j*j<cols; j++) {
            temp=mat[i][j];
            mat[i][j]=mat[i+(int)sqrt(rows)][j];
            mat[i+(int)sqrt(rows)][j]=temp;
        }
    }
}
bool isMagicSquare(int mat[][cols])   {
    int temp[rows][cols];
    int i,j;
    for(i=0; i<rows; i++)   {
        for(j=0; j<cols; j++)   {
            temp[i][j]=mat[i][j];
        }
    }
    printSudoku(mat);
    printf("\n");
    swapSquaresBelow(mat);
    printSudoku(mat);
    printf("\n");
    swapSquaresAside(temp);
    printSudoku(temp);
    printf("\n");
    if(isDistinctValues(mat) && isDistinctValues(temp))
        return true;
    return false;
}
int main() {
    int result;
	int mat[][cols]={{1,2,3,0,0,0,0,0,0},
	                 {0,0,0,0,0,0,1,2,3},
	                 {0,0,0,1,2,3,0,0,0},
	                 {2,3,1,0,0,0,0,0,0},
	                 {0,0,0,0,0,0,2,3,1},
	                 {0,0,0,2,3,1,0,0,0},
	                 {3,1,2,0,0,0,0,0,0},
	                 {0,0,0,0,0,0,3,1,2},
	                 {0,0,0,3,1,2,0,0,0}};
                   
	/*              {{1,0,0,0},
	                 {0,0,2,0},
	                 {0,3,0,0},
	                 {0,0,0,4}};
	  */
	                
	   
	if(solveSudoku(mat) && isMagicSquare(mat))    
	    result=1;
	    //printSudoku(mat);
	else
	    result=0;
	
	printf("%d\n",result);
	return 0;
}
