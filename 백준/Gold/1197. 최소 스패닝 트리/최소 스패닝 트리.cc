#include <algorithm>
#include <cstdio>
#include <list>
#include <queue>
#include <vector>
#define MAX 1000001

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    std::vector<std::priority_queue<std::pair<int, int>,
                                    std::vector<std::pair<int, int>>,
                                    std::greater<std::pair<int, int>>>>
        graph(V + 1);
    for (int i = 0; i < E; i++) {
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);
        graph[A].emplace(std::make_pair(C, B));
        graph[B].emplace(std::make_pair(C, A));
    }
    std::vector<int> check(V + 1);
    check[1] = 1;
    int num = 0;
    int ans = 0;
    std::list<int> temp;
    temp.push_back(1);
    while (num < V - 1) {
        int min = MAX, end;

        for (int &a : temp) {
            if (check[a] == 1) {
                while (graph[a].empty() == 0 &&
                       check[graph[a].top().second] == 1) {
                    graph[a].pop();
                }
                if (graph[a].empty() == 0 && graph[a].top().first < min) {
                    min = graph[a].top().first;
                    end = graph[a].top().second;
                }
            }
        }
        num++;
        ans += min;
        check[end] = 1;
        temp.push_back(end);
    }
    printf("%d\n", ans);
    return 0;
}