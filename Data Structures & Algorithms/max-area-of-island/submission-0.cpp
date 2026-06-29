class Solution {
private:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int mx = 0, cnt = 0;

    void dfs(int r, int c, vector <vector<int>> &g){
        g[r][c] = 0, cnt++;
        for(int i = 0; i < 4; i++){
            int nrow = r + dx[i];
            int ncol = c + dy[i];
            if(nrow >= 0 and ncol >= 0 and nrow < (int) g.size() and ncol < (int) g[0].size() and g[nrow][ncol] == 1){
                dfs(nrow, ncol, g);
            }
        }
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = (int) grid.size(), col = (int) grid[0].size();

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                cnt = 0;
                if(grid[i][j] == 1){
                    dfs(i, j, grid);
                }
                mx = max(mx, cnt);
            }
        }
        return mx;
    }
};