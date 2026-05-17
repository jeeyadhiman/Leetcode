// Last updated: 5/17/2026, 5:51:29 PM
class Solution {
public:
    void dfs(int row,int col,vector<vector<int>> &visited,vector<vector<int>> &grid){
        int n= grid.size();
        int m= grid[0].size();
        visited[row][col]=1;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int r=row+delrow[i];
            int c=col+delcol[i];
            if(r>=0 && c>=0 && r<n && c<m && grid[r][c]==1 && visited[r][c]==0){
                dfs(r,c,visited,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        int count=0;
        vector<vector<int>> visited(n, vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(grid[0][i]==1 && visited[0][i]==0){
                dfs(0,i,visited,grid);
            }
        }
        for(int i=0;i<m;i++){
            if(grid[n-1][i]==1 && visited[n-1][i]==0){
                dfs(n-1,i,visited,grid);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && visited[i][0]==0){
                dfs(i,0,visited,grid);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][m-1]==1 && visited[i][m-1]==0){
                dfs(i,m-1,visited,grid);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]==0) count++;
            }
        }
        return count;
    }
};