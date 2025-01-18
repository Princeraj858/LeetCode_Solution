class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        vector<int> tin(n, -1), low(n, -1);
        vector<vector<int>> bridges;
        int timer = 0;

        for (auto& conn : connections) {
            int u = conn[0], v = conn[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        function<void(int, int)> dfs = [&](int node, int parent) {
            tin[node] = low[node] = timer++;
            
            for (int neighbor : graph[node]) {
                if (neighbor == parent) continue;
                
                if (tin[neighbor] == -1) { 
                    dfs(neighbor, node);
                    low[node] = min(low[node], low[neighbor]);


                    if (low[neighbor] > tin[node]) {
                        bridges.push_back({node, neighbor});
                    }
                } else {
                    low[node] = min(low[node], tin[neighbor]); 
                }
            }
        };

        dfs(0, -1);

        return bridges;
    }
};