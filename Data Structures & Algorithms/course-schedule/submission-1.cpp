class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //Calculate indegrees
        vector<int>inDeg(numCourses, 0);

        vector<vector<int>>adjL(numCourses);
        for(auto p : prerequisites){
            int before = p[1];
            int after = p[0];

            adjL[before].push_back(after);
            inDeg[after]++;
        }

        //Starting with the nodes whose indeg = 0
        queue<int>q;
        int nodesLeft = numCourses;
        for(int i=0; i<numCourses; i++){
            if(inDeg[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            nodesLeft--;

            for(int i=0; i<adjL[node].size(); i++){
                int newNode = adjL[node][i];
                inDeg[newNode]--;
                if(!inDeg[newNode]){
                    q.push(newNode);
                }
            }
        }

        //Seeing if any nodes are left
        return !nodesLeft;
    }
};
