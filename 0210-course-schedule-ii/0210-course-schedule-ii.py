class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(numCourses)]
        indegree = [0]*numCourses
        ans =[]

        for pair in prerequisites:
            adj[pair[1]].append(pair[0])
            indegree[pair[0]] +=1
        q =deque()
        for i in range(numCourses):
            if indegree[i]==0:
                q.append(i)

        while q:
            curr = q.popleft()
            ans.append(curr)
            for next_course in adj[curr]:
                indegree[next_course] -=1
                if indegree[next_course]==0:
                    q.append(next_course)

        if len(ans)<numCourses:
            return []
        return ans