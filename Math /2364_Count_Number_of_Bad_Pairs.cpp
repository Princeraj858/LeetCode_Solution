class Solution {
public:
    long long countBadPairs(std::vector<int>& nums) {
        long long n = nums.size();
        long long totalPairs = (n * (n - 1)) / 2;
        long long goodPairs = 0;
        std::unordered_map<int, long long> freq;

        for (int i = 0; i < n; ++i) {
            int key = nums[i] - i;
            goodPairs += freq[key];  
            freq[key]++; 
        }
        
        return totalPairs - goodPairs;
    }
};
