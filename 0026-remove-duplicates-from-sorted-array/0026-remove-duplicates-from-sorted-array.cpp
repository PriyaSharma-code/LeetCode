class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;  // Create a set to store unique elements (automatically sorted)

        // Insert all elements into the set — this removes duplicates
        for(int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }

        int k = s.size();  // Number of unique elements
        int j = 0;

        // Copy the unique elements back into the original array
        for(int x : s) {
            nums[j++] = x;
        }

        return k;  // Return the count of unique elements
    }
};
