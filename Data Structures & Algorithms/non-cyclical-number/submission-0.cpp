class Solution {
public:
    int giveSum(int n){
        int ans = 0;
        while(n!=0){
            ans += pow(n%10, 2);
            n/=10;
        }
        return ans;
    }
    bool isHappy(int n) {
        //Cycle detection
        vector<bool>vis(244, false);

        while(n!=1){
            n = giveSum(n);
            if(vis[n]) return false;
            else vis[n] = true;
        }
        return true;
    }
};
