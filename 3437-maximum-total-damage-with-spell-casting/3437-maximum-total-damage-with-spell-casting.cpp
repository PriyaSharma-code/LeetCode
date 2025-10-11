class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        // Sort the power array to handle the constraints more easily
    sort(power.begin(), power.end());
    
    // Create a map to count the occurrences of each power value
    unordered_map<int, int> freq;
    for (int p : power) {
        freq[p]++;
    }
    
    // Remove duplicates to get unique power values
    vector<int> uniquePower;
    for (int p : power) {
        if (uniquePower.empty() || uniquePower.back() != p) {
            uniquePower.push_back(p);
        }
    }
    
    // Initialize DP array
    int n = uniquePower.size();
    vector<long long> dp(n, 0);
    
    // Base case
    dp[0] = static_cast<long long>(uniquePower[0]) * freq[uniquePower[0]];
    
    // Fill DP array
    for (int i = 1; i < n; i++) {
        long long currentPower = uniquePower[i];
        long long currentDamage = currentPower * freq[currentPower];
        
        // Option 1: Take current power value
        long long take = currentDamage;
        // Check for non-conflicting previous power value
        int j = i - 1;
        while (j >= 0 && (currentPower - uniquePower[j] <= 2)) {
            j--;
        }
        if (j >= 0) {
            take += dp[j];
        }
        
        // Option 2: Skip current power value
        long long skip = dp[i - 1];
        
        // Choose the maximum of both options
        dp[i] = max(take, skip);
    }
    
    // The last element in dp array contains the result
    return dp[n - 1];
    }
};