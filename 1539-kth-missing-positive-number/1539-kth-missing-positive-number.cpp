class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int i = 0;
       int n = nums.size();
       while (i < n) {
            int j = nums[i] - 1;
            if (nums[i] > 0 && nums[i]<= n && nums[i]!= nums[j]) {
                // swap
                swap(nums[i], nums[nums[i] - 1]);
            }
            else {
                i++;
            }
        }
        vector<int> missingNumbers;
        unordered_set<int> extraNumbers;
        for (int i = 0; i < n; i++) {
            if (missingNumbers.size() < k) {
                if (nums[i] != i + 1) {
                    missingNumbers.push_back(i + 1);
                    extraNumbers.insert(nums[i]);
                }
            }
        }
        // add the remaining missing numbers
        int j = 1;
        while (missingNumbers.size() < k) {
            int currentNumber =j + n;
                // ignore if the array contains the current number
                if (extraNumbers.find(currentNumber)== extraNumbers.end()){
                    missingNumbers.push_back(currentNumber);
                }
               j++;
        }
        return missingNumbers[k-1];
    }
};