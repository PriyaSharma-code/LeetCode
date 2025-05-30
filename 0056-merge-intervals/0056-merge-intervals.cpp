class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0){
            return  {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        //vector<int> cur = intervals[0];
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<= end){
               end = max(end,intervals[i][1]);
            }
            else{
                ans.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};