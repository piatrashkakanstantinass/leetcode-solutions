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
    bool isValid(string s) {
        vector<char> pars;
        unordered_map<char, char> closing;
        closing[')'] = '(';
        closing['}'] = '{';
        closing[']'] = '[';
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                pars.push_back(c);
            } else {
                if (pars.size() == 0 || closing[c] != pars.back()) return false;
                pars.pop_back();
            }
        }
        return pars.size() == 0;
    }
};

int main()
{
    auto sol = Solution();
    assert(sol.isValid("()"));
    assert(!sol.isValid("(]"));
}