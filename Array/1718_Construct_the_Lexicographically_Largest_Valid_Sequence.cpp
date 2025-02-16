class Solution {
    public:
        vector<int> constructDistancedSequence(int n) {
            vector<int> result(2 * n - 1, 0);
            vector<bool> used(n + 1, false);
            backtrack(result, used, n, 0);
            return result;
        }
    
        bool backtrack(vector<int>& result, vector<bool>& used, int n, int idx) {
            if (idx == result.size()) {
                return true;
            }
            if (result[idx] != 0) {
                return backtrack(result, used, n, idx + 1);
            }
    
            for (int i = n; i >= 1; --i) {
                if (used[i]) continue;
    
                if (i == 1) {
                    result[idx] = 1;
                    used[1] = true;
                    if (backtrack(result, used, n, idx + 1)) {
                        return true;
                    }
                    result[idx] = 0;
                    used[1] = false;
                } else {
                    if (idx + i < result.size() && result[idx + i] == 0) {
                        result[idx] = i;
                        result[idx + i] = i;
                        used[i] = true;
    
                        if (backtrack(result, used, n, idx + 1)) {
                            return true;
                        }
    
                        result[idx] = 0;
                        result[idx + i] = 0;
                        used[i] = false;
                    }
                }
            }
    
            return false;
        }
    };
    