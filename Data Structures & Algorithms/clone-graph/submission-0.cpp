/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> copy;

        Node* startNode = new Node(node->val);
        copy[node] = startNode;

        queue<Node*> q;
        q.push(node);

        while(!q.empty()) {
            Node* u = q.front();
            q.pop();

            for (auto v : u->neighbors) {
                if (copy.find(v) == copy.end()) {
                    Node* w = new Node(v->val);
                    copy[v] = w;
                    q.push(v);
                }
                copy[u]->neighbors.push_back(copy[v]);
            }
        }

        return startNode;
    }
};
