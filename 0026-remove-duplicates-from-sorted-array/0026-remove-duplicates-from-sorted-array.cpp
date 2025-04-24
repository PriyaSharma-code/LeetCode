class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1;              // Start from the second element
        int nonDupe = 1;        // Position to insert the next unique element

        while (i < nums.size()) {
            // If the current element is not equal to the previous one,
            // it means it's a new unique element
            if (nums[i - 1] != nums[i]) {
                nums[nonDupe] = nums[i]; // Place the unique element at the 'nonDupe' index
                nonDupe++;               // Move the pointer for the next unique element
            }
            i++; // Move to the next element
        }

        // 'nonDupe' represents the number of unique elements in the array
        return nonDupe;
    }
};
