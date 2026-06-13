class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = m ? grid[0].size() : 0;
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    erase(grid, i, j);
                }
            }
        }
        return count;
    }

    void erase(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || j < 0 || i == m || j == n || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        erase(grid, i - 1, j);
        erase(grid, i + 1, j);
        erase(grid, i, j - 1);
        erase(grid, i, j + 1);
    }
};