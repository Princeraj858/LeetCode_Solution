class Solution {
public:
    int reverse(int x) {
        int remander = 0, reverse = 0;
        while(x != 0){
            remander = x % 10;
            if( (reverse > INT_MAX/10) || reverse < INT_MIN /10){
                return 0;
            }
            reverse = reverse * 10 + remander;
            x /= 10;
        }
        return reverse;
    }
};
