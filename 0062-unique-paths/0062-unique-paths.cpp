class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);          // First row is all 1s
        for (int i = 1; i < m; ++i) {  // From second row
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1];    // dp[j] = from top + from left
            }
        }
        return dp[n - 1];
    }
};
