class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long count = 0;
        int minPos = -1, maxPos = -1, leftBound = -1;

        for (int right = 0; right < n; right++) {
            if (nums[right] < minK || nums[right] > maxK) {
                leftBound = right;
                minPos = -1;
                maxPos = -1;
            }
            if (nums[right] == minK) minPos = right;
            if (nums[right] == maxK) maxPos = right;

            if (minPos != -1 && maxPos != -1) {
                count += max(0, min(minPos, maxPos) - leftBound);
            }
        }
        return count;
    }
};
