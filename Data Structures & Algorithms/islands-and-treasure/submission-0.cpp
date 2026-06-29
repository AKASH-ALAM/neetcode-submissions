class Solution {
public:
    int row, col;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    void dfs (int r, int c, int cnt, vector <vector<int>> &g){
        for(int i = 0; i < 4; i++){
            int nrow = r + dx[i];
            int ncol = c + dy[i];
            if(nrow >= 0 and ncol >= 0 and nrow < row and ncol < col and g[nrow][ncol] != -1 and g[nrow][ncol] != 0){
                if(g[nrow][ncol] > cnt) {
                    g[nrow][ncol] = cnt;
                    dfs(nrow, ncol, cnt + 1, g);
                }
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        row = (int) grid.size(); col = (int) grid[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 0) dfs(i, j, 1, grid);
            }
        }    
    }
};
