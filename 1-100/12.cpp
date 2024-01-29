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
    string intToRoman(int num)
    {
        string res;
        auto it = values.begin();
        while (num > 0)
        {
            while (it->first > num) ++it;
            res += it->second;
            num -= it->first;
        }
        return res;
    }
};

int main()
{
    auto sol = Solution();
    assert(sol.intToRoman(3) == "III");
}