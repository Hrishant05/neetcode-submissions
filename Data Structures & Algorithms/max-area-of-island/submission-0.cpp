class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis, int &ans, vector<int>&dr, vector<int>&dc){
        vis[r][c] = 1;
        ans++;
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0; i<4; i++){
            int newR = r+dr[i];
            int newC = c + dc[i];

            if(newR>=0 && newR<m && newC>=0 and newC<n){
                if(grid[newR][newC] && !vis[newR][newC]){
                    dfs(newR, newC, grid, vis, ans, dr, dc);
                }
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //Trying with DFS
        int maxAns = 0;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m, vector<int>(n, 0));
        vector<int>dr = {1, 0, -1, 0};
        vector<int>dc = {0, 1, 0, -1};

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    int ans = 0;
                    cout << i << " " << j << endl;
                    dfs(i, j, grid, vis, ans, dr, dc);

                    maxAns = max(maxAns, ans);
                }
            }
        }

        return maxAns;
    }
};
