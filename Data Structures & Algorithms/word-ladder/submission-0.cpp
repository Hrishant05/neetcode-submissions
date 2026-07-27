class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>s1;
        set<string>vis;

        int words = wordList.size();

        bool isPoss = false;
        for(int i=0; i<words; i++){
            if(wordList[i]==endWord) isPoss = true;
            s1.insert(wordList[i]);
        }

        if(!isPoss) return 0;

        

        vis.insert(beginWord);
        queue<pair<string, int>>q;
        q.push({beginWord, 1});

        while(!q.empty()){
            string str = q.front().first;
            int cnt = q.front().second;
            q.pop();

            if(str==endWord) return cnt;

            for(int i=0; i<str.length(); i++){
                char og = str[i];
                for(int j=0; j<26; j++){
                    if('a'+j==og){
                        continue;
                    }
                    else{
                        str[i] = ('a'+j);
                    }
                    if(s1.find(str)!=s1.end() && vis.find(str)==vis.end()){
                        cout << str << endl;
                        q.push({str, cnt+1});
                        vis.insert(str);
                    }
                }
                str[i] = og;
            }
        }
        return 0;
    }
};
