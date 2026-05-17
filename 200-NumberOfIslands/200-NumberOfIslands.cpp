// Last updated: 5/17/2026, 5:52:02 PM
class Solution {
public:
    void bfs(vector<vector<int>>& visited, vector<vector<char>>& grid, int r,
             int c) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({r, c});
        visited[r][c] = 1;
        while (!q.empty()) {
            int crow = q.front().first;
            int ccol = q.front().second;
            q.pop();
            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int dr = crow + delrow[i];
                int dc = ccol + delcol[i];
                if (dr < n && dr >= 0 && dc < m && dc >= 0 &&
                    grid[dr][dc] == '1' && visited[dr][dc] == 0) {
                    q.push({dr, dc});
                    visited[dr][dc] = 1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && visited[i][j] == 0) {
                        count++;
                        bfs(visited, grid, i, j);
                    }
                }
            }
            return count;
        }
    };