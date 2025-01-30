class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> color(n + 1, -1); 
        int max_groups = 0;

        function<int(int)> bfs = [&](int start) {
            queue<int> q;
            vector<int> level(n + 1, -1);
            q.push(start);
            level[start] = 1;
            int max_depth = 1;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node]) {
                    if (level[neighbor] == -1) {
                        level[neighbor] = level[node] + 1;
                        max_depth = max(max_depth, level[neighbor]);
                        q.push(neighbor);
                    }
                }
            }
            return max_depth;
        };

        for (int i = 1; i <= n; ++i) {
            if (color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;
                vector<int> component;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    component.push_back(node);

                    for (int neighbor : adj[node]) {
                        if (color[neighbor] == -1) {
                            color[neighbor] = color[node] ^ 1;
                            q.push(neighbor);
                        } else if (color[neighbor] == color[node]) {
                            return -1; 
                        }
                    }
                }

               
                int component_max = 0;
                for (int node : component) {
                    component_max = max(component_max, bfs(node));
                }
                max_groups += component_max;
            }
        }
        return max_groups;
    }
};
