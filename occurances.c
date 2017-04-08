/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */
//Count the number of occurances of an element in a sorted array
int firstOccurances(const int *A, int low, int high, int B)    {
    if(low <= high)  {
        int mid=low+(high-low)/2;
        if((mid > 0 && A[mid]==B && A[mid-1]!=B) || (mid == 0 && A[mid]==B))
            return mid;
        else if(A[mid] >= B)
            return firstOccurances(A,low,mid-1,B);
        else if(A[mid] < B)
            return firstOccurances(A,mid+1,high,B);
    }
    return -1;
}
int lastOccurances(const int *A, int n1, int low, int high, int B)    {
    if(low <= high)  {
        int mid=low+(high-low)/2;
        //printf("%d %d\n",low,high);
        if((mid < n1 && A[mid]==B && A[mid+1]!=B) ||(mid == n1-1 && A[mid]==B))
            return mid;
        else if(A[mid] <= B)
            return lastOccurances(A,n1,mid+1,high,B);
        else if(A[mid] > B)
            return lastOccurances(A,n1,low,mid-1,B);
    }
    return -1;
}

int findCount(const int* A, int n1, int B) {
    int x=lastOccurances(A,n1,0,n1-1,B);
    int y=firstOccurances(A,0,n1-1,B);
    return (x==-1 && y==-1)?0:(x-y+1);
}
