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
    ListNode* reverse(ListNode* head) {
        if (!head->next) return head;
        ListNode* tmp1 = head;
        ListNode* tmp2 = head->next;
        head->next = NULL;
        while (tmp2) {
            ListNode* tmp = tmp2 -> next;
            tmp2 -> next = tmp1;
            tmp1 = tmp2;
            tmp2 = tmp;
        }

        return tmp1;
    }
    void reorderList(ListNode* head) {

        if (!head->next || !head->next->next) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* tmp1 = head;
        ListNode* tmp2 = reverse(slow->next);
        slow->next = NULL;

        ListNode* tmp = NULL;
        int state = 0;
        while(true) {
            if (state == 0) {
                if (!tmp2) break;
                tmp = tmp1->next;
                tmp1->next = tmp2;
                tmp1 = tmp;
                state = 1;
            }
            else {
                if (!tmp1) break;
                tmp = tmp2->next;
                tmp2->next = tmp1;
                tmp2 = tmp;
                state = 0;
            }
        }
    }
};
