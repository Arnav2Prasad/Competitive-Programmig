
class Solution {
public:

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    stack<int> s;
    s.push(node);
    visited[node] = true;

    while (!s.empty()) {
        int current = s.top();
        s.pop();
        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                s.push(neighbor);
            }
        }
    }
}

int makeConnected(int n, vector<vector<int>>& connections) {
    if (connections.size() < n - 1) return -1; // Not enough cables to connect all computers

    // Create adjacency list
    vector<vector<int>> adj(n);
    for (const auto& connection : connections) {
        adj[connection[0]].push_back(connection[1]);
        adj[connection[1]].push_back(connection[0]);
    }

    // Find number of connected components
    vector<bool> visited(n, false);
    int numComponents = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            ++numComponents;
        }
    }

    // We need (numComponents - 1) cables to connect these components
    return numComponents - 1;
}
};


