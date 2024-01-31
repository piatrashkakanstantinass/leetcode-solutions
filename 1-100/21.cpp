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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = new ListNode();
        auto currNode = head;
        while (list1 || list2) {
            int val;
            if (list1 == nullptr) {
                val = list2->val;
                list2 = list2->next;
            } else if (list2 == nullptr) {
                val = list1->val;
                list1 = list1->next;
            } else {
                val = min(list1->val, list2->val);
                if (val == list1->val) {
                    list1 = list1->next;
                } else {
                    list2 = list2->next;
                }
            }
            auto node = new ListNode(val);
            currNode->next = node;
            currNode = node;
        }
        return head->next;
    }
};

int main()
{
    auto sol = Solution();
    ListNode list1(vector<int>{1, 2, 4});
    ListNode list2(vector<int>{1, 3, 4});
    assert((*sol.mergeTwoLists(&list1, &list2) == ListNode(vector<int>{1, 1, 2, 3, 4, 4})));
}