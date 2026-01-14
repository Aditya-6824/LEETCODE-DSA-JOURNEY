class Solution {
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i==0 && j==0)return grid[i][j];
        if(i<0 || j<0) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        int left = grid[i][j] + solve(i-1, j, grid, dp);
        int top = grid[i][j] + solve(i, j-1, grid, dp);

        return dp[i][j] = min(left, top);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int i = grid.size(), j=grid[0].size();
        vector<vector<int>> dp(i, vector<int>(j, -1));
        return solve(i-1, j-1, grid, dp);
    }
};