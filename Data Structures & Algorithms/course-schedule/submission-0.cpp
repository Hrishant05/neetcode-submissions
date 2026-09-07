class Solution {
public:
    bool dfs(int node, vector<int>&vis, vector<int>&pathVis, vector<vector<int>>&adjL){
        vis[node] = 1;
        pathVis[node] = 1;

        bool ans = true;

        for(int i=0; i<adjL[node].size(); i++){
            int newNode = adjL[node][i];
            //Single condition for game over
            if(vis[newNode] && pathVis[newNode]){
                return false;
            }
            if(!vis[newNode]){
                ans = ans && dfs(newNode, vis, pathVis, adjL);
                if(!ans) return ans;
            }
        }
        pathVis[node] = 0;
        return ans;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //Cycle detection in graph
        vector<vector<int>>adjL(numCourses);
        for(auto p : prerequisites){
            int before = p[1];
            int after = p[0];
            adjL[before].push_back(after);
        }

        vector<int>vis(numCourses, 0);
        vector<int>pathVis(numCourses, 0);

        bool ans = true;

        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                ans = ans && dfs(i, vis, pathVis, adjL);
            }

            if(!ans) return false;
        }
        return ans;
    }
};
