class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long res = 0, total = 0;
        int left=0;
        for (int right = 0; right< n; right++) {
            total += nums[right];
            while (left <= right && total * (right - left + 1) >= k) {
                total -= nums[left++];
            }
            res += right - left + 1;
        }
        return res;
    }
};