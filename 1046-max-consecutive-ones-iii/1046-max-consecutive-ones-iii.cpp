class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0,right=0;
        int maxCount = 0; // count of 1s present
        int maxLen = 0;

        while(right<nums.size()) {
            if (nums[right] == 1) {
                maxCount++;
            }
            //current window size is from windowStart to windowEnd, overall we have a 
    //maximum of `1`'s repeating maxOnesCount times, this means we can have a window 
    //with maxOnesCount `1`'s and the remaining are `0`'s which should replace with `1`'s
    //now, if the remaining `0`'s are more that k, it is the time to shrink the 
    //window as we are not allowed to replace more than k `0`'s
            if (right - left + 1 - maxCount > k) {
                if (nums[left] == 1) {
                    maxCount--;
                }
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};