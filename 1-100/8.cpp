#include <vector>
#include <assert.h>
#include <string>
#include <unordered_set>
#include <limits>
#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int v = 0;
        bool neg = false;
        auto it = s.begin();
        for (; it < s.end() && *it == ' '; ++it) ;
        switch (*it) {
            case '-':
                neg = true;
            case '+':
                ++it;
        }
        for (; it < s.end(); ++it) {
            if (*it < '0' || *it > '9') break;
            int digit = (int)*it - '0';
            try {
                v = addOverflow(mulOverflow(v, 10), digit);
            } catch (const overflow_error& e) {
                return neg ? INT_MIN : INT_MAX;
            }
            
        }
        return v * (neg ? -1 : 1);
    }

    int addOverflow(int a, int b) {
        if (INT_MAX - a < b) {
            throw overflow_error("Addition overflow");
        }
        return a + b;
    }

    int mulOverflow(int a, int b) {
        if (a != 0 && INT_MAX / a < b) {
            throw overflow_error("Multiplication overflow");
        }
        return a * b;
    }
};

int main()
{
    auto sol = Solution();
    assert(sol.myAtoi("42") == 42);
}