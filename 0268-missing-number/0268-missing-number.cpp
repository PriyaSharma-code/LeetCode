class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int expectedSum = 0;
        int curSum=0;
        int n = nums.size();

        expectedSum = n*(n+1)/2;

        for(int num : nums){
            curSum+=num;
        }

        return expectedSum - curSum;
    }
};