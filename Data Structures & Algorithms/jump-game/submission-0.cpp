class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachableInd = 0;

        for(int i=0; i<nums.size(); i++){
            if(i<=maxReachableInd){
                maxReachableInd = max(maxReachableInd, i+nums[i]);
            }
            else{
                return false;
            }
        }
        return true;
    }
};
