class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        string str = "";
        for(int i=0; i<n; i++){
            if(isalnum(s[i])){
                str += (char)tolower((int)s[i]);
            }
        }


        int newLen = str.length();

        for(int i=0; i<(newLen/2); i++){
            if(str[i]!=str[newLen-i-1]){
                cout << i << endl;
                return false;
            }
        }
        
        return true;
    }
};
