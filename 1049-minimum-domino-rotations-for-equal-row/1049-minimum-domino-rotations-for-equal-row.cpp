class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {

        int n = tops.size();
        vector<int> top(7, 0), bottom(7, 0), same(7, 0);

        for(int i=0;i<tops.size();i++) {
            top[tops[i]]++;
            bottom[bottoms[i]]++;
            if(tops[i] == bottoms[i]) 
                same[tops[i]]++;
        }

        int ans = INT_MAX;
        for(int i=0;i<7;i++) {
            if(top[i] + bottom[i] - same[i] == n) {
                ans = min({ans, n - top[i], n - bottom[i]});
            }
        }

        return ans == INT_MAX ? -1 : ans;
        
    }
};