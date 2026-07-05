class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    int n, m, check = 0;
    void dfs(int r, int c, int time, vector <vector<bool>> &vis, vector <vector<int>> &g){
        vis[r][c] = 1;
        if(r == n-1 and c == m - 1) {
            check = true;
            return;
        }
        for(int i = 0; i < 4; i++){
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(nr >= 0 and nc >= 0 and nr < n and nc < m and !vis[nr][nc] and g[nr][nc] <= time){
                dfs(nr, nc, time, vis, g);
            }
        }
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        int lo = 0, hi = 1e4, ans = 0;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            check = 0;
            vector <vector<bool>> vis(n, vector <bool>(m, 0));
            dfs(0, 0, mid, vis, grid);
            if(check and mid >= grid[0][0]) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};
