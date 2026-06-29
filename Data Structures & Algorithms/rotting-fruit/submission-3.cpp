class Solution {
public:
    int row, col;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    void dfs(int r, int c, vector <vector<int>> &dis, vector<vector<int>> &g){
        for(int i = 0; i < 4; i++){
            int nrow = r + dx[i];
            int ncol = c + dy[i];
            if(nrow >= 0 and ncol >= 0 and nrow < row and ncol < col and g[nrow][ncol] != 0 and g[nrow][ncol] != 2){
                if(dis[nrow][ncol] > dis[r][c] + 1){
                    dis[nrow][ncol] = dis[r][c] + 1;
                    dfs(nrow, ncol, dis, g);
                }
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        row = grid.size(), col = grid[0].size();
        vector <vector<int>> dis(row, vector<int>(col, INT_MAX)); 

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 2) {
                    dis[i][j] = 0;
                    dfs(i, j, dis, grid);
                }
            }
        }

        int mx = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++) {
                if(dis[i][j] == INT_MAX and grid[i][j] == 1) return -1;
                if(dis[i][j] != INT_MAX) mx = max(mx, dis[i][j]);
            }
        }
        return mx;
    }
};
