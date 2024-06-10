class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int empty = 1;

    int uniquePathsIII(vector<vector<int>>& grid) {
        int startX = 0, startY = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0) {
                    ++empty;
                }
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }
            }
        }
        return backtrack(grid, startX, startY);
    }

    int backtrack(vector<vector<int>>& grid, int x, int y) {
        if (grid[x][y] == 2) {
            return empty == 0 ? 1 : 0;
        }
        grid[x][y] = -1;
        --empty;
        int sum = 0;
        for (auto& direction : directions) {
            int newX = x + direction[0], newY = y + direction[1];
            if (newX >= 0 && newY >= 0 && newX < grid.size() && newY < grid[0].size() && grid[newX][newY] != -1) {
                sum += backtrack(grid, newX, newY);
            }
        }
        grid[x][y] = 0;
        ++empty;
        return sum;
    }
};
