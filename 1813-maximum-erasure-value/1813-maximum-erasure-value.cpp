class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> unique;

        int max_sum = 0;
        int cur_sum = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            // If duplicate, shrink window from the left
            while (unique.find(nums[right]) != unique.end()) {
                unique.erase(nums[left]);
                cur_sum -= nums[left];
                left++;
            }

            unique.insert(nums[right]);
            cur_sum += nums[right];
            max_sum = max(max_sum, cur_sum);
        }
        return max_sum;
    }
};