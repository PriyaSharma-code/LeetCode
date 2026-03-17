class Solution {
public:
    bool dfs(int node, const vector<vector<int>>&adj, vector<bool>& vis,vector<bool>&path){
        vis[node] = path[node] = true;
        for(int next: adj[node]){
            if(!vis[next]){
                if(dfs(next,adj,vis,path)){
                    return true;
                }
            }
            else if(path[next]){
                return true;
            }
        }
        path[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(const auto&e: prerequisites){
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(numCourses,false),path(numCourses,false);

        for(int i =0;i <numCourses; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, path)){
                    return false;
                }
            }
        }
        return true;

    }
};