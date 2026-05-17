// Last updated: 5/17/2026, 5:51:36 PM
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
         vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    visited[i][j] = 2;
                    q.push({{i, j}, 0});
                }
            }
        }
        int time = 0;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        while (!q.empty()) {
            pair<pair<int, int>, int> cur = q.front();
            int u = cur.first.first;
            int v = cur.first.second;
            int t = cur.second;
            time=max(time,t);
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = u + delrow[i];
                int ncol = v + delcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    visited[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    visited[nrow][ncol] = 2;
                }
            }
        }
        for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==1 && visited[i][j]!=2)
                    return -1;
                }
            }
        return time;
    }
};