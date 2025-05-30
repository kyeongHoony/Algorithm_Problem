#include <algorithm>
#include <cstdio>
#include <vector>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    std::vector<std::pair<int, int>> stuff;
    stuff.push_back(std::make_pair(0, 0));
    for (int i = 0; i < N; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        stuff.push_back(std::make_pair(a, b));
    }
    std::vector<std::vector<int>> bag(K + 1, std::vector<int>(N + 1, 0));
    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= N; j++) {
            int weight = stuff[j].first, value = stuff[j].second;
            if (i - weight >= 0) {
                bag[i][j] =
                    std::max(bag[i][j - 1], bag[i - weight][j - 1] + value);
            } else {
                bag[i][j] = bag[i][j - 1];
            }
        }
    }

    // for (int i = 0; i <= K; i++) {
    //     for (int j = 0; j <= N; j++) {
    //         printf("%d ", bag[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("%d\n", bag[K][N]);

    return 0;
}