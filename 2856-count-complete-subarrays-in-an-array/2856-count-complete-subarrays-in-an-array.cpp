class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> dis(nums.begin(),nums.end());
        int distinct = dis.size();
        int n = nums.size();
        int right = 0;
        unordered_map<int,int> map;
        int ans = 0;

        for(int left = 0; left<n; left++){
            if(left>0){
                int remove = nums[left -1];
                map[remove]--;
                if(map[remove]==0){
                    map.erase(remove);
                }
            }
            while(right< n && map.size() < distinct){
                int add = nums[right];
                map[add]++;
                right++;
            }
            if(map.size() ==distinct){
                ans +=(n - right +1);
            }
        }
        return ans;
    }
};