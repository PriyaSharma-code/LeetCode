class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        set<int> ans;
        int majority = int(nums.size()/3);
        map<int,int> mp;

        for(int i = 0 ; i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>majority){
                ans.insert(nums[i]);
            }
        }
        vector<int> a;
        for(auto&e: ans){
            a.push_back(e);
        }
        return a;
    }
};