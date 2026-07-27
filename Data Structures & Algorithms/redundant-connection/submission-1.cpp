class Solution {
public:
    int findUpar(int node, vector<int>&par){
        if(par[node]==node) return node;

        return par[node] = findUpar(par[node], par);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>par(n+1);
        for(int i=1; i<=n; i++){
            par[i] = i;
        }

        for(int i=0; i<n; i++){
            int n1 = edges[i][0];
            int n2 = edges[i][1];

            if(findUpar(n1, par)==findUpar(n2, par)) return edges[i];
            else{
                par[findUpar(n2, par)] = findUpar(n1, par);
            }
        }


        return {};
    }
};
