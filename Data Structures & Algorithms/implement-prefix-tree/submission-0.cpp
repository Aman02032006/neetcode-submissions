class Node {
public:
    unordered_map<char, Node*> children;
};

class PrefixTree {
    Node* root = new Node();
    Node* end = new Node();
public:
    PrefixTree() {
    }
    
    void insert(string word) {
        auto tmp = root;
        for (char ch : word) {
            if (tmp->children.find(ch) == tmp->children.end()) {
                Node* tmp2 = new Node();
                tmp->children[ch] = tmp2;
            }
            tmp = tmp->children[ch];
        }
        tmp->children['*'] = end;
    }
    
    bool search(string word) {
        auto tmp = root;
        for (char ch : word) {
            if (tmp->children.find(ch) == tmp->children.end()) return false;
            tmp = tmp->children[ch];
        }

        if (tmp->children.find('*') == tmp->children.end()) return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        auto tmp = root;
        for (char ch : prefix) {
            if (tmp->children.find(ch) == tmp->children.end()) return false;
            tmp = tmp->children[ch];
        }

        return true;
    }
};
