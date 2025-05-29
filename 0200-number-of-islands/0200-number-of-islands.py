class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0

        m, n = len(grid), len(grid[0])

        def erase(i, j):
            if i < 0 or j < 0 or i >= m or j >= n or grid[i][j] != "1":
                return
            grid[i][j] = "0"
            erase(i + 1, j)
            erase(i - 1, j)
            erase(i, j + 1)
            erase(i, j - 1)

        count = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == "1":
                    count += 1
                    erase(i, j)
        return count
