#include <vector>
#include <assert.h>
#include <string>
#include <unordered_set>
#include <limits>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    bool operator ==(const ListNode &ref) const {
        if (this->val != ref.val || (this->next != ref.next && (this->next == nullptr || ref.next == nullptr))) return false;
        if (this->next == nullptr && ref.next == nullptr) return true;
        return *(this->next) == *ref.next;
    }
    ListNode(vector<int> values) {
        this->val = values[0];
        ListNode *prev = this;
        for (int i = 1; i < values.size(); ++i) {
            auto node = new ListNode(values[i]);
            prev->next = node;
            prev = node;
        }
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;
        auto actualHead = head->next;
        ListNode* prev = nullptr;
        while (head && head->next) {
            auto b = head->next;
            auto c = b->next;
            b->next = head;
            head->next = c;
            if (prev) prev->next = b;
            prev = head;
            head = c;
        }    
        return actualHead;
    }
};

int main()
{
    auto sol = Solution();
    assert((*sol.swapPairs(new ListNode(vector<int>{1, 2, 3, 4})) == ListNode(vector<int>{2, 1, 4, 3})));
}