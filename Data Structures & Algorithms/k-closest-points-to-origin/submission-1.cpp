class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //We want closest points hence minimise hence max heap
        priority_queue<vector<double>>pq;

        for(int i=0; i<points.size(); i++){
            double x = (double)points[i][0];
            double y = (double)points[i][1];

            double dist = pow(x, 2)+pow(y, 2);

            pq.push({dist, x, y});

            while(pq.size()>k){
                pq.pop();
            }
        }

        vector<vector<int>>ans;
        while(!pq.empty()){
            int x = (int)pq.top()[1];
            int y = (int)pq.top()[2];
            pq.pop();
            ans.push_back({x, y});
        }
        return ans;
    }
};
