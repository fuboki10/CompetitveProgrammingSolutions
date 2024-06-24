class Solution {
private:
    bool visited[200000];
    vector<vector<int>> adj;

    bool dfs(int src, int par, int dst) {
        if (visited[src]) return false;
        visited[src] = 1;
        if (src == dst) return true;
        for (auto u: adj[src]) {
            if (u != par) {
                if (dfs(u, src, dst)) return true;
            }
        }

        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
       adj.resize(n, vector<int>());

       for (auto &e: edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
       } 

       return dfs(source, -1, destination);
    }
};