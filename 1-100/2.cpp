#include <vector>
#include <assert.h>
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

    class Solution
    {
    public:
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
        {
            ListNode* start = nullptr;
            ListNode* prev = nullptr;
            int temp = 0;
            while (l1 || l2 || temp > 0) {
                auto sum = this->getValue(l1) + this->getValue(l2) + temp;
                temp = sum > 9 ? 1 : 0;
                auto node = new ListNode(sum % 10);
                if (prev == nullptr) {
                    start = node;
                } else {
                    prev->next = node;
                }
                prev = node;
                l1 = this->next(l1);
                l2 = this->next(l2);
            }
            return start;
        }

        int getValue(ListNode *n) {
            if (n == nullptr) return 0;
            return n->val;
        }

        ListNode* next(ListNode *n) {
            if (n == nullptr) return nullptr;
            return n->next;
        }
    };

int main()
{
    auto sol = Solution();
    auto l1 = ListNode(vector<int>{2, 4, 3});
    auto l2 = ListNode(vector<int>{5, 6, 4});
    assert((*sol.addTwoNumbers(&l1, &l2) == ListNode(vector<int>{7, 0, 8})));
    auto l3 = ListNode(0);
    assert((*sol.addTwoNumbers(&l3, &l3) == ListNode(0)));
}