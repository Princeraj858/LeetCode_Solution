class Solution {
    public:
        int numTilePossibilities(string tiles) {
            unordered_map<char, int> freq;
            for (char ch : tiles) {
                freq[ch]++;
            }
            return dfs(freq);
        }
    
        int dfs(unordered_map<char, int>& freq) {
            int count = 0;
            for (auto& [ch, num] : freq) {
                if (num == 0) continue;
    
              
                freq[ch]--;
                count += 1 + dfs(freq); 
    
                
                freq[ch]++;
            }
            return count;
        }
    };
    