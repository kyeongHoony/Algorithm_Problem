#include <cstdio>
#include <iostream>
#include <vector>

int merge_sort(int start, int end, std::vector<int> &array) {
    if (start == end) {
        return 0;
    } else {
        int middle = (start + end) / 2;
        merge_sort(start, middle, array);
        merge_sort(middle + 1, end, array);
        std::vector<int> temp;
        int left = start, right = middle + 1;
        while (left <= middle && right <= end) {
            if (array[left] < array[right]) {
                temp.push_back(array[left++]);
            } else {
                temp.push_back(array[right++]);
            }
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
        // Boundary check
        // In case when the target is not included in array,
        // we cannot guarantee whether the number is lower than target or not
        if (target >= array[start]) {
            return start;
        } else {
            return start - 1;
        }
    } else {
        int result;
        int middle = (start + end) / 2;
        if (target <= array[middle]) {
            result = binary_search(target, start, middle, array);
        } else {
            result = binary_search(target, middle + 1, end, array);
        }
        return result;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    std::vector<int> array(N, 0);
    for (int i = 0; i < N; i++) {
        int input;
        scanf("%d", &input);
        array[i] = input;
    }

    merge_sort(0, N - 1, array);
    std::vector<int> meet_in_the_middle;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            meet_in_the_middle.push_back(array[i] + array[j]);
            // printf("%d\n", array[i] + array[j]);
        }
    }
    merge_sort(0, meet_in_the_middle.size() - 1, meet_in_the_middle);
    // for (int &i : meet_in_the_middle) {
    //     printf("%d\n", i);
    // }
    int target;
    int ans;
    bool done = false;
    for (int i = N - 1; i >= 0 && !done; i--) {
        for (int j = 0; j < N && !done; j++) {
            target = array[i] - array[j];
            ans = binary_search(target, 0, meet_in_the_middle.size() - 1,
                                meet_in_the_middle);
            if (ans >= 0 && target == meet_in_the_middle[ans]) {
                printf("%d\n", array[i]);
                // printf("%d, %d, %d\n", array[i], array[j], ans);
                done = true;
            }
        }
    }
    return 0;
}
