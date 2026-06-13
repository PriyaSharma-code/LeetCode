class Solution {
public:
    int maxProduct(vector<int>& nums) {

        // Stores the maximum product found so far.
        // Initialized to the smallest possible integer.
        int maxi = INT_MIN;

        // Product while traversing from left to right.
        int left = 1;

        // Product while traversing from right to left.
        int right = 1;

        for (int i = 0; i < nums.size(); i++) {

            // Multiply current number into the left-running product.
            left *= nums[i];

            // Multiply current number into the right-running product.
            // nums.size() - i - 1 gives indices:
            // n-1, n-2, n-3, ...
            right *= nums[nums.size() - i - 1];

            // Update maximum product using both directions.
            // We check both because negative numbers can flip signs.
            maxi = max(maxi, max(left, right));

            // If left product becomes 0,
            // start a new subarray after this zero.
            if (left == 0) {
                left = 1;   // reset
            }

            // If right product becomes 0,
            // start a new subarray before this zero.
            if (right == 0) {
                right = 1;  // reset
            }
        }

        // Return the maximum product subarray found.
        return maxi;
    }
};