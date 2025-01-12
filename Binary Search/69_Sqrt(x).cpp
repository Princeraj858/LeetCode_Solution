class Solution {
public:
    int mySqrt(int x) {
        int low =0, high = x, result =0;

        while(low <= high){

            long mid = low +(high-low)/2;

            if( mid*mid == x){
                return mid;
            }else if( mid*mid < x){
                result = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return result;
    }
};
