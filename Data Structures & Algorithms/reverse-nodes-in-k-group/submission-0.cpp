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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> list;
        ListNode* tmp = head;

        while (tmp != NULL) {
            list.push_back(tmp);
            tmp = tmp -> next;
        }

        for (int i = k - 1 ; i < list.size() ; i+=k) {
            for (int j = 0 ; j < k - 1 ; j++) list[i - j]->next = list[i - j - 1];
            if (i > k) list[i - (2 * k - 1)]->next = list[i];
        }

        if (list.size() % k) {
            list[k * (list.size() / k) - k]->next = list[k * (list.size() / k)];
        }
        else list[list.size() - k]->next = NULL;

        return list[k - 1];
    }
};
