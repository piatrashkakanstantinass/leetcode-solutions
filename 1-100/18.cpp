#include <vector>
#include <assert.h>
#include <string>
#include <unordered_set>
#include <limits>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        return kSum(4, sortedNums.begin(), sortedNums.end(), target);
    }

    vector<vector<int>> kSum(size_t k, vector<int>::iterator first, vector<int>::iterator last, long target) {
        if (k == 0) return {};
        if (k == 1) {
            if (find(first, last, target) == last) return {{(int)target}};
            return {};
        }
        if (k == 2) {
            --last;
            vector<vector<int>> combinations;
            while (first < last) {
                int sum = *first + *last;
                if (sum < target) {
                    ++first;
                } else if (sum == target) {
                    combinations.push_back({*first, *last});
                    ++first;
                    while (first < last && *(first - 1) == *first) ++first;
                } else {
                    --last;
                }
            }
            return combinations;
        }
        vector<vector<int>> combinations;
        for (; last - first >= k;) {
            auto newCombinations = kSum(k - 1, first + 1, last, target - *first);
            for (auto combination : newCombinations) {
                combination.insert(combination.begin(), *first);
                combinations.push_back(combination);
            }
            ++first;
            while (last - first >= k && *(first - 1) == *first) ++first;
        }
        return combinations;
    }
};

int main()
{
    auto sol = Solution();
    vector<int> nums {1,0,-1,0,-2,2};
    assert((sol.fourSum(nums, 0) == vector<vector<int>> {{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}}));
}