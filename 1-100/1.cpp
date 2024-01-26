#include <vector>
#include <assert.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        for (int i = 0; i < nums.size(); ++i) {
            int required_num = target - nums[i];
            if (hashmap.count(required_num)) {
                return vector<int> {hashmap[required_num], i};
            }
            hashmap[nums[i]] = i;
        }
        return nums;
    }
};

int main() {
    auto v1 = vector<int> {2, 7, 11, 15};
    auto v2 = vector<int> {3, 2, 4};
    auto v3 = vector<int> {3, 3};
    auto sol = Solution();
    assert((sol.twoSum(v1, 9) == vector<int>{0, 1}));
    assert((sol.twoSum(v2, 6) == vector<int>{1, 2}));
    assert((sol.twoSum(v3, 6) == vector<int>{0, 1}));
}