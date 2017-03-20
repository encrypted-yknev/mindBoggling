#include <stdio.h>
#include <limits.h>

int maxContSum(int arr[], int len)  {
    int i, cur_sum = arr[0], max_sum = cur_sum;
    for(i = 1; i <= len; i++)   {
        cur_sum = (cur_sum+arr[i] > arr[i])?(cur_sum+arr[i]):arr[i];
        max_sum = (max_sum < cur_sum)?cur_sum:max_sum;
    }
    return max_sum;
}
int main() {
	int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int len = sizeof(arr)/sizeof(arr[0]);
	
	printf("%d",maxContSum(arr,len-1));
	return 0;
}
