class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i < rows; i++) {
            // Check if the target could be in the current row
            if (target >= matrix[i][0] && target <= matrix[i][cols - 1]) {
                // Use binary search within this row
                int left = 0, right = cols - 1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (matrix[i][mid] == target) {
                        return true;
                    } else if (matrix[i][mid] < target) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                return false;  // Target not found in the row
            }
        }

        return false;  // Target not found in any row
    }
};
