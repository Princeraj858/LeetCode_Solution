class Solution {
    vector<int> dir = {-1, 0, 1, 0, -1}; 

    bool isValid(int n, int x, int y) {
        return (x >= 0 && x < n && y >= 0 && y < n);
    }

    int markIsland(vector<vector<int>>& grid, int island_number, int n, int x, int y) {
        grid[x][y] = island_number;
        int count = 1;
        
        for (int i = 0; i < 4; ++i) {
            int newX = x + dir[i];
            int newY = y + dir[i + 1];
            if (isValid(n, newX, newY) && grid[newX][newY] == 1) {
                count += markIsland(grid, island_number, n, newX, newY);
            }
        }
        return count;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int> island_size;
        int island_number = 2;  

        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                if (grid[x][y] == 1) {
                    int island = markIsland(grid, island_number, n, x, y);
                    island_size[island_number] = island;
                    island_number++;
                }
            }
        }

        int max_size = 0;
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                if (grid[x][y] == 0) { 
                    set<int> adjacent_islands;
                    for (int i = 0; i < 4; ++i) {
                        int newX = x + dir[i];
                        int newY = y + dir[i + 1];
                        if (isValid(n, newX, newY) && grid[newX][newY] > 1) {
                            adjacent_islands.insert(grid[newX][newY]);
                        }
                    }
                    
                    int curr_island = 1;
                    for (int key : adjacent_islands) {
                        curr_island += island_size[key];
                    }
                    max_size = max(max_size, curr_island);
                }
            }
        }

        return max_size == 0 ? n * n : max_size;
    }
};
