// Last updated: 5/17/2026, 5:52:13 PM
class Solution {
public:

    void dfs(int row, int col,
             vector<vector<char>>& board,
             vector<vector<int>>& visited) {

        int n = board.size();
        int m = board[0].size();

        visited[row][col] = 1;

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        for(int i=0;i<4;i++) {

            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && ncol >= 0 &&
               nrow < n && ncol < m &&
               board[nrow][ncol] == 'O' &&
               !visited[nrow][ncol]) {

                dfs(nrow, ncol, board, visited);
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        // first row
        for(int j=0;j<m;j++) {
            if(board[0][j] == 'O' && !visited[0][j]) {
                dfs(0, j, board, visited);
            }
        }

        // last row
        for(int j=0;j<m;j++) {
            if(board[n-1][j] == 'O' && !visited[n-1][j]) {
                dfs(n-1, j, board, visited);
            }
        }

        // first column
        for(int i=0;i<n;i++) {
            if(board[i][0] == 'O' && !visited[i][0]) {
                dfs(i, 0, board, visited);
            }
        }

        // last column
        for(int i=0;i<n;i++) {
            if(board[i][m-1] == 'O' && !visited[i][m-1]) {
                dfs(i, m-1, board, visited);
            }
        }

        // convert trapped O to X
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {

                if(board[i][j] == 'O' &&
                   !visited[i][j]) {

                    board[i][j] = 'X';
                }
            }
        }
    }
};