// Last updated: 5/17/2026, 5:51:48 PM
class Solution {
public:
    void bfs(queue<pair<pair<int, int>, int>>& q, vector<vector<int>>& mat,
             vector<vector<int>>& visited,vector<vector<int>>& updated) {
        int u = mat.size();
        int v = mat[0].size();
        while (!q.empty()) {
            int n = q.front().first.first;
            int m = q.front().first.second;
            int t = q.front().second;
            q.pop();
            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int nrow = n + delrow[i];
                int ncol = m + delcol[i];
                if (nrow >= 0 && ncol >= 0 && nrow < u && ncol < v &&
                    mat[nrow][ncol] == 1 && updated[nrow][ncol] == 0) {
                    q.push({{nrow,ncol},t+1});
                    visited[nrow][ncol] =1;
                    updated[nrow][ncol]=t+1;
                }
            }
        }
    }
     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> updated(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) {
                q.push({{i, j}, 0});
                visited[i][j] = 1;
            }
        }
    }
    bfs(q, mat,visited,updated);
    return updated;
}

};