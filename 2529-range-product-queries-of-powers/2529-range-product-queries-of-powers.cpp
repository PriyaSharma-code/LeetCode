class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        
        // Find the highest power of 2 <= n
        int power = 1;
        while (power <= n) power <<= 1;
        power >>= 1;

        // Store powers of 2 present in n's binary representation
        vector<int> powers;
        while (n > 0) {
            if (power <= n) {
                powers.push_back(power);
                n -= power;
            }
            power >>= 1;
        }

        int m = powers.size();
        vector<vector<int>> prefix(m, vector<int>(m, 0));

        // Build prefix product matrix
        for (int i = 0; i < m; i++) {
            prefix[i][i] = powers[m - 1 - i];
            for (int j = i + 1; j < m; j++) {
                prefix[i][j] = (1LL * prefix[i][j - 1] * powers[m - 1 - j]) % MOD;
            }
        }

        // Answer queries
        vector<int> res;
        for (auto& q : queries) {
            res.push_back(prefix[q[0]][q[1]]);
        }

        return res;
    }
};