class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        deque <pair<int ,int>> de;
        int n = (int) grid.size(), m = grid[0].size();
        vector <vector<int>> dis(n, vector<int>(m, INT_MAX));

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    de.push_front({i, j});
                    dis[i][j] = 0;
                }
            }
        }

        while(!de.empty()){
            auto [row, col] = de.front();
            de.pop_front();
            for(int i = 0; i < 4; i++){
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                if(nrow >= 0 and ncol >= 0 and nrow < n and ncol < m and grid[nrow][ncol] != 0 and grid[nrow][ncol] != 2){
                    if(dis[nrow][ncol] > dis[row][col] + 1){
                        dis[nrow][ncol] = dis[row][col] + 1;
                        de.push_back({nrow, ncol});
                    }
                }
            }
        }

        int mx = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(dis[i][j] == INT_MAX and grid[i][j] == 1) return -1;
                if(dis[i][j] != INT_MAX) mx = max(mx, dis[i][j]);
            }
        }
        return mx;
    }
};