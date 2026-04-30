class Solution {
public:
    int maxPath(int i, int j, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int k, int usedCost) {
        if(i == 0 && j == 0) {
            int cost = (grid[0][0] == 0) ? 0 : 1;
            if(usedCost + cost > k) return INT_MIN;
            int score = (grid[0][0] == 0) ? 0 : (grid[0][0] == 1 ? 1 : 2);
            return score;
        }
        if(i < 0 || j < 0) return INT_MIN;
        
        if(dp[i][j][usedCost] != -1) return dp[i][j][usedCost];
        
        int currentCost = (grid[i][j] == 0) ? 0 : 1;
        int currentScore = (grid[i][j] == 0) ? 0 : (grid[i][j] == 1 ? 1 : 2);
        
        if(usedCost + currentCost > k) {
            dp[i][j][usedCost] = INT_MIN;
            return INT_MIN;
        }
        
        int up = maxPath(i-1, j, grid, dp, k, usedCost + currentCost);
        int left = maxPath(i, j-1, grid, dp, k, usedCost + currentCost);
        
        int best = max(up, left);
        if(best != INT_MIN) {
            dp[i][j][usedCost] = best + currentScore;
        } else {
            dp[i][j][usedCost] = INT_MIN;
        }
        return dp[i][j][usedCost];
    }
    
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));
        int ans = maxPath(n-1, m-1, grid, dp, k, 0);
        return ans == INT_MIN ? -1 : ans;
    }
};