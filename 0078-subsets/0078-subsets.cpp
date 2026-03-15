class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;

        createsub(nums, 0 , res , subset);
        return res;
    }
    void createsub(vector<int>& nums, int index, vector<vector<int>> &res, vector<int>& sub){
        if(index == nums.size()){
            res.push_back(sub);
            return;
        }
        sub.push_back(nums[index]);
        createsub(nums, index+1, res, sub);

        sub.pop_back();
        createsub(nums, index + 1, res, sub);
    }
};