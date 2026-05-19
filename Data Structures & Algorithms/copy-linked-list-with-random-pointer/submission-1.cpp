/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* tmp1 = head;
        Node* tmp2 = new Node(tmp1->val);

        Node* copyHead = tmp2;

        unordered_map<Node*, Node*> nodeMap;

        while (tmp1) {
            nodeMap[tmp1] = tmp2;

            if (tmp1->next) {
                Node* tmp = new Node(tmp1->next->val);
                tmp2->next = tmp;
                tmp2 = tmp2->next;
            }
            tmp1 = tmp1->next;
        }

        tmp1 = head;
        tmp2 = copyHead;

        while (tmp1 && tmp2) {
            if (tmp1->random) tmp2->random = nodeMap[tmp1->random];
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }

        return copyHead;
    }
};
