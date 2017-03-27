#include <stdio.h>

//To segregate 0s and 1s
void segregate01(int arr[], int len)  {
    int i=0,j=-1,temp;
    
    while(i<len)    {
        if(arr[i]==1)   {
            j++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
        i++;
    }
}
//To segregate Even and odd numbers
void segregateEvenOdd(int arr[], int len)  {
    int i=0,j=-1,temp;
    
    while(i<len)    {
        if(arr[i] % 2 == 0)   {
            j++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
        i++;
    }
}
int main() {
	int arr[]={0,1,0,1,1,0,0,1,0,0,1};
	int i,len=sizeof(arr)/sizeof(arr[0]);
	segregate(arr,len);
	
	for(i=0; i<len; i++)
	    printf("%d ",arr[i]);
	    
	return 0;
}
