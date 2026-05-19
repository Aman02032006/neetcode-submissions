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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0) {
        ListNode* head = new ListNode(0);

        if (l1 && l2) {
            head->val = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            head->next = addTwoNumbers(l1->next, l2->next, carry);
        }
        else if (l2) {
            head->val = (l2->val + carry) % 10;
            carry = (l2->val + carry) / 10;
            head->next = addTwoNumbers(nullptr, l2->next, carry);
        }
        else if (l1) {
            head->val = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;
            head->next = addTwoNumbers(l1->next, nullptr, carry);
        }
        else if (carry) {
            head->val = carry;
        }
        else head = nullptr;

        return head;
    }
};
