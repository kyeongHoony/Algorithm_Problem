#include <algorithm>
#include <cstdio>
#include <vector>

#define MAX 2000000001

int merge_sort(int start, int end, std::vector<int> &array) {
    if (start == end) {
        return 0;
    } else {
        int middle = (start + end) / 2;
        merge_sort(start, middle, array);
        merge_sort(middle + 1, end, array);
        int left = start, right = middle + 1;
        std::vector<int> temp;
        while (left <= middle && right <= end) {
            if (array[left] < array[right]) {
                temp.push_back(array[left++]);
            } else
                temp.push_back(array[right++]);
        }
        while (left <= middle) {
            temp.push_back(array[left++]);
        }
        while (right <= end) {
            temp.push_back(array[right++]);
        }
        for (int i = start; i <= end; i++) {
            array[i] = temp[i - start];
        }
    }
    return 0;
}

int binary_search(int target, int start, int end,
                  const std::vector<int> &array) {
    if (start == end) {
        if (array[start] <= target) {
            return start;
        } else {
            return start - 1;
        }
    } else {
        int middle = (start + end) / 2;
        int result;
        if (target <= array[middle]) {
            result = binary_search(target, start, middle, array);
        } else {
            result = binary_search(target, middle + 1, end, array);
        }
        return result;
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    std::vector<int> input(N, 0);
    for (int i = 0; i < N; i++) {
        int a;
        scanf("%d", &a);
        input[i] = a;
    }
    merge_sort(0, N - 1, input);
    int ans = MAX;
    for (int i = N - 1; i >= 0; i--) {
        int target = input[i] - M;
        int index = binary_search(target, 0, i, input);
        if (index >= 0) {
            ans = (ans > target - input[index]) ? target - input[index] : ans;
        }
    }
    printf("%d\n", ans + M);

    return 0;
}