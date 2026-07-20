class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        int ts = row*col;
        k %= ts;
        vector<vector<int>> ans(row, vector<int>(col, 0));
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                int idx = (i * col + j - k + ts) % ts; 
                int rowId = idx / col;
                int colId = idx % col;
                ans[i][j] = grid[rowId][colId];
            }
        }
        return ans;
    }
};