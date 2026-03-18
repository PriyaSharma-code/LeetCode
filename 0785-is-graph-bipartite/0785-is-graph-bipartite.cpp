class Solution {
public:
    bool dfs(int node, vector<int>&colored, int color, vector<vector<int>>&graph){
        colored[node] = color;

        for(int neighbor : graph[node]){
            if(colored[neighbor]==-1){
                int c = 1-color;
                if(!dfs(neighbor, colored, c, graph)){
                    return false;
                }
            }
            else if(colored[node] == colored[neighbor]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colored(n,-1);

        for(int i = 0 ; i<n;i++){
            if(colored[i]==-1){
                if(!dfs(i, colored, 0, graph)){
                    return false;
                }
            }
        }
        return true;
    }
};