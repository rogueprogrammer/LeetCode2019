#include "Header.h"

bool oneCharDiff(string str1, string str2) {

    int numDifs = 0;
    for (int i = 0; i < str1.size(); ++i) {
        if (str1[i] != str2[i]) {
            ++numDifs;
        }
    }
    return numDifs == 1;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

    set<string> s(wordList.begin(), wordList.end());

    auto it = s.find(endWord);
    if (it == s.end()) {
        return 0;
    }

    map<string, int> visited; //word, distance

    //use bfs to find shortest path. a path can only be formed between words if 
    queue<string> q;
    q.push(beginWord);
    visited[beginWord] = 0;
    int level = 1;
    while (!q.empty()) {
        string curWord = q.front(); //hit
        if (curWord == endWord) {
            return visited[curWord];
        }
        for (string word : wordList) { //hot
            if (oneCharDiff(curWord, word)) {
                auto it = visited.find(word);
                if (it == visited.end()) {
                    q.push(word);
                    visited[word] = level;
                }
            }
        }
        ++level;
        q.pop();
    }
    return 0;
}


void main() {
    
    vector<string> wordList = { "hot","dot","dog","lot","log","cog" };
    string s = "hit";
    string e = "cog";
    cout << ladderLength(s, e, wordList) << endl;

	system("PAUSE");
}
