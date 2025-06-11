#include <cstdio>
#include <queue>
#include <vector>

int main() {
    int N;
    scanf("%d", &N);
    std::priority_queue<int, std::vector<int>, std::greater<int>> card;
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        card.push(num);
    }
    int ans = 0;
    while (card.size() >= 2) {
        int first = card.top();
        card.pop();
        int second = card.top();
        card.pop();
        ans += first + second;
        card.push(first + second);
    }
    printf("%d\n", ans);

    return 0;
}