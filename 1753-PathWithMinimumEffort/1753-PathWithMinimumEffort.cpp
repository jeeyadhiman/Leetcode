// Last updated: 6/2/2026, 1:19:40 PM
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int effort = curr.first;
            int r = curr.second.first;
            int c = curr.second.second;

            if(r == n - 1 && c == m - 1)
                return effort;

            for(int i = 0; i < 4; i++) {

                int nr = r + delrow[i];
                int nc = c + delcol[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m) {

                    int newEffort =
                        max(effort,
                            abs(heights[r][c] - heights[nr][nc]));

                    if(newEffort < dist[nr][nc]) {

                        dist[nr][nc] = newEffort;

                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }

        return 0;
    }
};