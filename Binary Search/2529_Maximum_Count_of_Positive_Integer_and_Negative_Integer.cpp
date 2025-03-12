class Solution {
public:
    int maximumCount(std::vector<int>& nums) {
        int negCount = std::lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int posCount = nums.end() - std::upper_bound(nums.begin(), nums.end(), 0);
        return std::max(negCount, posCount);
    }
};
