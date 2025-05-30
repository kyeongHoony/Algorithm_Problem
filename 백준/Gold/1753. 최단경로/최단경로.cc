#include <algorithm>
#include <cstdio>
#include <functional>
#include <list>
#include <queue>
#include <vector>

struct comp {
    bool operator()(const std::pair<int, int> &p1,
                    const std::pair<int, int> &p2) const {
        return p1.second > p2.second;
    }
};

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    int K;
    scanf("%d", &K);
    std::vector<std::vector<std::pair<int, int>>> graph(V + 1);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back(std::make_pair(v, w));
    }
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        comp>
        pq;
    pq.push(std::make_pair(K, 0));
    std::vector<int> ans(V + 1, -1);
    int target;
    int dis;
    while (pq.empty() == 0) {
        while (pq.empty() == 0) {
            target = pq.top().first;
            dis = pq.top().second;
            if (ans[target] != -1) {
                pq.pop();
            } else {
                break;
            }
        }
        if (pq.empty()) {
            break;
        }
        pq.pop();
        ans[target] = dis;
        for (std::pair<int, int> &a : graph[target]) {
            if (ans[a.first] == -1) {
                pq.push(std::make_pair(a.first, a.second + dis));
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (ans[i] == -1) {
            printf("INF\n");
        } else {
            printf("%d\n", ans[i]);
        }
    }

    return 0;
}