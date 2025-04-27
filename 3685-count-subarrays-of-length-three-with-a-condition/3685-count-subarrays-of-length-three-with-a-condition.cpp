class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        if(nums.size()<2){
            return 0;
        }
        int left = 0;
        int count=0;
        for(int right = 2;right<nums.size();right++){
                if(nums[right-1] ==  (nums[left]+nums[right])*2){
                    count++;
                }
                left++;
        }
        return count;
    }
};