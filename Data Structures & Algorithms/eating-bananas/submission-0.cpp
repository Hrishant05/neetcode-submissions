class Solution {
public:
    int calculateTime(int rate, vector<int>& piles){
        int hours = 0;
        for(int num: piles){
            hours += ceil(num*1.0/rate);
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // The rate lies between 1 and max(piles[i])
        //Find min while time cant cross h

        int low = 1;
        int high = 0;
        for(int num: piles){
            high = max(high, num);
        }
        int ans = high;
        while(low<=high){
            int mid = (low+high)/2;
            if(calculateTime(mid, piles)<=h){
                //Can be your answer still will try a lower rate
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};
