class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> map;
        int maxLen = 0;
        int left = 0;

        for(int right = 0; right< s.size();right++){
            char curr = s[right];

            if(map.find(curr)!=map.end() && map[curr]>=left){
                left = map[curr]+1;
            }
            map[curr] = right;
            maxLen = max(maxLen, right - left +1);
        }
        return maxLen;
    }
};