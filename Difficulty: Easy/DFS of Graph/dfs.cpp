class Solution {
  private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& ls) {
        vis[node] = 1;
        ls.push_back(node);
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, ls);
            }
        }
    }

  public:
    vector<int> dfsOfGraph(int V, vector<vector<int>>& adj) {
        vector<int> vis(V, 0);
        vector<int> ls;
        dfs(0, adj, vis, ls);
        return ls;
    }
};
