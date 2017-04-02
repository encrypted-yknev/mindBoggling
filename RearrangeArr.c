/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Void. Just modifies the args passed by reference 
 */

//To rearrange the array such that A[i] becomes A[A[i]] using O(1) space.
void arrange(int* A, int n1) {
    int i;
    for(i=0; i<n1; i++) {
        A[i]+=(A[A[i]]%n1)*n1;
    }
    for(i=0; i<n1; i++) {
        A[i]=A[i]/n1;
    }
    return A;
}
