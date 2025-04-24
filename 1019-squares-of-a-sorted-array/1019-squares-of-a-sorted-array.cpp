class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> num(n, 0);
        int right = n - 1;
        int left = 0;
        int HighestSquareIndex = n - 1;
        while (left <= right) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];
            if (leftSquare > rightSquare) {
                num[HighestSquareIndex] = leftSquare;
                left++;
            } else {
                num[HighestSquareIndex] = rightSquare;
                right--;
            }
            HighestSquareIndex--;
        }
        return num;
    }
};