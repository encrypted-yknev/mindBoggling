int partition(int *arr,int i,int j) {
    int p=i-1,q=i,x=arr[j],temp;
    
    while(q < j)    {
        if(arr[q] <= x) {
            p++;
            temp=arr[q];
            arr[q]=arr[p];
            arr[p]=temp;
        }
        q++;
    }
    temp=arr[p+1];
    arr[p+1]=arr[j];
    arr[j]=temp;
    
    return p+1;
}
void quicksort(int *arr, int i, int j)    {
    if(i<j) {
        int index=partition(arr,i,j);
        quicksort(arr,i,index-1);
        quicksort(arr,index+1,j);
    }
}
