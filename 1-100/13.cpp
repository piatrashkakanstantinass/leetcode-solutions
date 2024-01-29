#include <vector>
#include <assert.h>
#include <string>
#include <unordered_set>
#include <limits>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<pair<int, string>> values = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}};
    int romanToInt(string s)
    {
        int res = 0;
        auto sit = s.begin();
        auto it = values.begin();
        while (sit != s.end()) {
            while (equal(it->second.begin(), it->second.end(), sit)) {
                res += it->first;
                sit += it->second.size();
            }
            ++it;
        }
        return res;
    }
};

int main()
{
    auto sol = Solution();
    assert(sol.romanToInt("III") == 3);
}