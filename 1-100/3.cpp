#include <vector>
#include <assert.h>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_map<char, int> seen;
        int start = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto it = seen.find(s[i]);
            if (it != seen.end() && it->second >= start) {
                res = max(res, i - start);
                start = it->second + 1;
            }
            seen[s[i]] = i;
        }
        res = max(res, (int)s.size() - start);
        return res;
    }
};

int main()
{
    auto sol = Solution();
    assert(sol.lengthOfLongestSubstring("abcabcbb") == 3);
}