class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> indegree(n, 0);
        vector<int> longest_chain(n, 1); // Stores longest path to a node
        
        // Build the indegree array
        for (int i = 0; i < n; ++i) 
            indegree[favorite[i]]++;

        // Topological Sorting: Find longest chains leading into cycles
        queue<int> q;
        for (int i = 0; i < n; ++i) 
            if (indegree[i] == 0) q.push(i);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            int v = favorite[u];
            longest_chain[v] = max(longest_chain[v], longest_chain[u] + 1);
            if (--indegree[v] == 0) q.push(v);
        }

        // Step 2: Find cycles and calculate results
        int max_cycle_size = 0, two_node_cycle_sum = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; ++i) {
            if (indegree[i] > 0) { // Node in a cycle
                int cycle_size = 0;
                int node = i;
                
                // Detect cycle length
                while (!visited[node]) {
                    visited[node] = true;
                    cycle_size++;
                    node = favorite[node];
                }
                
                // Case 1: Maximum cycle size
                if (cycle_size == 2) {
                    two_node_cycle_sum += longest_chain[i] + longest_chain[favorite[i]];
                } else {
                    max_cycle_size = max(max_cycle_size, cycle_size);
                }
            }
        }

        // Return max of the two scenarios
        return max(max_cycle_size, two_node_cycle_sum);
    }
};