//https://leetcode.com/problems/implement-trie-prefix-tree/submissions/
struct TrieNode {
    char cur;
    vector<TrieNode*> children;
    bool isEnd;
    TrieNode(char curChar) {
        cur = curChar;
        isEnd = false;
        vector<TrieNode*> _children(26);
        children = _children;
    }
};

class Trie {
public:
    TrieNode* root;

    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode(' ');
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* n = root;
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i];
            int posn = tolower(c) - 'a';
            if (n->children[posn] != NULL) {
                n = n->children[posn];
            }
            else {
                n->children[posn] = new TrieNode(c);
                n = n->children[posn];
            }
            if (i == word.size() - 1) {
                n->isEnd = true;
            }
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* n = root;
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i];
            int posn = tolower(c) - 'a';
            if (!n->children[posn]) {
                return false;
            }
            n = n->children[posn];
        }
        return n->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* n = root;
        for (int i = 0; i < prefix.size(); ++i) {
            char c = prefix[i];
            int posn = tolower(c) - 'a';
            if (!n->children[posn]) {
                return false;
            }
            n = n->children[posn];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
