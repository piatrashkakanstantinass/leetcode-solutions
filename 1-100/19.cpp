#include <vector>
#include <assert.h>
#include <string>
#include <unordered_set>
#include <limits>
#include <iostream>
#include <algorithm>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        size_t length = 1;
        auto temp = head;
        while (temp->next) {
            ++length;
            temp = temp->next;
        }
        size_t offset = length - n;
        temp = head;
        if (offset == 0) return head->next;
        while (offset > 1) {
            temp = temp->next;
            --offset;
        }
        temp->next = temp->next->next;
        return head;
    }
};

int main()
{
    auto sol = Solution();
    auto l1 = ListNode(vector<int>{1, 2, 3, 4, 5});
    auto l2 = ListNode(vector<int>{1, 2, 3, 5});
    assert(*sol.removeNthFromEnd(&l1, 2) == l2);
}