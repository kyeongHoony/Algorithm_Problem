#include <cstdio>
#include <vector>

int find(int child, std::vector<int> &parent) {
    int child_use = child;
    while (parent[child_use] != child_use) {
        child_use = parent[child_use];
    }
    int root = child_use;

    int current = child;
    while (parent[child] != root) {
        child = parent[child];
        parent[current] = root;
        current = child;
        
    }
    return root;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    std::vector<int> parent(n + 1, 0);
    for (int i = 0; i < n + 1; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int sign, a, b;
        scanf("%d %d %d", &sign, &a, &b);
        int parent_a = find(a, parent);
        int parent_b = find(b, parent);
        if (sign == 1) {
            if (parent_a == parent_b) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        } else if (sign == 0) {
            if (parent_a == parent_b)
                continue;
            else {
                int new_parent = (parent_a < parent_b) ? parent_a : parent_b;
                parent[parent_a] = new_parent;
                parent[parent_b] = new_parent;
            }
        }
    }
    return 0;
}