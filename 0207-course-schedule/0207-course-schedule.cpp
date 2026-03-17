class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);

        for(auto &e: prerequisites){
            graph[e[1]].push_back(e[0]);
            indegree[e[0]]++;
    }
    queue<int> q;
    for(int i = 0; i<numCourses; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    int count = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        count++;
        for(int next : graph[node]){
            indegree[next]--;
            if(indegree[next]==0){
                q.push(next);
            }
        }
    }
       
        return count ==numCourses;
    }
};