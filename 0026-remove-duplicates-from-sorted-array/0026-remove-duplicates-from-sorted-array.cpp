class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i =1;
        int nonDupe=1;
        while(i<nums.size()){
            if(nums[i-1]!=nums[i]){
                nums[nonDupe]=nums[i];
                nonDupe++;
            }
            i++;
        }
        return nonDupe;
    }
};