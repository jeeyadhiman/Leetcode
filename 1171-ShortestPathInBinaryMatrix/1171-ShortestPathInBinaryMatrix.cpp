// Last updated: 5/29/2026, 5:29:28 PM
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited=grid;
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }
        if(n==1 && grid[0][0]==0) return 1;
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});
        visited[0][0]=1;
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    if (dr == 0 && dc == 0)
                        continue;
                    int nr = r + dr;
                    int nc = c + dc;
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                        grid[nr][nc] == 0 && visited[nr][nc]==0) {
                        q.push({{nr, nc}, dist + 1});
                        visited[nr][nc]=1;
                        if (nr == n - 1 && nc == n - 1) {
                            return dist + 1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};