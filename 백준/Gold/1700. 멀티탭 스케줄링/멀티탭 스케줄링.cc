#include <cstdio>
#include <list>
#include <unordered_map>
#include <vector>

class cache {
  private:
    int size;
    int M;
    int ans;
    int N;
    int flip;
    std::list<int> &input;
    std::vector<int> cache_ele;
    int evict() {
        int target = this->N;
        int prev_flip = this->flip;
        this->flip = (this->flip + 1) % 2;
        for (int &i : input) {
            if (target == 1) {
                break;
            }
            if (cache_ele[i] == prev_flip) {
                cache_ele[i] = flip;
                target--;
            }
        }
        for (int i = 1; i <= M; i++) {
            if (cache_ele[i] == prev_flip) {
                cache_ele[i] = 2;
                break;
            }
        }
        this->size--;
        this->ans++;
        return 0;
    }

    int add(int _element) {
        this->size++;
        cache_ele[_element] = this->flip;
        return 0;
    }

  public:
    cache(int _N, int _M, std::list<int> &_input)
        : N(_N), M(_M), size(0), input(_input), flip(0), cache_ele(_M + 1, 2),
          ans(0) {}

    int check(int _element) {
        if (this->cache_ele[_element] == 2) {
            if (this->size == this->N) {
                this->evict();
            }
            this->add(_element);
        }
        return 0;
    }

    int print() { return this->ans; }
};

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    bool flip = true;
    std::list<int> input;
    for (int i = 0; i < M; i++) {
        int a;
        scanf("%d", &a);
        input.push_back(a);
    }

    cache cache_prac(N, M, input);
    while (input.empty() == 0) {
        int target = input.front();
        input.pop_front();
        cache_prac.check(target);
    }

    printf("%d\n", cache_prac.print());
    return 0;
}