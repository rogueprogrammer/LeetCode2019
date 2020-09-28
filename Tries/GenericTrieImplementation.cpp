class TrieNode {
public:
    char cur;
    bool endWord;
    vector<TrieNode*> children;
    TrieNode(char c, bool e = false) {
        cur = c;
        children.resize(26);
        endWord = e;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('$');
    }
    void addWord(string word) {
        TrieNode* n = root;
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i];
            int pos = tolower(c) - 'a';
            if (!n->children[pos]) {
                n->children[pos] = new TrieNode(c);
                if (i == word.size() - 1) {
                    n->children[pos]->endWord = true;
                }
            }
            n = n->children[pos];
        }
    }
    bool search(string word) {
        TrieNode* n = root;
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i];
            int pos = tolower(c) - 'a';
            if (!n->children[pos]) {
                return false;
            }
            n = n->children[pos];
        }
        return true;
    }

};
