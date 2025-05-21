class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m,n = len(grid),len(grid[0])
        visited = grid
        q = collections.deque()
        fresh = 0
        for i in range(m):
            for j in range(n):
                if(visited[i][j]==2):
                    q.append((i,j))
                if visited[i][j]==1:
                    fresh+=1
        if fresh==0:
            return 0
        if not q:
            return -1

        minutes = -1
        dirs = [(0,1),(1,0),(-1,0),(0,-1)]
        while(q):
            size = len(q)
            while size>0:
                x,y = q.popleft()
                size -=1
                for dx,dy in dirs:
                    i,j = x + dx, y + dy
                    if 0<=i < m and 0 <=j <n and visited[i][j]==1:
                        visited[i][j]=2
                        fresh -=1
                        q.append((i,j))
            minutes +=1
        if fresh ==0:
            return minutes
        return -1