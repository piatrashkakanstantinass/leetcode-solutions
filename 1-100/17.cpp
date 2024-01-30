#include <vector>
#include <assert.h>
#include <string>
#include <unordered_set>
#include <limits>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> letters = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return {};
        vector<string> combinations = {""};
        for (char digit : digits)
        {
            vector<string> tempCombinations;
            for (string combination : combinations)
            {
                int i = digit - '2';
                for (char letter : letters[i])
                {
                    tempCombinations.push_back(combination + letter);
                }
            }
            combinations = tempCombinations;
        }
        return combinations;
    }
};

int main()
{
    auto sol = Solution();
    assert((sol.letterCombinations("23") == vector<string>{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}));
    assert((sol.letterCombinations("") == vector<string>{}));
    assert((sol.letterCombinations("2") == vector<string>{"a", "b", "c"}));
}