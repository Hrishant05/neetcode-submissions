class Solution {
public:
    bool checkRow(vector<vector<char>>& board, int row){
        unordered_set<char>s;
        for(int j=0; j<9; j++){
            if(board[row][j]=='.') continue;
            if(s.find(board[row][j])!=s.end()){
                return false;
            }
            s.insert(board[row][j]);
        }
        return true;
    }
    bool checkCol(vector<vector<char>>& board, int col){
        unordered_set<char>s;
        for(int i=0; i<9; i++){
            if(board[i][col]=='.') continue;
            if(s.find(board[i][col])!=s.end()){
                return false;
            }
            s.insert(board[i][col]);
        }
        return true;
    }

    bool checkSquare(vector<vector<char>>& board, int sq){
        int r = (sq/3)*3;
        int c = (sq%3)*3;
        unordered_set<char>s;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[r+i][c+j]=='.') continue;
                if(s.find(board[r+i][c+j])!=s.end()){
                    // cout << r+i << " "<<c+j << endl;
                    return false;
                }
                s.insert(board[r+i][c+j]);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        //Checking all rows
        for(int i=0; i<9; i++){
            if(!checkRow(board, i)) return false;
        }

        

        //Checking all col
        for(int j=0; j<9; j++){
            if(!checkCol(board, j)) return false;
        }

        

        //Checking all squares
        for(int sq=0; sq<9; sq++){
            if(!checkSquare(board, sq)) return false;
        }

        

        return true;
    }
};

/*
0 -> 0,0
1 -> 0,3
2 -> 0,6
3 -> 3,0
4

*/
