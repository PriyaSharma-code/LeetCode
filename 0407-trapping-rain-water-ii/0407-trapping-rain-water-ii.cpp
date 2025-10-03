class Solution {
public:
    const int di[4]={-1,1,0,0};
    const int dj[4]={0,0,1,-1};
    int trapRainWater(vector<vector<int>>& height) {
        int m = height.size();
        int n = height[0].size();
        vector<tuple<int,int,int>> hij;
        hij.reserve(2*(m+n));

        for(int i=0; i<m; i++){
            hij.emplace_back(height[i][0],i,0);
            hij.emplace_back(height[i][n-1],i,n-1);
            height[i][0] = height[i][n-1] =-1;
        }

        for(int j=0; j<n; j++){
            hij.emplace_back(height[0][j],0,j);
            hij.emplace_back(height[m-1][j],m-1,j);
            height[0][j] = height[m-1][j] =-1;
        }
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq(hij.begin(),hij.end());
        int ans = 0;
        int water_level=0;
        while(!pq.empty()){
            auto [h,i,j] = pq.top();
            pq.pop();
            water_level = max(water_level,h);
            for(int k = 0; k<4 ; k++){
                int i0 = i+di[k], j0= j+dj[k];
                if(i0 <=0 || i0>=m-1 || j0 <=0 || j0>=n-1 || height[i0][j0] ==-1) continue;
                int currHeight = height[i0][j0];
                pq.push({currHeight,i0,j0});
                if(currHeight < water_level){
                    ans+= water_level - currHeight;
                }
                height[i0][j0]=-1;

            }
        }
        return ans;
    }
};