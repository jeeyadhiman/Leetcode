// Last updated: 5/17/2026, 5:51:43 PM
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size();
        int m = image[0].size();
        int curc = image[sr][sc];
        if(curc == color) return image;
        vector<vector<int>> result=image;
        queue<pair<int, int>> q;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        q.push({sr, sc});
        while (!q.empty()) {
            result[q.front().first][q.front().second] = color;
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = r+ delrow[i];
                int ncol =c + delcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    image[nrow][ncol] == curc && result[nrow][ncol] == curc){
                        q.push({nrow,ncol});
                        result[nrow][ncol]=color;
                    }
            }
        }
        return result;
    }
};