class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //Maintain a stack <Temp, index>
        stack<pair<int, int>>st;

        int n = temperatures.size();
        vector<int>ans(n);
        for(int i=n-1; i>=0; i--){
            // if(st.empty()){
            //     ans[i] = 0;
            //     st.push({temperatures[i], i});
            // }
            while(!st.empty()){
                if(temperatures[i]<st.top().first){
                    ans[i] = (st.top().second-i);
                    st.push({temperatures[i], i});
                    break;
                }
                st.pop();
            }
            if(st.empty()){
                ans[i] = 0;
                st.push({temperatures[i], i});
            }
            
        }
        return ans;
    }
};
