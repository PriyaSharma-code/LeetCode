class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>answer;
        answer.push_back(vector<int>());
        int startIndex=0;
        int endIndex=0;
        for(int i=0;i<nums.size();i++){
            startIndex=0;

            if(i>0 and nums[i]==nums[i-1]){
                startIndex=endIndex+1;
            }
            endIndex=answer.size()-1;

            for(int j=startIndex;j<=endIndex;j++){
                vector<int>set=answer[j];
                set.push_back(nums[i]);
                answer.push_back(set);
            }
        }
        return answer;
    }
};