class Solution {
public:
    string addBinary(string a, string b) {
        int A = a.size()-1;
        int B = b.size()-1;

        string result ="";
        int carry = 0;
        while(A >=0 || B >=0 || carry){
            int sum = carry;
            if(A >=0 ) sum += a[A--] - '0';
            if(B >=0 ) sum +=b[B--] - '0';
            result += (sum%2) + '0';
            carry = sum/2;
        } 
        reverse(result.begin(),result.end());
        return result;
    }
};
