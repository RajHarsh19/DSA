class Solution {
public:
    
    int find(int u, vector<int>& parent) {
        if (parent[u] != u)
            parent[u] = find(parent[u], parent);
        return parent[u];
    }

    
    void unionSets(int u, int v, vector<int>& parent) {
        int pu = find(u, parent);
        int pv = find(v, parent);
        if (pu != pv)
            parent[pu] = pv;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1; 

        vector<int> parent(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        int components = n;
        for (auto& conn : connections) {
            int u = conn[0];
            int v = conn[1];

            int pu = find(u, parent);
            int pv = find(v, parent);

            if (pu != pv) {
                unionSets(u, v, parent);
                components--;  
            }
        }

        
        return components - 1;
    }
};
