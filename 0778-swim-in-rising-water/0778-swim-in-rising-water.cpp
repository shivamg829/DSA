class Solution {
public:
    bool bfs(vector<vector<int>>& grid, int n, int m, int guess){
        // Start or end cell deeper than guess => no path
        if(grid[0][0] > guess || grid[n-1][m-1] > guess) return false;

        queue<pair<int, int>> pq;
        pq.push({0, 0});
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[0][0] = 1;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while(!pq.empty()){
            pair<int, int> p = pq.front();
            pq.pop();
            int x = p.first;
            int y = p.second;

            if(x == n-1 && y == m-1) return true;

            for(int d = 0; d < 4; d++){
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m
                   && !vis[nx][ny] && grid[nx][ny] <= guess){
                    vis[nx][ny] = 1;
                    pq.push({nx, ny});
                }
            }
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int low = 0;
        int high = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                high = max(high, grid[i][j]);
            }
        }
        int res = high;              // safe fallback
        while(low<=high){
            int guess = low + (high-low)/2;
            if(bfs(grid, n, m, guess)){   // was: bfs(grid, n, m, res)
                res = guess;
                high = guess-1;
            }else{
                low = guess+1;
            }
        }
        return res;
    }
};