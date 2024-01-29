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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> v = nums;
        sort(v.begin(), v.end());
        vector<vector<int>> res;
        for (size_t i = 0; i < v.size() -2; ++i) {
            if (i > 0 && v[i] == v[i - 1]) continue;
            int l = i + 1;
            int r = v.size() - 1;
            int sum = v[i] + v[l] + v[r];
            while (l < r) {
                if (sum < 0) {
                    sum -= v[l];
                    sum += v[++l];
                } else if (sum > 0) {
                    sum -= v[r];
                    sum += v[--r];
                } else {
                    res.push_back(vector<int>{v[i], v[l], v[r]});
                    sum -= v[l];
                    ++l;
                    while (l < r && v[l] == v[l - 1]) ++l;
                    sum += v[l];
                }
            }
        }
        return res;
    }
};

int main()
{
    auto sol = Solution();
    vector<int> v = {0, 0, 0};
    assert((sol.threeSum(v) == vector<vector<int>> {{0, 0, 0}}));
}