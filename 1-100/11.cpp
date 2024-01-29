#include <vector>
#include <assert.h>
#include <string>
#include <unordered_set>
#include <limits>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        auto l = height.begin();
        auto r = --height.end();
        int bestArea = 0;
        while (l < r) {
            bestArea = max(bestArea, (int)(r - l) * min(*l, *r));
            if (*l <= *r) ++l;
            else --r;
        }
        return bestArea;
    }
};

int main()
{
    auto sol = Solution();
    vector<int> v = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    assert(sol.maxArea(v) == 49);
}