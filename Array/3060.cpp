#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> queryResults(int limit, std::vector<std::vector<int>>& queries) {
        std::unordered_map<int, int> ballToColor;
        std::unordered_map<int, int> colorCount;
        std::vector<int> result;

        for (const auto& query : queries) {
            int ball = query[0];
            int color = query[1];

            // If the ball was previously colored, decrement the count of its previous color
            if (ballToColor.find(ball) != ballToColor.end()) {
                int prevColor = ballToColor[ball];
                colorCount[prevColor]--;
                if (colorCount[prevColor] == 0) {
                    colorCount.erase(prevColor);
                }
            }

            // Assign the new color to the ball
            ballToColor[ball] = color;
            // Increment the count of the new color
            colorCount[color]++;

            // The number of distinct colors is the size of the colorCount map
            result.push_back(colorCount.size());
        }

        return result;
    }
};
