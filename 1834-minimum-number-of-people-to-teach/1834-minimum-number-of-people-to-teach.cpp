class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> cncon;
        for(auto f: friendships){
            unordered_map<int,int> mp;
            bool conm = false;
            for(int lan : languages[f[0]-1]){
                mp[lan] = 1;
            }
            for(int lan : languages[f[1] -1]){
                if(mp[lan]){
                    conm = true;
                    break;
                }
            }
            if(!conm){
                cncon.insert(f[0] -1);
                cncon.insert(f[1] -1);
            }

        }
        int max_cnt = 0;
        vector<int> cnt(n+1,0);
        for(auto friendships:cncon){
            for(int lan: languages[friendships]){
                cnt[lan]++;
                max_cnt = max(max_cnt,cnt[lan]);
            }
        }
        return cncon.size() - max_cnt;
    }
};