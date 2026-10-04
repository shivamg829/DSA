class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> res(n, vector<int>(m, INT_MAX));
        res[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {0, 0}});
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        while (!pq.empty()) {
            auto [dis, cell] = pq.top();
            pq.pop();
            int row = cell.first;
            int col = cell.second;
            if (dis > res[row][col]) continue;
            if (row == n - 1 && col == m - 1) return dis;
            for (int i = 0; i < 4; i++) {
                int nr = row + dx[i];
                int nc = col + dy[i];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                int newEffort = max(dis, abs(heights[nr][nc] - heights[row][col]));
                if (newEffort < res[nr][nc]) {
                    res[nr][nc] = newEffort;
                    pq.push({newEffort, {nr, nc}});
                }
            }
        }
        return res[n - 1][m - 1];
    }
};