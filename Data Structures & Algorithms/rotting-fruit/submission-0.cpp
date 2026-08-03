class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m, vector<int>(n, 0));
        //Find all rotten fruits and put in queue
        queue<pair<int, int>>q; //<r, c>

        int freshFruits = 0;
        int rottenFruits = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1) freshFruits++;
                else if(grid[i][j]==2){
                    rottenFruits++;
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }

        //Base checks
        if(freshFruits==0)return 0;
        if(rottenFruits==0) return -1;

        vector<int>dr = {0, 1, 0, -1};
        vector<int>dc = {1, 0, -1, 0};

        //Main BFS
        int time = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int j=0; j<4; j++){
                    int newR = r+dr[j];
                    int newC = c+dc[j];

                    if(newR<m && newR>=0 && newC<n && newC>=0 && !vis[newR][newC] && grid[newR][newC]==1){
                        vis[newR][newC] = true;
                        q.push({newR, newC});
                        rottenFruits++;
                        freshFruits--;
                    }
                }
            }
            time++;
            if(freshFruits==0) return time;
        }
        
        //Final checks
        if(freshFruits) return -1;
        else return time; 

    }
};
