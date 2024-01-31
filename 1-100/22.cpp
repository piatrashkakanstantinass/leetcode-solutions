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
    vector<string> generateParenthesis(int n) {
        vector<string> combinations;
        permutateParanthesis(combinations, "", n, 0);
        return combinations;
    }

    void permutateParanthesis(vector<string>& combinations, string currCombination, int openingLeft, int closedLeft) {
        if (openingLeft == 0 && closedLeft == 0) {
            combinations.push_back(currCombination);
        }
        if (openingLeft > 0) {
            permutateParanthesis(combinations, currCombination + "(", openingLeft - 1, closedLeft + 1);
        }
        if (closedLeft > 0) {
            permutateParanthesis(combinations, currCombination + ")", openingLeft, closedLeft - 1);
        }
    }
};

int main()
{
    auto sol = Solution();
    assert((sol.generateParenthesis(3) == vector<string>{"((()))","(()())","(())()","()(())","()()()"}));
}