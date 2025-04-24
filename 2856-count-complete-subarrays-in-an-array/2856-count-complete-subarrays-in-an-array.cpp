class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Find number of distinct elements in the whole array
        unordered_set<int> unique(nums.begin(), nums.end());
        int totalDistinct = unique.size();

        int count = 0;

        // Step 2: Sliding window approach to count complete subarrays
        for (int left = 0; left < n; ++left) {
            unordered_set<int> windowSet;
            for (int right = left; right < n; ++right) {
                windowSet.insert(nums[right]);
                if (windowSet.size() == totalDistinct) {
                    count++;
                }
            }
        }

        return count;
    }
};
