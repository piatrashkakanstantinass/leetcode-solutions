#include <vector>
#include <assert.h>
#include <string>
#include <unordered_set>
#include <limits>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long r = 0;
        int temp = x;
        while (temp > 0) {
            r *= 10;
            r += temp % 10;
            temp /= 10;
        }
        return r == x;
    }
};

int main()
{
    auto sol = Solution();
    assert(sol.isPalindrome(121));
    assert(!sol.isPalindrome(-121));
    assert(!sol.isPalindrome(10));
}