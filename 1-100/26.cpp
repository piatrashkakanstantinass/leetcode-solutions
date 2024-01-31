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
    int removeDuplicates(vector<int>& nums) {
        size_t i = 1, j = 1;
        while (j < nums.size()) {
            if (nums[j] == nums[i - 1]) ++j;
            else nums[i++] = nums[j++];
        }
        return i;
    }
};

int main()
{
    auto sol = Solution();
    auto nums = vector<int>{1, 1, 2};
    assert(sol.removeDuplicates(nums) == 2);
    assert(nums[0] == 1);
    assert(nums[1] == 2);
}