class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //Logic of prefix sum
        int n = nums.size();
        vector<int>l;
        vector<int>r(n+1);
        
        l.push_back(1);
        

        for(int i=0; i<n; i++){
            l.push_back(l[i]*nums[i]);
        }
        r[n] = 1;
        for(int i=n-1; i>=0; i--){
            r[i] = (r[i+1]*nums[i]);
        }

        //Final step
        vector<int>ans;

        for(int i=0; i<n; i++){
            ans.push_back(l[i]*r[i+1]);
        }
        return ans;

    }
};
/*
  1 2 4 6 
  1 1 2 8 48
  48 48 24 6 1
*/
