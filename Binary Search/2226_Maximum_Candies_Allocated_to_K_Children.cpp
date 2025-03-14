class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long left = 1, right = *max_element(candies.begin(), candies.end());
        int ans = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long count = 0;

            for (int c : candies) {
                count += (c / mid);
            }

            if (count >= k) {
                ans = mid;   
                left = mid + 1; 
            } else {
                right = mid - 1; 
            }
        }

        return ans;
    }
};
