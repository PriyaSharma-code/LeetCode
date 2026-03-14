class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> val;
        for(int i=0;i<nums.size();i++){
            int rem = target - nums[i];
            if(val.find(rem)!= val.end()){
                return {val[rem],i};
            }
            val[nums[i]] =i;
        }
        return {-1,-1};
    }
};