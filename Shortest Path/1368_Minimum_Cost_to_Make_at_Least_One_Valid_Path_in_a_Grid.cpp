class Solution {
    #define pip pair<int, pair<int, int>>
    bool isvalid(int x, int y, int m, int n) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pip, vector<pip>, greater<pip>> minheap;
        
        minheap.push({0, {0, 0}}); 
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        while (!minheap.empty()) {
            pip curr = minheap.top();
            minheap.pop();

            int cost = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;

            if (visited[x][y]) continue;
            

            if (x == m - 1 && y == n - 1) return cost;
            
            visited[x][y] = true;

            for (int i = 0; i < 4; ++i) {
                int newx = x + dx[i];
                int newy = y + dy[i];

                if (isvalid(newx, newy, m, n) && !visited[newx][newy]) {
                    int new_cost = cost + ((i + 1) == grid[x][y] ? 0 : 1);
                    minheap.push({new_cost, {newx, newy}});
                }
            }
        }
        return 0;
    }
};