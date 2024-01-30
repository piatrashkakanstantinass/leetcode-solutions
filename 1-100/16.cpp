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
    int threeSumClosest(vector<int>& nums, int target) {
        vector<int> v = nums;
        sort(v.begin(), v.end());
        int bestSum = v[0] + v[1] + v[2];
        for (size_t i = 0; i < v.size() - 2; ++i) {
            size_t j = i + 1, k = v.size() - 1;
            while (j < k) {
                int sum = v[i] + v[j] + v[k];
                if (abs(sum - target) < (abs(bestSum - target))) bestSum = sum;
                if (sum < target) {
                    ++j;
                } else if (sum == target) {
                    return target;
                } else {
                    --k;
                }
            }
        }
        return bestSum;
    }
};

int main()
{
    auto sol = Solution();
    vector<int> nums1 = {-1,2,1,-4};
    vector<int> nums2 = {0, 0, 0};
    assert(sol.threeSumClosest(nums1, 1) == 2);
    assert(sol.threeSumClosest(nums2, 1) == 0);
}