// Last updated: 5/18/2026, 3:40:10 PM
class Solution {
public:
    bool dfs(vector<int>& color, vector<vector<int>>& graph, int i) {
        for (auto neighbor : graph[i]) {
            if (color[neighbor] != -1 && color[neighbor] == color[i]) {
                return false;
            }
            if (color[neighbor] == -1) {
                color[neighbor] = !color[i];
                if (dfs(color, graph, neighbor) == false) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        bool res;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
               res= dfs(color, graph, i);
            }
            if(!res) return false;
        }
        return true;
    }
};