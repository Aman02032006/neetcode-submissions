class Node {
public:
    unordered_map<char, Node*> children;
};

class WordDictionary {
    Node* root = new Node();
    Node* end = new Node();
public:
    WordDictionary() {}
    
    void addWord(string word) {
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
    
    bool search(string word, Node* start = nullptr) {
        auto tmp = (start) ? start : root;
        bool exist = false;
        for (int i = 0 ; i < word.size() ; i++) {
            if (word[i] == '.') {
                for (auto p : tmp->children) {
                    exist = exist || search(word.substr(i + 1, word.size() - i - 1), p.second);
                }

                return exist;
            }
            else if (tmp->children.find(word[i]) == tmp->children.end()) return false;
            tmp = tmp->children[word[i]];
        }

        if (tmp->children.find('*') == tmp->children.end()) return false;
        return true;
    }
};
