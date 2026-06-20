class TrieNode {
public:
    TrieNode* child[2];

    TrieNode() {
        for (int i = 0; i < 2; i++) {
            child[i] = NULL;
        }
    }
};
class trieB {
    TrieNode* root;

public:
    trieB() { 
        root = new TrieNode(); 
    }

    void insert(int num) {
        TrieNode* temp = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!temp->child[bit]) {
                temp->child[bit] = new TrieNode();
            }
            temp = temp->child[bit];
        }
    }

    int findmax(int num) {
        int ans = 0;
        TrieNode* temp = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (temp->child[1 - bit]) {
                ans = ans | (1 << i);
                temp = temp->child[1 - bit];
            } else {
                temp = temp->child[bit];
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        trieB* t = new trieB();
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int m = queries.size();
        vector<int> ans(m);

        vector<pair<int, int>> q_max(m);
        for (int i = 0; i < m; i++) {
            q_max[i] = {queries[i][1], i};
        }
        sort(q_max.begin(), q_max.end());
        int j = 0;
        for (int i = 0; i < m; i++) {
            int el = q_max[i].first;
            int ind = q_max[i].second;
            while (j < n && nums[j] <= el) {
                t->insert(nums[j]);
                j++;
            }
            if (j == 0) {
                ans[ind] = -1;
            } else {
                ans[ind] = t->findmax(queries[ind][0]);
            }
        }

        return ans;
    }
};