class Solution {
public:
    unordered_map<int, int> parent;

    int find(int x) {
        if (parent.find(x) == parent.end())
            parent[x] = x;
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py)
            parent[px] = py;
    }

    int removeStones(vector<vector<int>>& stones) {
        for (auto& stone : stones) {
            // Use row as positive and col as negative to avoid overlap
            int row = stone[0];
            int col = ~stone[1];  // bitwise NOT ensures uniqueness
            unite(row, col);
        }

        unordered_set<int> uniqueRoots;
        for (auto& stone : stones) {
            uniqueRoots.insert(find(stone[0]));
        }

        return stones.size() - uniqueRoots.size();
    }
};
