class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n, vector<int>(n, -1));
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
        
        int dr[] = {-1,0,1,0}, dc[] = {0,1,0,-1};
        
        while(!q.empty()) {
            auto [r,c] = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if(nr >= 0 && nc >= 0 && nr < n && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        
        int lo = 0, hi = 2*n, ans = 0;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if([&](){
                if(dist[0][0] < mid) return false;
                queue<pair<int,int>> q;
                vector<vector<bool>> vis(n, vector<bool>(n));
                q.push({0,0});
                vis[0][0] = true;
                while(!q.empty()) {
                    auto [r,c] = q.front(); q.pop();
                    if(r == n-1 && c == n-1) return true;
                    for(int i = 0; i < 4; i++) {
                        int nr = r + dr[i], nc = c + dc[i];
                        if(nr >= 0 && nc >= 0 && nr < n && nc < n && !vis[nr][nc] && dist[nr][nc] >= mid) {
                            vis[nr][nc] = true;
                            q.push({nr, nc});
                        }
                    }
                }
                return false;
            }()) {
                ans = mid;
                lo = mid + 1;
            } else hi = mid - 1;
        }
        return ans;
    }
};