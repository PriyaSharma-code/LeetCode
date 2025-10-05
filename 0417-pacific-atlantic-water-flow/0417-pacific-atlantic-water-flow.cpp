class Solution {
public:

    int r[4] = {0,1,0,-1};
    int c[4] = {1,0,-1,0};

    void solve(vector<vector<int>>& h,int i,int j, bool atlantic, vector<vector<pair<int,int>>>& a){
        if(atlantic && a[i][j].first==1) return;
        if(!atlantic && a[i][j].second==1) return;

        if(atlantic) a[i][j].first=1;
        else a[i][j].second=1;

        for(int k=0;k<4;k++){
            int row = i+ r[k];
            int col = j+ c[k];

            if(row>=0 && col>=0 && row<h.size() && col<h[0].size() && h[i][j]<=h[row][col]){
                
                solve(h,row,col,atlantic,a);
            }
        }

        
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n=heights[0].size();

        vector<vector<pair<int,int>>> v(m, vector<pair<int,int>>(n,{0,0}));
        vector<vector<int>> ans;

        for(int j=0;j<n;j++){
            solve(heights,0,j,false,v);
        }

        for(int i=0;i<m;i++){
            solve(heights,i,0,false,v);
        }

        for(int j=0;j<n;j++){
            solve(heights,m-1,j,true,v);
        }

        for(int i=0;i<m;i++){
            solve(heights,i,n-1,true,v);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j].first==1 && v[i][j].second==1) ans.push_back({i,j});
            }
        }

        return ans;
    }
};