class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0;
        int maxLen = 0;
        int maxRepeat = 0;
        unordered_map<char, int> map; // key should be char, not int

        for (int end = 0; end < s.size(); end++) {
            char cur = s[end];
            map[cur]++;
            maxRepeat = max(maxRepeat, map[cur]);

            // If more than k chars need to be replaced
            if ((end - start + 1) - maxRepeat > k) {
                map[s[start]]--;
                start++;
            }

            maxLen = max(maxLen, end - start + 1);
        }
        return maxLen;
    }
};
