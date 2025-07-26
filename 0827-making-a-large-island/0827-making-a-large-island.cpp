class Solution {
public:
    int n;
    vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
    
    int dfs(vector<vector<int>>& grid, int x, int y, int islandId, vector<vector<int>>& idGrid) {
        if (x < 0 || y < 0 || x >= n || y >= n || grid[x][y] != 1 || idGrid[x][y] != 0)
            return 0;
        idGrid[x][y] = islandId;
        int area = 1;
        for (auto& dir : dirs) {
            area += dfs(grid, x + dir[0], y + dir[1], islandId, idGrid);
        }
        return area;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> idGrid(n, vector<int>(n, 0));
        unordered_map<int, int> islandArea;
        int islandId = 2;

        // 1. Label each island with a unique ID and calculate its area
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && idGrid[i][j] == 0) {
                    int area = dfs(grid, i, j, islandId, idGrid);
                    islandArea[islandId++] = area;
                }
            }
        }

        int maxArea = 0;
        for (auto& p : islandArea)
            maxArea = max(maxArea, p.second);

        // 2. Try flipping each 0 to 1 and compute new island area
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> neighborIslands;
                    for (auto& dir : dirs) {
                        int x = i + dir[0], y = j + dir[1];
                        if (x >= 0 && y >= 0 && x < n && y < n && idGrid[x][y] > 1)
                            neighborIslands.insert(idGrid[x][y]);
                    }
                    int newArea = 1;
                    for (int id : neighborIslands)
                        newArea += islandArea[id];
                    maxArea = max(maxArea, newArea);
                }
            }
        }

        return maxArea == 0 ? n * n : maxArea;
    }
};
