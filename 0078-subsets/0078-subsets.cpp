class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back({});
        bfs(result,nums);
        return result;
    }
    void bfs(vector<vector<int>> &result, vector<int>& nums){
        for(int i=0; i <nums.size() ;i++){
            int n = result.size();
            for(int j = 0; j <n; j++){
                vector<int>cur = result[j];
                cur.push_back(nums[i]);
                result.push_back(cur);
            }
        }
    }
};