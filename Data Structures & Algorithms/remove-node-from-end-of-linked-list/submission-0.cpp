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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k = 0;
        ListNode* tmp = head;
        while (tmp) {
            k++;
            tmp = tmp->next;
        }
        if (k == n) return head->next;

        tmp = head;
        int j = 0;
        while (j < k - n - 1 && tmp) {
            j++;
            tmp = tmp->next;
        }

        tmp->next = tmp->next->next;
        return head;
    }
};
