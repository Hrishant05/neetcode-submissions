class Solution {
public:
    int trap(vector<int>& height) {
        //Pre compute Lmax and Rmax arrs
        //These will tell us for a particular space the prev highest and next highest
        int n = height.size();
        vector<int>Rmax(n);
        Rmax[n-1] = height[n-1];
        
        for(int i=n-2; i>=0; i--){
            Rmax[i] = max(Rmax[i+1], height[i]);
        }

        int Lmax = height[0];
        int ans = 0;
        for(int i=1; i<n-1; i++){
            int temp = min(Lmax, Rmax[i+1]);
            if(height[i]<temp){
                ans += (temp-height[i]);
            }
            Lmax = max(Lmax, height[i]);
        }
        return ans;
    }
};
