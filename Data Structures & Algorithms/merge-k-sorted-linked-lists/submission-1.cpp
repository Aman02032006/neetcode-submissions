/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
private:
    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) return ((l1) ? l1 : l2);

        auto tmp1 = l1;
        auto tmp2 = l2;

        if (l1->val > l2->val) return mergeLists(l2, l1);

        while (tmp1 && tmp2) {
            if (tmp1->next) {
                if (tmp1->next->val <= tmp2->val) tmp1 = tmp1->next;
                else {
                    auto tmp = tmp2->next;
                    tmp2->next = tmp1->next;
                    tmp1->next = tmp2;
                    tmp2 = tmp;
                    tmp1 = tmp1->next;
                }
            }
            else {
                tmp1->next = tmp2;
                break;
            }
        }

        return l1;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0) return nullptr;

        for (int i = 1 ; i < k ; i *= 2) {
            for (int j = 0 ; j + i < k ; j += (2 * i)) {
                lists[j] = mergeLists(lists[j], lists[j + i]);
            }
        }

        return lists[0];
    }
};
