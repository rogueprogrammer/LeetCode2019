#include "Header.h"
//https://leetcode.com/problems/word-search-ii/
//incomplete (too long for an hour interview), but general idea is to create a trie using input words, and do a DFS on the trie each time a letter is encountered

class TrieNode {
public:
    char c;
    vector<TrieNode*> children;
    bool end;
    TrieNode(char cur, bool e = false) {
        c = cur;
        children.resize(26);
        end = e;
    }

};

class Trie {
public:
    TrieNode* root; //always points to root of trie
    
    TrieNode* getRoot() {
        return root;
    }
    
    Trie() {
        root = new TrieNode('$');
    }
    void addWord(string word) {
        TrieNode* n = root;
        dfsAdd(n, word, 0);
    }
    
    void dfsAdd(TrieNode* n, string word, int i) {
        int childIndex = word[i] - 'a';

        if (n->children[childIndex] != NULL) {
            n = n->children[childIndex];
        }
        else {
            n->children[childIndex] = new TrieNode(word[i]);
        }
        if (i == word.size() - 1) { //base case
            n->children[childIndex]->end = true;
            return;
        }
        else {
            n = n->children[childIndex];
            dfsAdd(n, word, i + 1);
        }
    }

};


bool isSafe(vector<vector<char>>& board, int row, int col) {
    int numRows = board.size();
    int numCols = board[0].size();

    if ((row >= 0 && row < numRows) && (col >= 0 && col < numCols)) {
        return true;
    }
    return false;
}

void searchTrie(vector<vector<char>>& board, TrieNode* root, string word, int row, int col, bool& found) {
    if (root == NULL) {
        return;
    }
    if (root->end == true) {
        found = true;
        return;
    }

    char cur = board[row][col];
    word += cur; 
    if (root->children[cur - 'a'] != NULL) {
        char next;
        // search up
        if (isSafe(board, row - 1, col)) {
            next = board[row - 1][col];
            if (root->children[next - 'a'] != NULL) {
                root = root->children[next - 'a'];
                searchTrie(board, root->children[next - 'a'], word, row-1, col, found);
            }
        }

        // down
        if (isSafe(board, row + 1, col)) {
            next = board[row + 1][col];
            if (root->children[next - 'a'] != NULL) {
                root = root->children[next - 'a'];
                searchTrie(board, root->children[next - 'a'], word, row + 1, col, found);
            }
        }
        // left
        if (isSafe(board, row, col-1)) {
            next = board[row][col-1];
            if (root->children[next - 'a'] != NULL) {
                root = root->children[next - 'a'];
                searchTrie(board, root->children[next - 'a'], word, row, col-1, found);
            }
        }
        // right
        if (isSafe(board, row, col + 1)) {
            next = board[row][col + 1];
            if (root->children[next - 'a'] != NULL) {
                root = root->children[next - 'a'];
                searchTrie(board, root->children[next - 'a'], word, row, col + 1, found);
            }
        }

    }
    
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> res;
    //build prefix tree (trie) out of input param words
    Trie* trie = new Trie();
    for (int i = 0; i < words.size(); ++i) {
        trie->addWord(words[i]);
    }
    
    //search each of the cells using trie
    int numRows = board.size();
    int numCols = board[0].size();
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            char cur = board[i][j];
            if (trie->root->children[cur - 'a'] != NULL) {
                string word = "";
                TrieNode* root = trie->getRoot();
                bool found;
                searchTrie(board, root, word, i, j, found);
                if (found) {
                    res.push_back(word);
                }
            }
        }
    }
    return res;
}



void main() {
    vector<string> words = { "oath", "pea", "eat", "rain" };
    //findWords(words);
	system("PAUSE");
}
