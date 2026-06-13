class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> mp;

        for(auto &i : nums) {
            mp[i]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(const auto &[elem,freq] : mp){
            if(pq.size()<k) 
                pq.push({freq,elem});
            else if(pq.top().first<freq) {
                pq.pop();
                pq.push({freq,elem});
            }
            
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};