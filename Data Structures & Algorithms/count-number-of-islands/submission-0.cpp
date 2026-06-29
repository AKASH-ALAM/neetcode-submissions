class Solution {

private:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void dfs(int r, int c, vector <vector<char>> &g){
        g[r][c] = '0';
        for(int i = 0; i < 4; i++){
            int nrow = r + dx[i];
            int ncol = c + dy[i];
            if(nrow >= 0 and ncol >= 0 and nrow < (int) g.size() and ncol < (int) g[0].size() and g[nrow][ncol] == '1'){
                dfs(nrow, ncol, g);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int row = (int) grid.size(), col = (int) grid[0].size(), cnt = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(i, j, grid);
                }
            }
        }
        return cnt;
    }
};