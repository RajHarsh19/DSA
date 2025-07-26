class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        vis[0][0] = 1;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [time, x, y] = pq.top();
            pq.pop();

            if (x == n - 1 && y == n - 1)
                return time;

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    pq.push({max(time, grid[nx][ny]), nx, ny});
                }
            }
        }

        return -1; // unreachable (should never happen for valid input)
    }
};
