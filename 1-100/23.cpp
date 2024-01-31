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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comparator = [](ListNode a, ListNode b) {
            return a.val > b.val;
        };
        priority_queue<ListNode, vector<ListNode>, decltype(comparator)> q(comparator);
        for (auto head : lists) {
            if (head != nullptr) q.push(*head);
        }
        auto dummy = new ListNode();
        auto tail = dummy;
        while (!q.empty()) {
            auto node = q.top();
            q.pop();
            tail->next = new ListNode(node.val);
            tail = tail->next;
            if (node.next != nullptr) q.push(*(node.next));
        }
        return dummy->next;
    }
};

int main()
{
    auto sol = Solution();
    auto l1 = new ListNode(vector<int>{1, 4, 5});
    auto l2 = new ListNode(vector<int>{1, 3, 4});
    auto l3 = new ListNode(vector<int>{2, 6});
    auto lists = vector<ListNode*>{l1, l2, l3};
    assert((*sol.mergeKLists(lists) == ListNode(vector<int>{1,1,2,3,4,4,5,6})));
}