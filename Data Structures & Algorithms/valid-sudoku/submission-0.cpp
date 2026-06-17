class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = 9, col = 9;
        for(int i = 0; i < row; i++){
            map <char, int> mp1, mp2;
            for(int j = 0; j < col; j++){
                if(board[i][j] != '.') mp1[board[i][j]]++;
                if(board[i][j] != '.' and mp1[board[i][j]] > 1) return false;
            }
            for(int j = 0; j < col; j++){
                if(board[j][i] != '.') mp2[board[j][i]]++;
                if(board[j][i] != '.' and mp2[board[j][i]] > 1) return false;
            }
        }
        for(int i = 0; i < row; i += 3){
            for(int j = 0; j < col; j += 3){
                map <char, int> mp;
                for(int l = i; l < i + 3 and l < row; l++){
                    for(int k = j; k < j + 3 and k < col; k++){
                        if(board[l][k] != '.') mp[board[l][k]]++;
                        if(mp[board[l][k]] > 1) return false;
                    }
                }
            }
        }
        return true;
    }
};
