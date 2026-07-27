class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n-1;

        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]==target) return mid;

            //Left is sorted
            if(nums[mid]>=nums[left]){
                if(target>=nums[left] && target<nums[mid]){
                    right = mid - 1;
                }
                else{
                    left = mid+1;
                }
            }
            //Right is sorted
            else{
                if(target>nums[mid] && target<=nums[right]){
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
            }

        }

        return -1;
 
    }
};

/*
5 6 7 1 2 3 4

*/
