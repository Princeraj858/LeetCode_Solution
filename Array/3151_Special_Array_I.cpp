class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        
       
        for (int x = 1; x < n; ++x) {
            if((nums[x]&1) == (nums[x-1]&1))
                return false;
        }
        
       
        return true;
    }
};
