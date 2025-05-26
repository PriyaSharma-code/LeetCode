class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char,int> freq;
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
        }
        vector<pair<char, int>> freqVec(freq.begin(), freq.end());
    sort(freqVec.begin(), freqVec.end(), [](pair<char, int>& a, pair<char, int>& b) {
        return a.second < b.second; 
    });
    int val = freq.size() - k;
    int ans = 0;
    for(int i=0;i<val;i++){
        ans += freqVec[i].second;
    }

    return ans;

        
    }
};