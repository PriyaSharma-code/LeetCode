class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int maxele=0;
        int maxfreq=0;
        vector<int>count(26,0);

        for(int right=0;right<s.length();right++){
            count[s[right]-'A']++;

            maxfreq=max(maxfreq,count[s[right]-'A']);

            int windowsize=right-left+1;
            if(windowsize-maxfreq>k){
                count[s[left]-'A']--;
                left++;
            }
            maxele=max(maxele,right-left+1);
        }
        return maxele;
    }
};