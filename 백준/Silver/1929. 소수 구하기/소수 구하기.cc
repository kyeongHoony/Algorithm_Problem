#include <cstdio>
#include <vector>

#define MAX 1000001
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    std::vector<int> prime(MAX, 1);
    prime[1] = 0;
    
    for (int i = 2; i <= MAX - 1; i++) {
        if (prime[i] == 1) {
            for (int j = i * 2; j <= MAX - 1; j += i) {
                prime[j] = 0;
            }
        }
    }

    for (int i = N; i <= M; i++) {
        if (prime[i] == 1) {
            printf("%d\n", i);
        }
    }

    return 0;
}