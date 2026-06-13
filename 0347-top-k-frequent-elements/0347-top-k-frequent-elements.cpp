class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> map;
        for(auto num:nums) map[num]++;

        // vector<int> bucket(n+1);
        // for(auto it:map){
        //     bucket[it.first]=
        // }

        vector<pair<int,int>> v(map.begin(),map.end());
        sort(v.begin(),v.end(),[](auto &a,auto &b){
            return a.second>b.second;
        });

        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.emplace_back(v[i].first);
        }
        return ans;


    }
};