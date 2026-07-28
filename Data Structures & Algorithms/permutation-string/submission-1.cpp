class Solution {
public:
    bool isPresent(vector<int>&f1, vector<int>&f2){
        for(int i=0; i<26; i++){
            if(f1[i]!=f2[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        //Sliding Window i fixed size of s1
        int n1 = s1.length();
        int n2 = s2.length();

        if(n1>n2) return false;

        vector<int>f1(26, 0);
        for(int i=0; i<n1; i++){
            f1[s1[i]-'a']++;
        }

        // unordered_map<char, int>freq;
        vector<int>freq(26, 0);
        

        for(int i=0; i<=n2-n1; i++){
            if(i==0){
                for(int j=0; j<n1; j++){
                    freq[s2[j]-'a']++;
                }
            }
            else{
                freq[s2[i-1]-'a']--;
                freq[s2[i+n1-1]-'a']++;
            }
            
            if(isPresent(f1, freq)){
                return true;
            }
        }

        return false;

    }
};
