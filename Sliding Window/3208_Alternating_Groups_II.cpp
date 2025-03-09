
class Solution {
public:
    int numberOfAlternatingGroups(std::vector<int>& colors, int k) {
        int n = colors.size();
        int count = 0;
        int alternatingLength = 1;

        
        for (int i = 1; i < n * 2; ++i) {
           
            if (colors[i % n] == colors[(i - 1) % n]) {
                alternatingLength = 1; 
            } else {
                ++alternatingLength; 
            }

       
            if (i >= n && alternatingLength >= k) {
                ++count;
            }
        }

        return count;
    }
};
