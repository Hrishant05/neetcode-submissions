class Solution {
public:
    // int func(int n, vector<int>&dp){
    //     if(n==0 || n==1) return 1;

    //     if(dp[n]!=-1) return dp[n];

    //     return dp[n] = func(n-1, dp)+func(n-2, dp);
    // }
    int climbStairs(int n) {
        int oldest = 1;
        int old = 1;
        int curr;
        for(int i=2; i<=n; i++){
            curr = old+oldest;
            oldest = old;
            old = curr;
        }
        return old;
        // return func(n, dp);
    }
};
