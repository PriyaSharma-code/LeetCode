class Solution {
public:
    struct comp{
        bool operator()(pair<int,int>&p1, pair<int,int>&p2){
            return p1.second<p2.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> map;

        for(int num : nums){
            map[num]++;
        }

        typedef pair<int,int> pi;
        priority_queue<pi,vector<pi>,comp> heap;

        for(auto &entry : map){
            heap.push({entry.first,entry.second});
        }

        vector<int> ans;
        while(k-- >0){
            ans.push_back(heap.top().first);
            heap.pop();
        }
        return ans;
    }
};