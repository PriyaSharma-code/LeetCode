class Solution {
public:
    int minDeletion(string s, int k) {
        int n = s.length();
        if(k>n){
            return 0;
        }
        unordered_map<char,int> freq;
        for(int i = 0; i <n ;i++){
            freq[s[i]]++;
        }
        int x = freq.size();
        if(x<=k) return 0;
        int z = x - k;

        vector<pair<char,int>> vec(freq.begin(),freq.end());
        sort(vec.begin(),vec.end(),[](pair<char,int> &a, pair<char,int> &b){
            return a.second<b.second;
        });

        int sum = 0;
        for(int i = 0 ; i<z;i++){
            sum+= vec[i].second;
        }
        return sum;

    }
};