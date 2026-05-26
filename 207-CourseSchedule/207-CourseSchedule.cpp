// Last updated: 5/26/2026, 2:57:36 PM
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int N= numCourses;
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int b=prerequisites[i][1];
            int a=prerequisites[i][0];
            adj[b].push_back(a);
        }
        vector<int> indegree(N,0);
        int count=0;
        for(int i=0;i<N;i++){
            for(auto neighbor : adj[i]){
                indegree[neighbor]++;
            }
        }
        queue<int> q;
        for(int i=0;i<N;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for (auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(count==N) return true;
        return false;
    }
};