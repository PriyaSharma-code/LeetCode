class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end()); //set
        return accumulate(s.begin(),s.end(),INT_MIN/2,[](int a,int b){
            return max({a,a+b,b});
        });
    }
};