class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector <pair<int, int>> g[n+1];
        for(auto have : times){
            int u = have[0];
            int v = have[1];
            int w = have[2];
            g[u].push_back({v, w});
        }

        vector <int> dis(n+1, 1e8);
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        dis[k] = 0;

        while(!pq.empty()){
            auto [w, u] = pq.top();
            pq.pop();
            if(dis[u] < w) continue;
            for(auto [v, time] : g[u]){
                if(w + time < dis[v]){
                    dis[v] = w + time;
                    pq.push({dis[v], v});
                }
            }
        }
        int mx = 0;
        for(int i = 1; i <= n; i++) {
            mx = max(mx, dis[i]);
        }
        return mx == 1e8 ? -1 : mx;
    }
};

static const bool __boost = [] (){
    std::cin.tie (nullptr);
    std::cout.tie (nullptr);
    return std::ios_base::sync_with_stdio (false);
}();

// Custom memory pool for dynamic allocation using a pre-allocated buffer
const size_t BUFFER_SIZE = 0x30000000;
alignas (std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;

void *
operator new (size_t size){
    constexpr std::size_t alignment = alignof (std::max_align_t);
    size_t padding = (alignment - (buffer_pos % alignment)) % alignment;
    size_t total_size = size + padding;
    char *aligned_ptr = &buffer[buffer_pos + padding];
    buffer_pos += total_size;
    return aligned_ptr;
}

void operator delete (void * /*unused*/, unsigned long /*unused*/) noexcept {}
void operator delete (void * /*unused*/) noexcept {}
void operator delete[] (void * /*unused*/) noexcept {}
void operator delete[] (void * /*unused*/, size_t /*unused*/) noexcept {}
