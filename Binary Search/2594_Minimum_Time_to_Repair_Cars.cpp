class Solution {
public:
    bool canRepairInTime(vector<int>& ranks, int cars, long long t) {
        long long totalCars = 0;
        for (int r : ranks) {
            long long count = sqrt(t / r);  // Number of cars this mechanic can repair in time t
            totalCars += count;
            if (totalCars >= cars) return true; // Early stopping
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1, right = 1LL * *min_element(ranks.begin(), ranks.end()) * cars * cars;
        long long ans = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (canRepairInTime(ranks, cars, mid)) {
                ans = mid;
                right = mid - 1; 
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
