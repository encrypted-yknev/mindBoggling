#include <stdio.h>
//Union of two arrays
void ArrayUnion(int arr1[],int len1,int arr2[],int len2)    {
    int p=0,q=0;
    
    while(p<len1 || q<len2) {
        if(arr1[p] == arr2[q])  {
            printf("%d ",arr1[p]);
            p++;
            q++;
        }
        else if(arr1[p] < arr2[q])  {
            printf("%d ",arr1[p]);
            p++;
        }
        else    {
            printf("%d ",arr2[q]);
            q++;
        }
    }
}
//Intersection of two arrays
void ArrayIntersection(int arr1[],int len1,int arr2[],int len2)    {
    int p=0,q=0;
    
    while(p<len1 && q<len2) {
        if(arr1[p] == arr2[q])  {
            printf("%d ",arr1[p]);
            p++;
            q++;
        }
        else if(arr1[p] < arr2[q])
            p++;
        else q++;
    }
}
int main() {
	int arr1[]={1,3,4,6,8};
	int arr2[]={1,2,10};
	int len1=sizeof(arr1)/sizeof(arr1[0]);
	int len2=sizeof(arr2)/sizeof(arr2[0]);
	ArrayUnion(arr1,len1,arr2,len2);
	printf("\n");
	ArrayIntersection(arr1,len1,arr2,len2);
	return 0;
}
