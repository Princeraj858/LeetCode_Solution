class Solution {
    public:
        bool isValid(int num, int target) {
            string s = to_string(num * num);
            return canPartition(s, 0, target, 0);
        }
    
        bool canPartition(string& s, int idx, int target, int currentSum) {
            if (idx == s.size()) {
                return currentSum == target;
            }
            
            int sum = 0;
            for (int i = idx; i < s.size(); ++i) {
                sum = sum * 10 + (s[i] - '0');
                if (currentSum + sum > target) break;
                if (canPartition(s, i + 1, target, currentSum + sum)) {
                    return true;
                }
            }
            return false;
        }
    
        int punishmentNumber(int n) {
            int result = 0;
            for (int i = 1; i <= n; ++i) {
                if (isValid(i, i)) {
                    result += i * i;
                }
            }
            return result;
        }
    };
    