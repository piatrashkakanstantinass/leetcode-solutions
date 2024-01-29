#include <vector>
#include <assert.h>
#include <string>
#include <unordered_set>
#include <limits>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];
        auto p = longestCommonPrefix(strs[0], strs[1]);
        for (size_t i = 2; i < strs.size(); ++i) {
            p = longestCommonPrefix(p, strs[i]);
        }
        return p;
    }

    string longestCommonPrefix(string s1, string s2) {
        auto i = s1.begin();
        auto j = s2.begin();
        while (i != s1.end() && j != s2.end() && *i == *j) {
            ++i;
            ++j;
        }
        return string(s1.begin(), i);
    }
};

int main()
{
    auto sol = Solution();
    vector<string> v = {"flower", "flow", "flight"};
    assert(sol.longestCommonPrefix(v) == "fl");
}