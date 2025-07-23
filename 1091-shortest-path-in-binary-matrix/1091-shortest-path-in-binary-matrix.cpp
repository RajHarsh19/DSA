class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0)
            return -1;

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<>> pq;

        vector<pair<int,int>> directions = {
            {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}
        };

        dist[0][0] = 1;
        pq.push({1, {0, 0}});

        while (!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if (vis[r][c]) continue;
            vis[r][c] = true;

            for (auto dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 0) {
                    if (d + 1 < dist[nr][nc]) {
                        dist[nr][nc] = d + 1;
                        pq.push({dist[nr][nc], {nr, nc}});
                    }
                }
            }
        }

        return (dist[n-1][n-1] == 1e9) ? -1 : dist[n-1][n-1];
    }
};
