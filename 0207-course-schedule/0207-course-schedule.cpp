class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0), bfs;

        for(auto &e: prerequisites){
            graph[e[1]].push_back(e[0]);
            indegree[e[0]]++;
    }

        for(int i=0 ;i<numCourses; i++){
            if(indegree[i]==0){
                bfs.push_back(i);
            }
        }

        for(int i=0; i< bfs.size(); i++){
            for(int j : graph[bfs[i]]){
                if(--indegree[j]==0){
                    bfs.push_back(j);
                }
            }
        }
        return bfs.size()==numCourses;
    }
};