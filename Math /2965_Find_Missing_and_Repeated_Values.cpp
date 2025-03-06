class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            int n = grid.size();
            int N = n * n; 
            
            long long expected_sum = (1LL * N * (N + 1)) / 2;
            long long expected_square_sum = (1LL * N * (N + 1) * (2 * N + 1)) / 6;
            
            long long actual_sum = 0, actual_square_sum = 0;
            
           
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    actual_sum += grid[i][j];
                    actual_square_sum += grid[i][j] * grid[i][j]; 
                }
            }
            
        
            long long diff = actual_sum - expected_sum;  
            long long square_diff = actual_square_sum - expected_square_sum;  
            
      
            long long sum_val = square_diff / diff; 
            int missing = (sum_val - diff) / 2;
            int repeated = missing + diff;
            
            return {repeated, missing};
        }
    };
    