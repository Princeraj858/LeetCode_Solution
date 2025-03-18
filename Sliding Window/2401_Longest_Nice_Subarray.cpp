class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int maxLength = 0;
        int currentOR = 0; 
        
        for (int right = 0; right < n; ++right) {

            while ((currentOR & nums[right]) != 0) {
   
                currentOR ^= nums[left];
                left++;
            }
            

            currentOR |= nums[right];
            
     
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};
