class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        long long dd = dividend;
        long long dv = divisor;

      
        bool isNegative = (dd < 0) ^ (dv < 0); 
        dd = dd < 0 ? -dd : dd; 
        dv = dv < 0 ? -dv : dv; 

        long long result = 0;


        while (dd >= dv) {
            long long temp = dv, count = 1;
            while (dd >= (temp << 1)) { 
                temp <<= 1;
                count <<= 1;
            }
            result += count;
            dd -= temp;
        }

        if (isNegative) {
            if (result > INT_MAX) return INT_MIN;
            result = -result;
        }

        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;

        return (int)result;
    }
};
