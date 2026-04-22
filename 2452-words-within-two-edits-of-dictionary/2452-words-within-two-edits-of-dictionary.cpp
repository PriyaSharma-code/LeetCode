class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        vector<string> ans;
        int n = queries[0].size() ;
        if (dictionary.size() == 0) {
            return ans;
        }
        for (auto& c : queries) {
            for (auto& s : dictionary) {
                int count = 0;
                for (int i = 0; i < n; i++) {
                    if (c[i] != s[i]) {
                        count++;
                    }
                    if (count > 2) {
                        break;
                    }
                }
                if (count <= 2) {
                    ans.push_back(c);
                    break;
                }
            }
        }
        return ans;
    }
};