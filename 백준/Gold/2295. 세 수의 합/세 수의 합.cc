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
    bool done = false;
    int first, second, third, target;
    for (int i = N - 1; i >= 0 && !done; i--) {
        target = array[i];
        third = binary_search(target, 0, i - 1, array);
        for (; third >= 0 && !done; third--) {
            int target_third = target - array[third];
            second = binary_search(target_third, 0, third, array);
            for (; second >= 0 && !done; second--) {
                int target_second = target_third - array[second];
                first = binary_search(target_second, 0, second, array);
                if (array[first] == target_second) {
                    done = true;
                    std::cout << target << std::endl;
                }
            }
        }
    }
    return 0;
}