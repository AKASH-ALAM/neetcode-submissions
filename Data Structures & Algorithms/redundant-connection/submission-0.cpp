struct DSU {        // O(α(N))—Here α is Inverse Ackermann function। O(4xalpha) = Amortized Constant time
    vector <int> Sz, Par;
    DSU (int n) {
        Sz.resize(n + 1), Par.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            Par[i] = i, Sz[i] = 1;
        }
    }

    int Find (int u) {
        return Par[u] = Par[u] == u ? u : Find(Par[u]);
    }

    void Union (int u, int v) {
        u = Find(u), v = Find(v);
        if (u == v) return;
        if(Sz[u] < Sz[v]) swap(u, v);
        Par[v] = u, Sz[u] += Sz[v];
    }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = (int) edges.size();
        DSU dsu(N);
        for(auto v : edges){
            if(dsu.Find(v[0]) == dsu.Find(v[1])) return {v[0], v[1]};
            else dsu.Union(v[0], v[1]); 
        }
    }
};
