/**
 * @input A : Integer
 * 
 * @Output Integer
 */
 //Square root of a number
int Sqrt(int A) {
    int result=0,low=0,high=A,mid;
    long power;
    if(A==1)
        return 1;
    while(low<high) {
        mid=low+(high-low)/2;
        power=(long)mid*mid;
        if(power == A)  {
            result=mid;
            break;
        }
        else if(power < A)  {
            result=mid;
            low=mid;
            if(low==high-1)
                break;
        }
        else    {
            high=mid;
        }
    }
    return result;
}
