class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>&vis){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row, col});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            for(int i = 0; i<4; i++){
                int nrow = r + dr[i];
                int ncol = c + dc[i];
                if(nrow<n && ncol<m && nrow>=0 && ncol>=0 && vis[nrow][ncol]==0 && grid[nrow][ncol]=='1'){
                    vis[nrow][ncol]=1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    res++;
                    bfs(i, j, grid, vis);
                }
            }
        }
        return res;
    }
};