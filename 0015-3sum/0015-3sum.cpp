class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        vector<vector<int>> ans;

        for(int i = 0 ; i < n; i++){
            int left = i + 1;
            int right = n -1;
            while( left < right){
                int sum = nums[i] + nums[left] +nums[right];
                if(sum==0){
                    s.insert({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                }
                else if(sum < 0){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        for(auto num : s){
            ans.push_back(num);
        }
        return ans;
    }
};