class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        queue<pair<int, int>>q;
        for(int i = 0; i<n; i++){
            if(board[i][0]=='O' && !vis[i][0]){
                vis[i][0]=1;
                q.push({i , 0});
            }
            if(board[i][m-1]=='O' && !vis[i][m-1]){
                vis[i][m-1]=1;
                q.push({i,m-1});
            }
        }
        for(int i = 0; i<m; i++){
            if(board[0][i]=='O' && !vis[0][i]){
                vis[0][i]=1;
                q.push({0 , i});
            }
            if(board[n-1][i]=='O' && !vis[n-1][i]){
                vis[n-1][i]=1;
                q.push({n-1,i});
            }
        }
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            for(int i = 0; i<4; i++){
                int nrow = r+dr[i];
                int ncol = c+dc[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && board[nrow][ncol]=='O' && !vis[nrow][ncol]){
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X',
                    vis[i][j]=1;
                }
            }
        }
    }
};